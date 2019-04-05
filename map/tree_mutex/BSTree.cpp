//二叉搜索树
//二叉搜索树又称二叉排序树，它或者是一颗空树，或者是具有以下性质的二叉树：
//若它的左子树不为空，则左子树上所有节点的值都小于根节点的值
//若它的右子树不为空，则右子树上所有节点的值都大于根节点的值
//它的作业子树也分别为二叉搜索树

//插入：
//a.树为空，则直接插入
//b.树不空，按二叉搜索树性质查找插入位置，插入新节点
//删除：
//a.要删除的结点无孩子结点
//b.要删除的结点只有左孩子结点
//c.要删除的结点只有右孩子结点
//d.要删除的结点有左，右孩子结点
//看起来有待删除节点有4种情况，实际情况a可以与情况b或者c合并起来：
//	1.删除该结点且使被删除节点的双亲结点指向被删除节点的左孩子结点
//	2.删除该结点且使被删除节点的双亲结点指向被删除结点的右孩子结点
//	3.在它的右子树中寻找中序下的第一个结点(关键码最小)，用它的值填补到被删除节点中， 再来处理该结点的删除问题

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
			//如果树为空，直接插入
			if (nullptr == _pRoot)
			{
				_pRoot = new Node(data);
				return true;
			}

			//按照二叉树搜索树的性质查找data在树中的插入位置
			PNode pCur = _pRoot;
			//记录pCur的双亲，因为新元素最终插入在pCur双亲左右孩子的位置
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
			//插入元素；
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
			//如果树为空，删除失败
			if (nullptr == _pRoot)
				return false;

			//查找在data在树中的位置
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

			//data不在二叉搜索树中，无法删除
			if (nullptr == pCur)
				return false;
			if (nullptr == pCur->_pRight)
			{
				//右孩子为空
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
				//左孩子为空
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
				//当左右子树都在时，我们需要找到左子树最大的，右子树最小的
				//这里我找的是左子树最小的，
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
					//这里不用判断这个结点一定没有右孩子，其有左孩子和没有左孩子一个样子
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
		cout << "插入失败" << endl;
	}
	if (!tree.Insert(32))
	{
		cout << "插入失败" << endl;
	}
	if (!tree.Insert(20))
	{
		cout << "插入失败" << endl;
	}
	tree.Insert(15);
	tree.Insert(186);
	tree.Insert(92);
	tree.Insert(39);
	tree.InOrder();
	cout << endl;
	if (tree.Find(15))
		cout << "<tree::node 15> :找到了 " << endl;
	tree.Erase(32);
	tree.InOrder();

	system("pause");
	return 0;
}