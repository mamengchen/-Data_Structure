#include "packet.h"
#include "network_buffer.h"

#include <iostream>
#include <cstdlib>
#include <cstring>

NetworkBuffer::NetworkBuffer(const unsigned int size) {
    _bufferSize = size;
    _beginIndex = 0;
    _endIndex = 0;
    _dataSize = 0;
    _buffer = new char[_bufferSize];
}

NetworkBuffer::~NetworkBuffer() {
    if (_buffer != nullptr) {
        delete[] _buffer;
        _buffer = nullptr;
    }
}

bool NetworkBuffer::HasData() const {
    if (_dataSize <= 0) {
        return false;
    }

    // 至少要有一个协议头
    if (_dataSize < sizeof(PacketHeader)) {
        return false;
    }

    return true;
}

unsigned int NetworkBuffer::GetEmptySize() {
    return _bufferSize - _dataSize;
}

unsigned int NetworkBuffer::GetWriteSize() const {
    if (_beginIndex <= _endIndex) {
        return _bufferSize - _endIndex;
    }
    else
    {
        return _beginIndex - _endIndex;
    }
}

unsigned int NetworkBuffer::GetReadSize() const {
    if (_dataSize <= 0) {
        return 0;
    }

    if (_beginIndex <= _endIndex) {
        return _endIndex - _beginIndex;
    }
    else {
        return _bufferSize - _beginIndex;
    }
}

void NetworkBuffer::FillData(unsigned int size) {
    _dataSize += size;

    // 移动到头部
    if ((_bufferSize - _endIndex) < size) {
        size -= _bufferSize - _endIndex;
        _endIndex = 0;
    }

    _endIndex += size;
}

void NetworkBuffer::RemoveData(unsigned int size) {
    _dataSize -= size;

    if ((_beginIndex + size) >= _bufferSize) {
        size -= _bufferSize - _beginIndex;
        _beginIndex = 0;
    }

    _beginIndex += size;
}

void NetworkBuffer::ReAllocBuffer() {
    Buffer::ReAllocBuffer(_dataSize);
}


/// 可读buffer
RecvNetworkBuffer::RecvNetworkBuffer(const unsigned int _size) : NetworkBuffer(_size) {}

void RecvNetworkBuffer::Dispose() {}

int RecvNetworkBuffer::GetBuffer(char*& pBuffer) const {
    pBuffer = _buffer + _beginIndex;
    return GetReadSize();
}

Packet* RecvNetworkBuffer::GetPacket() {
    // 数据长度不够
    if (_dataSize < sizeof(TotalSizeType)) {
        return nullptr;
    }

    // 1.读出 整体长度
    unsigned short totalSize;
    MemcpyFromBuffer(reinterpret_cast<char*>(&totalSize), sizeof(TotalSizeType));

    // 协议体长度不够，等待
    if (_dataSize < totalSize) {
        return nullptr;
    }

    RemoveData(sizeof(TotalSizeType));

    // 2.读出协议体
    PacketHeader head;
    MemcpyFromBuffer(reinterpret_cast<char*>(&head), sizeof(PacketHeader));
    RemoveData(sizeof(PacketHeader));

    // 3.读出协议体数据
    Packet* pPacket = new Packet(head.MsgId);
    const auto dataLength = totalSize - sizeof(PacketHeader) - sizeof(TotalSizeType);
    while (pPacket->GetTotalSize() < dataLength) {
        pPacket->ReAllocBuffer();
    }

    MemcpyFromBuffer(pPacket->GetBuffer(), dataLength);
    pPacket->FillData(dataLength);
    RemoveData(dataLength);

    return pPacket;
}

void RecvNetworkBuffer::MemcpyFromBuffer(char* pVoid, const unsigned int size)
{
    const auto readSize = GetReadSize();
    if (readSize < size) {
        // 1.copy 尾部数据
        ::memcpy(pVoid, _buffer + _beginIndex, readSize);

        // 2.copy 头部数据
        ::memcpy(pVoid + readSize, _buffer, size - readSize);
    }
    else {
        ::memcpy(pVoid, _buffer + _beginIndex, size);
    }
}



//// 发送数据包buf

SendNetworkBuffer::SendNetworkBuffer(const unsigned int size) : NetworkBuffer(size) {}

void SendNetworkBuffer::Dispose() {}

int SendNetworkBuffer::GetBuffer(char*& pBuffer) const {
    if (_dataSize <= 0) {
        pBuffer = nullptr;
        return 0;
    }

    if (_beginIndex < _endIndex) {
        pBuffer = _buffer + _beginIndex;
        return _endIndex - _beginIndex;
    }
    else {
        pBuffer = _buffer + _beginIndex;
        return _bufferSize - _beginIndex;
    }
}

void SendNetworkBuffer::AddPacket(Packet* pPacket) {
    const auto dataLength = pPacket->GetDataLength();
    TotalSizeType totalSize = dataLength + sizeof(PacketHeader) + sizeof(TotalSizeType);

    // 长度不够，扩容
    while (GetEmptySize() < totalSize) {
        ReAllocBuffer();
    }

    // 打印发送长度
    std::cout << "send buffer::Realloc. _bufferSize:" << _bufferSize << std::endl;

    // 1.写入整体长度
    MemcpyToBuffer(reinterpret_cast<char*>(&totalSize), sizeof(TotalSizeType));

    // 2.写入协议头
    PacketHeader head;
    head.MsgId = pPacket->GetMsgId();
    MemcpyToBuffer(reinterpret_cast<char*>(&head), sizeof(PacketHeader));

    // 3.数据
    MemcpyToBuffer(pPacket->GetBuffer(), pPacket->GetDataLength());
}

void SendNetworkBuffer::MemcpyToBuffer(char* pVoid, const unsigned int size) {
    const auto writeSize = GetWriteSize();
    if (writeSize < size) {
        // 1.copy 尾部数据
        ::memcpy(_buffer + _endIndex, pVoid, writeSize);

        // 2.copy 头部数据
        ::memcpy(_buffer, pVoid + writeSize, size - writeSize);
    }
    else {
        ::memcpy(_buffer + _endIndex, pVoid, size);
    }

    FillData(size);
}
