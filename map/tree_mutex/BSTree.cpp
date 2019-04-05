//����������
//�����������ֳƶ�������������������һ�ſ����������Ǿ����������ʵĶ�������
//��������������Ϊ�գ��������������нڵ��ֵ��С�ڸ��ڵ��ֵ
//��������������Ϊ�գ��������������нڵ��ֵ�����ڸ��ڵ��ֵ
//������ҵ����Ҳ�ֱ�Ϊ����������

//���룺
//a.��Ϊ�գ���ֱ�Ӳ���
//b.�����գ����������������ʲ��Ҳ���λ�ã������½ڵ�
//ɾ����
//a.Ҫɾ���Ľ���޺��ӽ��
//b.Ҫɾ���Ľ��ֻ�����ӽ��
//c.Ҫɾ���Ľ��ֻ���Һ��ӽ��
//d.Ҫɾ���Ľ�������Һ��ӽ��
//�������д�ɾ���ڵ���4�������ʵ�����a���������b����c�ϲ�������
//	1.ɾ���ý����ʹ��ɾ���ڵ��˫�׽��ָ��ɾ���ڵ�����ӽ��
//	2.ɾ���ý����ʹ��ɾ���ڵ��˫�׽��ָ��ɾ�������Һ��ӽ��
//	3.��������������Ѱ�������µĵ�һ�����(�ؼ�����С)��������ֵ�����ɾ���ڵ��У� ��������ý���ɾ������

#include <iostream>
#include <assert.h>
using namespace std;

namespace mmc {
	template<class T>
	struct BSTNode
	{
		BSTNode(const T& data = T())
			:_pLeft(nullptr)
			, _pRight(nullptr)
			, _data(data)
		{}

		BSTNode<T>* _pLeft;
		BSTNode<T>* _pRight;
		T _data;
	};

	template<class T>
	class BSTree
	{
		typedef BSTNode<T> Node;
		typedef Node* PNode;

	public:
		BSTree()
			:_pRoot(nullptr)
		{}

		~BSTree()
		{
			_Destroy(_pRoot);
		}

		bool Find(const T& data)
		{
			PNode pCur = _pRoot;
			while (pCur)
			{
				if (data == pCur->_data)
				{
					return true;
				}
				else if (data < pCur->_data) {
					pCur = pCur->_pLeft;
				}
				else {
					pCur = pCur->_pRight;
				}
			}
			return false;
		}

		bool Insert(const T& data)
		{
			//�����Ϊ�գ�ֱ�Ӳ���
			if (nullptr == _pRoot)
			{
				_pRoot = new Node(data);
				return true;
			}

			//���ն����������������ʲ���data�����еĲ���λ��
			PNode pCur = _pRoot;
			//��¼pCur��˫�ף���Ϊ��Ԫ�����ղ�����pCur˫�����Һ��ӵ�λ��
			PNode pParent = nullptr;
			while (pCur)
			{
				pParent = pCur;
				if (data < pCur->_data)
				{
					pCur = pCur->_pLeft;
				}
				else if (data > pCur->_data)
				{
					pCur = pCur->_pRight;
				}
				else
				{
					return false;
				}
			}
			//����Ԫ�أ�
			pCur = new Node(data);
			if (data < pParent->_data)
			{
				pParent->_pLeft = pCur;
			}
			else
			{
				pParent->_pRight = pCur;
			}
			return true;
		}

		bool Erase(const T& data)
		{
			//�����Ϊ�գ�ɾ��ʧ��
			if (nullptr == _pRoot)
				return false;

			//������data�����е�λ��
			PNode pCur = _pRoot;
			PNode pParent = nullptr;
			while (pCur)
			{
				if (data == pCur->_data)
					break;
				else if (data < pCur->_data)
				{
					pParent = pCur;
					pCur = pCur->_pLeft;
				}
				else {
					pParent = pCur;
					pCur = pCur->_pRight;
				}
			}

			//data���ڶ����������У��޷�ɾ��
			if (nullptr == pCur)
				return false;
			if (nullptr == pCur->_pRight)
			{
				//�Һ���Ϊ��
				if (pParent->_pLeft == pCur)
				{
					pParent->_pLeft = pCur->_pLeft;
					delete pCur;
					return true;
				}
				else {
					pParent->_pRight = pCur->_pLeft;
					delete pCur;
					return true;
				}
			}
			else if (nullptr == pCur->_pLeft)
			{
				//����Ϊ��
				if (pParent->_pLeft == pCur)
				{
					pParent->_pLeft = pCur->_pRight;
					delete pCur;
					return true;
				}
				else {
					pParent->_pRight = pCur->_pRight;
					delete pCur;
					return true;
				}
			}
			else
			{
				//��������������ʱ��������Ҫ�ҵ����������ģ���������С��
				//�������ҵ�����������С�ģ�
				PNode Parent_find_node = pCur;
				PNode Find_max_node = pCur->_pLeft;
				bool signal = false;
				while (Find_max_node->_pRight != nullptr)
				{
					Parent_find_node = Find_max_node;
					Find_max_node = Find_max_node->_pRight;
					signal = true;
				}

				if (signal)
				{
					//���ﲻ���ж�������һ��û���Һ��ӣ��������Ӻ�û������һ������
					Parent_find_node->_pRight = Find_max_node->_pLeft;
				}

				if (pParent->_pLeft == pCur)
				{
					pParent->_pLeft = Find_max_node;
					Find_max_node->_pLeft = pCur->_pLeft;
					Find_max_node->_pRight = pCur->_pRight;
					delete pCur;
					return true;
				}
				else if (pParent->_pRight == pCur)
				{
					pParent->_pRight = Find_max_node;
					Find_max_node->_pLeft = pCur->_pLeft;
					Find_max_node->_pRight = pCur->_pRight;
					delete pCur;
					return true;
				}
			}
		}

		void InOrder()
		{
			_InOrder(_pRoot);
		}

	private:
		void _InOrder(PNode pRoot)
		{
			if (pRoot)
			{
				_InOrder(pRoot->_pLeft);
				cout << pRoot->_data << " ";
				_InOrder(pRoot->_pRight);
			}
		}
		void _Destroy(PNode& pRoot)
		{
			if (pRoot)
			{
				_Destroy(pRoot->_pLeft);
				_Destroy(pRoot->_pRight);
				pRoot = nullptr;
			}
		}

	private:
		PNode _pRoot;
	};
}

int main()
{
	mmc::BSTree<int> tree;
	tree.Insert(10);
	tree.Insert(6);
	if (!tree.Insert(12))
	{
		cout << "����ʧ��" << endl;
	}
	if (!tree.Insert(32))
	{
		cout << "����ʧ��" << endl;
	}
	if (!tree.Insert(20))
	{
		cout << "����ʧ��" << endl;
	}
	tree.Insert(15);
	tree.Insert(186);
	tree.Insert(92);
	tree.Insert(39);
	tree.InOrder();
	cout << endl;
	if (tree.Find(15))
		cout << "<tree::node 15> :�ҵ��� " << endl;
	tree.Erase(32);
	tree.InOrder();

	system("pause");
	return 0;
}