
#include <iostream>
#include <iomanip>
using namespace std;

namespace mmc
{
	template <class T>
	class AVLTreeNode {
	public:
		T key;		//��ֵ
		int height;	//�߶�	
		AVLTreeNode<T>* _pLeft;	//����
		AVLTreeNode<T>* _pRight;//�Һ���

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
		PNode pRoot;	//���ڵ�

	public:
		AVLTree()
			:pRoot(NULL)
		{}
		~AVLTree()
		{
			destroy(pRoot);
		}

		//��ȡ���ĸ߶�
		int height()
		{
			return _height(pRoot);
		}

		int max(int a, int b)
		{
			return (a > b) ? (a) : (b);
		}

		//ǰ��
		void preOrder()
		{
			return _preOrder(pRoot);
		}

		//����
		void inOrder()
		{
			return _inOrder(pRoot);
		}
		//����
		void postOrder()
		{
			return _postOrder(pRoot);
		}

		//(�ݹ�ʵ��)���ҡ�avl�����м�ֵΪkey�Ľڵ�
		PNode search(T key)
		{
			return _search(pRoot, key);
		}
		PNode iterativeSearch(T key)
		{
			return _iterativeSearch(pRoot, key);
		}

		//������С��㣺������С���ļ�ֵ��
		T minimum()
		{
			PNode pNode = _minimum(pRoot);
			if (pNode != NULL)
				return pNode->key;
			return NULL;
		}
		//��������㣺���������ļ�ֵ��
		T maximum()
		{
			PNode pNode = _maximum(pRoot);
			if (pNode != NULL)
				return pNode->key;
			return NULL;
		}

		//�����(keyΪ�ڵ��ֵ)���뵽AVL����
		void insert(T key)
		{
			_insert(pRoot, key);
		}

		//ɾ�����(keyΪ�ڵ��ֵ)
		void avltree_remove(T key)
		{
			PNode z;
			if ((z = _search(pRoot, key)) != NULL)
			{
				pRoot = _remove(pRoot, z);
			}
		}

		//����AVL��
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

		//LL:�����Ӧ�����������ת����
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

		//RR:���Ҷ�Ӧ��������ҵ���ת����
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

		//LR:���Ҷ�Ӧ���������˫��ת��
		PNode _left_right_rotation(PNode k3)
		{
			k3->_pLeft = _right_right_rotation(k3->_pLeft);
			return _left_left_rotation(k3);
		}

		//RL:�����Ӧ���������˫��ת��
		PNode _right_left_rotation(PNode k1)
		{
			k1->_pRight = _left_left_rotation(k1->_pRight);
			return _right_right_rotation(k1);
		}

		//�����(z)���뵽AVL����tree����
		PNode _insert(PNode &tree, T key)
		{
			if (tree == NULL)
			{
				//�½��ڵ�
				tree = new AVLTreeNode<T>(key, nullptr, nullptr);
				if (tree == NULL)
				{
					cout << "ERROR: create avltree node failed!" << endl;
					return NULL;
				}
			}
			else if (key < tree->key)
			{
				//Ӧ�ý�key���뵽"tree��������"�����
				tree->_pLeft = _insert(tree->_pLeft, key);
				//����ڵ�֮����AVL��ʧȥƽ�⣬�������Ӧ�ĵ��ڡ�
				if (_height(tree->_pLeft) - _height(tree->_pRight) == 2)
				{
					if (key < tree->_pLeft->key)
						tree = _left_left_rotation(tree);
					else
						tree = _left_right_rotation(tree);
				}
			}
			else if (key > tree->key) //Ӧ�ý�key���뵽��tree���������������
			{
				tree->_pRight = _insert(tree->_pRight, key);
				//����ڵ����AVL��ʧȥƽ�⣬�������Ӧ�ĵ��ڡ�
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
				cout << "���ʧ�ܣ������������ͬ�Ľڵ㣡" << endl;
			}
			tree->height = max(_height(tree->_pLeft), _height(tree->_pRight)) + 1;
			return tree;
		}

		//ɾ��avl����tree���еĽ�㣨z���������ر�ɾ���Ľ��
		PNode _remove(PNode &tree, PNode z)
		{
			//��Ϊ�� ���� û��Ҫɾ���Ľڵ㣬ֱ�ӷ���NULL��
			if (tree == NULL || z == NULL)
				return NULL;

			if (z->key < tree->key)	//��ɾ���Ľڵ���"tree��������"��
			{
				tree->_pLeft = _remove(tree->_pLeft, z);
				// ɾ���ڵ�֮����AVL��ʧȥƽ�⣬�������Ӧ�ĵ��ڡ�
				if (_height(tree->_pRight) - _height(tree->_pLeft) == 2)
				{
					PNode r = tree->_pRight;
					//ɾ���ڵ����AVL��ʧȥƽ�⣬�������Ӧ�ĵ��ڡ�
					if (_height(r->_pLeft) > _height(tree->_pRight))
					{
						tree = _right_left_rotation(tree);
					}
					else
						tree = _right_right_rotation(tree);
				}
			}
			else if (z->key > tree->key)	//��ɾ���Ľڵ���"tree��������"��
			{
				tree->_pRight = _remove(tree->_pRight, z);
				//ɾ���ڵ����AVL��ʧȥƽ�⣬�������Ӧ�ĵ��ڡ�
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
				//tree�Ƕ�ӦҪɾ���Ľڵ㡣
				//tree�����Һ��Ӷ��ǿ�
				if ((tree->_pLeft != NULL) && (tree->_pRight != NULL))
				{
					if (_height(tree->_pLeft) > _height(tree->_pRight))
					{
						// ���tree�����������������ߣ�
						// ��(01)�ҳ�tree���������е����ڵ�
						//   (02)�������ڵ��ֵ��ֵ��tree��
						//   (03)ɾ�������ڵ㡣
						// ����������"tree�������������ڵ�"��"tree"������
						// �������ַ�ʽ�ĺô��ǣ�ɾ��"tree�������������ڵ�"֮��AVL����Ȼ��ƽ��ġ�
						PNode max = _maximum(tree->_pLeft);
						tree->key = max->key;
						tree->_pLeft = _remove(tree->_pLeft, max);
					}
					else
					{
						// ���tree��������������������(��������ȣ�������������������1)
						// ��(01)�ҳ�tree���������е���С�ڵ�
						//   (02)������С�ڵ��ֵ��ֵ��tree��
						//   (03)ɾ������С�ڵ㡣
						// ����������"tree������������С�ڵ�"��"tree"������
						// �������ַ�ʽ�ĺô��ǣ�ɾ��"tree������������С�ڵ�"֮��AVL����Ȼ��ƽ��ġ�
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


		//����AVL��
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

		//��ӡavl��
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