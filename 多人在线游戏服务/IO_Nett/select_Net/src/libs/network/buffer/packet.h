#pragma once

#include "base_buffer.h"

#pragma pack(push)
#pragma pack(4)

struct PacketHeader {
    unsigned short MsgId;
};

#pragma pack(pop)

#define DEFAULT_PACKET_BUFFER_SIZE 1024 * 10

class Packet : public Buffer {
public:
    Packet();
    Packet(const int msgId);
    ~Packet();

    void Dispose() override;
    void CleanBuffer();

    char* GetBuffer() const;
    void AddBuffer(const char* pBuffer, const unsigned int size);
    unsigned short GetDataLength() const;
    int GetMsgId() const;
    void FillData(unsigned int size);
    void ReAllocBuffer();
private:
    int _msgId;
};