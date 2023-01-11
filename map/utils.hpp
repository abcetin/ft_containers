#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include "avl_tree.hpp"
#include "../utils/iterator_traits.hpp"

namespace ft
{
	template <typename T>
	struct node
	{
		typedef node<T> *_Base_ptr;
		typedef const node<T> *_Const_Base_ptr;

		T data;
		int height;
		node<T> *left_node;
		node<T> *right_node;
		node<T>	*parent_node;

		node(const T &_value, node<T> *left = NULL, node<T> *right = NULL, node<T>* parent = NULL)
			: data(_value), height(1), left_node(left), right_node(right), parent_node(parent) {}

		_Base_ptr _minimum(_Base_ptr _x)
		{
			if (!_x || !_x->left_node)
				return _x;
			return _minimum(_x->left_node);
		}

		_Base_ptr _maxmimum(_Base_ptr _x)
		{
			if (!_x || !_x->right_node)
				return _x;
			return _maxmimum(_x->right_node);
		}
	};

	template <typename _Tp>
	struct tree_iterator
	{
		typedef _Tp		value_type;
		typedef _Tp&	reference;
		typedef _Tp*	pointer;

		typedef std::ptrdiff_t 						difference_type;
		typedef std::bidirectional_iterator_tag		iterator_category;

		typedef tree_iterator<_Tp>				_Self;
		typedef typename node<_Tp>::_Base_ptr	_Base_ptr;

		_Base_ptr	_M_node;

		tree_iterator(): _M_node(_Tp()) {}

		explicit tree_iterator(const _Base_ptr _x) : _M_node(_x) {}

		reference operator*() const { return _M_node->data; }

		pointer operator->() const { return &_M_node->data; }

		_Self& operator++()
		{
			_M_node = tree_increment(_M_node);
			return *this;
		}

		_Self operator++(int)
		{
			tree_iterator _temp = *this;
			_M_node = tree_increment(_M_node);
			return _temp;
		}

		node<_Tp> *tree_increment(node<_Tp>* _x)
		{
			if (_x->right_node)
				_x = _x->_minimum(_x->right_node);
			else
			{
				node<_Tp>* _y = _x->parent_node;
				printf("y : %d y.r : %d x : %d\n", _y->data, _y->right_node->data, _x->data);
				while(_y && _x == _y->right_node)
				{
					printf("aa %d\n", _y->data);
					_x = _y;
					_y = _y->parent_node;
				}
				if (_x->right_node != _y)
				{
					printf("aa\n");
					_x = _y;
				}
			}
			return _x;
		}

	 	const node<_Tp> *tree_increment(const node<_Tp>* _x)
		{
			node<_Tp>* _tmp = unconst(_x);
			return tree_increment(_tmp);
		}

	};
}

#endif