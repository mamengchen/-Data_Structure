
#include <iostream>
#include <iomanip>
using namespace std;

namespace mmc
{
	template <class T>
	class AVLTreeNode {
	public:
		T key;		//键值
		int height;	//高度	
		AVLTreeNode<T>* _pLeft;	//左孩子
		AVLTreeNode<T>* _pRight;//右孩子

		AVLTreeNode(T value, AVLTreeNode *pleft, AVLTreeNode *pright)
			:key(value)
			, height(0)
			, _pLeft(pleft)
			, _pRight(pright)
		{}
	};

	template <class T>
	class AVLTree
	{
		typedef AVLTreeNode<T> Node;
		typedef AVLTreeNode<T>* PNode;
	private:
		PNode pRoot;	//根节点

	public:
		AVLTree()
			:pRoot(NULL)
		{}
		~AVLTree()
		{
			destroy(pRoot);
		}

		//获取树的高度
		int height()
		{
			return _height(pRoot);
		}

		int max(int a, int b)
		{
			return (a > b) ? (a) : (b);
		}

		//前序
		void preOrder()
		{
			return _preOrder(pRoot);
		}

		//中序
		void inOrder()
		{
			return _inOrder(pRoot);
		}
		//后序
		void postOrder()
		{
			return _postOrder(pRoot);
		}

		//(递归实现)查找“avl树”中键值为key的节点
		PNode search(T key)
		{
			return _search(pRoot, key);
		}
		PNode iterativeSearch(T key)
		{
			return _iterativeSearch(pRoot, key);
		}

		//查找最小结点：返回最小结点的键值。
		T minimum()
		{
			PNode pNode = _minimum(pRoot);
			if (pNode != NULL)
				return pNode->key;
			return NULL;
		}
		//查找最大结点：返回最大结点的键值。
		T maximum()
		{
			PNode pNode = _maximum(pRoot);
			if (pNode != NULL)
				return pNode->key;
			return NULL;
		}

		//将结点(key为节点键值)插入到AVL树中
		void insert(T key)
		{
			_insert(pRoot, key);
		}

		//删除结点(key为节点键值)
		void avltree_remove(T key)
		{
			PNode z;
			if ((z = _search(pRoot, key)) != NULL)
			{
				pRoot = _remove(pRoot, z);
			}
		}

		//销毁AVL树
		void destroy()
		{
			_destroy(pRoot);
		}

		void print()
		{
			if (pRoot != NULL)
			{
				_print(pRoot, pRoot->key, 0);
			}
		}
	private:
		int _height(PNode tree)
		{
			if (tree != NULL)
				return tree->height;
			return 0;
		}

		void _preOrder(PNode tree) const
		{
			if (tree != NULL)
			{
				cout << tree->key << " ";
				_preOrder(tree->_pLeft);
				_preOrder(tree->_pRight);
			}
		}

		void _inOrder(PNode tree) const
		{
			if (tree != NULL)
			{
				_inOrder(tree->_pLeft);
				cout << tree->key << " ";
				_inOrder(tree->_pRight);
			}
		}

		void _postOrder(PNode tree) const
		{
			if (tree != NULL)
			{
				_postOrder(tree->_pLeft);
				_postOrder(tree->_pRight);
				cout << tree->key << " ";
			}
		}

		PNode _search(PNode x, T key) const
		{
			if (x == NULL || x->key == key)
				return x;
			if (key < x->key)
				return _search(x->_pLeft, key);
			else
				return _search(x->_pRight, key);
		}

		PNode _iterativeSearch(PNode x, T key) const
		{
			while ((x != NULL) || (x->key != key))
			{
				if (key < x->key)
					x = x->_pLeft;
				else
					x = x->_pRight;
			}
			return x;
		}

		PNode _minimum(PNode tree)
		{
			if (tree == NULL)
				return NULL;
			while (tree->_pLeft != NULL)
			{
				tree = tree->_pLeft;
			}
			return tree;
		}

		PNode _maximum(PNode tree)
		{
			if (tree == NULL)
			{
				return NULL;
			}
			while (tree->_pRight != NULL)
			{
				tree = tree->_pRight;
			}
			return tree;
		}

		//LL:左左对应的情况（左单旋转）。
		PNode _left_left_rotation(PNode k2)
		{
			PNode k1;
			k1 = k2->_pLeft;
			k2->_pLeft = k1->_pRight;
			k1->_pRight = k2;

			k2->height = max(_height(k2->_pLeft), _height(k2->_pRight)) + 1;
			k1->height = max(_height(k1->_pLeft), k2->height) + 1;

			return k1;
		}

		//RR:右右对应的情况（右单旋转）。
		PNode _right_right_rotation(PNode k1)
		{
			PNode k2;

			k2 = k1->_pRight;
			k1->_pRight = k2->_pLeft;
			k2->_pLeft = k1;

			k1->height = max(_height(k1->_pLeft), _height(k1->_pRight)) + 1;
			k2->height = max(_height(k2->_pRight), k1->height) + 1;

			return k2;
		}

		//LR:左右对应的情况（左双旋转）
		PNode _left_right_rotation(PNode k3)
		{
			k3->_pLeft = _right_right_rotation(k3->_pLeft);
			return _left_left_rotation(k3);
		}

		//RL:右左对应的情况（右双旋转）
		PNode _right_left_rotation(PNode k1)
		{
			k1->_pRight = _left_left_rotation(k1->_pRight);
			return _right_right_rotation(k1);
		}

		//将结点(z)插入到AVL树（tree）中
		PNode _insert(PNode &tree, T key)
		{
			if (tree == NULL)
			{
				//新建节点
				tree = new AVLTreeNode<T>(key, nullptr, nullptr);
				if (tree == NULL)
				{
					cout << "ERROR: create avltree node failed!" << endl;
					return NULL;
				}
			}
			else if (key < tree->key)
			{
				//应该将key插入到"tree的左子树"的情况
				tree->_pLeft = _insert(tree->_pLeft, key);
				//插入节点之后，若AVL树失去平衡，则进行相应的调节。
				if (_height(tree->_pLeft) - _height(tree->_pRight) == 2)
				{
					if (key < tree->_pLeft->key)
						tree = _left_left_rotation(tree);
					else
						tree = _left_right_rotation(tree);
				}
			}
			else if (key > tree->key) //应该将key插入到“tree的右子树”的情况
			{
				tree->_pRight = _insert(tree->_pRight, key);
				//插入节点后，若AVL树失去平衡，则进行相应的调节。
				if (_height(tree->_pRight) - _height(tree->_pLeft) == 2)
				{
					if (key > tree->_pRight->key)
						tree = _right_right_rotation(tree);
					else
						tree = _right_left_rotation(tree);
				}
			}
			else //key == tree->key
			{
				cout << "添加失败：不允许添加相同的节点！" << endl;
			}
			tree->height = max(_height(tree->_pLeft), _height(tree->_pRight)) + 1;
			return tree;
		}

		//删除avl树（tree）中的结点（z），并返回被删除的结点
		PNode _remove(PNode &tree, PNode z)
		{
			//根为空 或者 没有要删除的节点，直接返回NULL。
			if (tree == NULL || z == NULL)
				return NULL;

			if (z->key < tree->key)	//待删除的节点在"tree的左子树"中
			{
				tree->_pLeft = _remove(tree->_pLeft, z);
				// 删除节点之后，若AVL树失去平衡，则进行相应的调节。
				if (_height(tree->_pRight) - _height(tree->_pLeft) == 2)
				{
					PNode r = tree->_pRight;
					//删除节点后，若AVL树失去平衡，则进行相应的调节。
					if (_height(r->_pLeft) > _height(tree->_pRight))
					{
						tree = _right_left_rotation(tree);
					}
					else
						tree = _right_right_rotation(tree);
				}
			}
			else if (z->key > tree->key)	//待删除的节点在"tree的右子树"中
			{
				tree->_pRight = _remove(tree->_pRight, z);
				//删除节点后，若AVL树失去平衡，则进行相应的调节。
				if (_height(tree->_pLeft) - _height(tree->_pRight) == 2)
				{
					PNode l = tree->_pLeft;
					if (_height(l->_pRight) > _height(l->_pLeft))
						tree = _left_right_rotation(tree);
					else
						tree = _left_left_rotation(tree);
				}
			}
			else
			{
				//tree是对应要删除的节点。
				//tree的左右孩子都非空
				if ((tree->_pLeft != NULL) && (tree->_pRight != NULL))
				{
					if (_height(tree->_pLeft) > _height(tree->_pRight))
					{
						// 如果tree的左子树比右子树高；
						// 则(01)找出tree的左子树中的最大节点
						//   (02)将该最大节点的值赋值给tree。
						//   (03)删除该最大节点。
						// 这类似于用"tree的左子树中最大节点"做"tree"的替身；
						// 采用这种方式的好处是：删除"tree的左子树中最大节点"之后，AVL树仍然是平衡的。
						PNode max = _maximum(tree->_pLeft);
						tree->key = max->key;
						tree->_pLeft = _remove(tree->_pLeft, max);
					}
					else
					{
						// 如果tree的左子树不比右子树高(即它们相等，或右子树比左子树高1)
						// 则(01)找出tree的右子树中的最小节点
						//   (02)将该最小节点的值赋值给tree。
						//   (03)删除该最小节点。
						// 这类似于用"tree的右子树中最小节点"做"tree"的替身；
						// 采用这种方式的好处是：删除"tree的右子树中最小节点"之后，AVL树仍然是平衡的。
						PNode min = _minimum(tree->_pRight);
						tree->key = min->key;
						tree->_pRight = _remove(tree->_pRight, min);
					}
				}
				else
				{
					PNode tmp = tree;
					tree = (tree->_pLeft != NULL) ? tree->_pLeft : tree->_pRight;
					delete tmp;
				}
			}
			return tree;
		}


		//销毁AVL树
		void _destroy(PNode &tree)
		{
			if (nullptr == tree)
				return;
			if (tree->_pLeft != NULL)
				_destroy(tree->_pLeft);
			if (tree->_pRight != NULL)
				_destroy(tree->_pRight);
			delete tree;
		}

		//打印avl树
		void _print(PNode tree, T key, int direction)
		{
			if (tree != NULL)
			{
				if (direction == 0)
					cout << setw(2) << tree->key << "is root" << endl;
				else
					cout << setw(2) << tree->key << " is " << setw(2) << key << "'s " << setw(12) << (direction == 1 ? "right child" : "left child") << endl;
				_print(tree->_pLeft, tree->key, -1);
				_print(tree->_pRight, tree->key, 1);
			}
		}
	};
}