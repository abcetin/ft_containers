#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include "utils.hpp"

namespace ft
{
	template <typename T> class avl_tree
	{	
			public:
				node<T> *_tree;
				node<T> *_start;
				node<T> *_end;

				typedef T							value_type;
				typedef const ft::tree_iterator<T>	const_iterator;
				typedef ft::tree_iterator<T>		iterator; // const_iterator yap sonra
				typedef iterator					const_reverse_iterator; //hepsinin const olmasının sebebi ağaçta verilerin yeniden atanmasını istemiyoruz.
				typedef const_iterator				reverse_iterator;		//avl_ağaç yapısını bozabileceği için eğer atama iterator ile yapılırsa hatalı çalışmalara sebep olabilir.

			private:

			node<T> *RR(node<T> *x)
			{
				node<T> *y = x->right_node;
				node<T> *z = y->left_node;

				if (x)
					y->parent_node = x->parent_node;
				y->left_node = x;
				x->right_node = z;
				if (x)
					x->parent_node = y;
				if (z)
					z->parent_node = x;
				x->height = std::max(height(x->left_node), height(x->right_node)) + 1;
				y->height = std::max(height(y->left_node), height(y->right_node)) + 1;
				return y;
			}

			node<T> *LL(node<T> *x)
			{
				node<T> *y = x->left_node;
				node<T> *z = y->right_node;

				if (x)
					y->parent_node = x->parent_node;
				y->right_node = x;
				x->left_node = z;
				if (x)
					x->parent_node = y;
				if (z)
					z->parent_node = x;
				x->height = std::max(height(x->left_node), height(x->right_node)) + 1;
				y->height = std::max(height(y->left_node), height(y->right_node)) + 1;
				return y;
			}

			node<T> *delete_node(node<T> *_node, const T& _value)
			{
				node<T>* temp;
				if (!_node)
					return _node;
				if (_value > _node->data)
					_node->right_node = delete_node(_node->right_node, _value);
				else if (_value < _node->data)
					_node->left_node = delete_node(_node->left_node, _value);
				else
				{
					if (!(_node->left_node) || !(_node->right_node))
					{
						temp = _node->left_node ? _node->left_node : _node->right_node;
						if (!temp)
						{
							temp = _node;
							_node = NULL;
						}
						else
							_node = temp;
						free(temp); //deallocate yap unutma
						return _node;
					}
					else
					{
						temp = find_largest_node(_node->left_node);
						_node->data = temp->data;
						_node->left_node = delete_node(_node->left_node, temp->data);
					}
				}
				_node->height = 1 + std::max(height(_node->left_node), height(_node->right_node));
				_node = balance(_node);
				return _node;
			}

			node<T> *balance(node<T> *_node)
			{
				int balance = get_balance(_node);
				if (balance >= -1 && balance <= 1)
					return _node;
				if (_node->left_node && balance > 1 && get_balance(_node->left_node) >= 1)
					return LL(_node);
				if (_node->right_node && balance < -1 && get_balance(_node->right_node) <= -1)
					return RR(_node);
				if (_node->left_node && balance > 1 && get_balance(_node->left_node) <= -1)
				{
					_node->left_node = RR(_node->left_node);
					return LL(_node);
				}
				if (_node->right_node && balance < -1 &&  get_balance(_node->right_node) >= 1)
				{
					_node->right_node = LL(_node->right_node);
					return RR(_node);
				}
				return _node;
			}

			node<T>* add_with_balance(node<T> *_node, const T& _value, node<T>* parent)
			{
				if (!_node)
					return (new node<T>(_value, NULL, NULL, parent));
				else if (_value < _node->data)
					_node->left_node = add_with_balance(_node->left_node, _value, _node);
				else if (_value >= _node->data)
					_node->right_node = add_with_balance(_node->right_node, _value, _node);
				else
					return _node;
				_node->height = 1 + std::max(height(_node->left_node), height(_node->right_node));
				_node = balance(_node);
				return _node;
			}

			node<T> *find_largest_node(node<T> *_node)
			{
				if ((!_node->left_node && !_node->right_node) || !_node)
					return _node;
				if (_node->right_node)
					_node = find_largest_node(_node->right_node);
				else if (_node->left_node)
					_node = find_largest_node(_node->left_node);
				return _node;
			}

			int height(node<T> *_node)
			{
				if (_node == NULL)
					return 0;
				return _node->height;
			}
		public:
			avl_tree(): _tree(), _start(){_end = new node<T>(0);}

			void insert(const T& _value)
			{	
				this->_tree = add_with_balance(this->_tree, _value, this->_tree);
				// this->_end->parent_node = max;
			}

			int get_balance(node<T> *_node)
			{
				if (!_node)
					return 0;
				return (height(_node->left_node) - height(_node->right_node));
			}

			node<T> *search(node<T> *_node, const T& _value)
			{
				if (!_node)
					return _node;
				if (_value == _node->data)
					return _node;
				if (_value >= _node->data)
					_node = search(_node->right_node, _value);
				else if (_value < _node->data)
					_node = search(_node->left_node, _value);
				return _node;
			}

			void _delete_node(const T& _value)
			{
				this->_tree = delete_node(this->_tree, _value);
			}

			const_iterator begin() const
			{
				return const_iterator(this->_tree->_minimum(_tree));
			}

			iterator begin()
			{
				return iterator(this->_tree->_minimum(_tree));
			}

			const_iterator end() const //end nullptr döndürür
			{
				
				return const_iterator(this->_tree);
			}

			iterator end() //end nullptr döndürür
			{
				return iterator(this->_end);
			}

			~avl_tree()
			{
				// while(_tree)
				// {
				// 	_delete_node(_tree->data);
				// }
			}
	};

};

#endif