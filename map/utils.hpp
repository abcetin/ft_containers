#ifndef UTILS_HPP
#define UTILS_HPP

#include "tree/avl_tree.hpp"
#include "../utils/iterator_traits.hpp"
#include <iostream>

namespace ft
{

	template <typename T>
	struct node
	{
		typedef node<T> *_Base_ptr;
		typedef const node<T> *_Const_Base_ptr;

		T data;
		int height;
		_Base_ptr left_node;
		_Base_ptr right_node;
		_Base_ptr parent_node;

		node() : data(0), height(0), left_node(0), right_node(0), parent_node(0) {}

		node(const T &_value, _Base_ptr left = NULL, _Base_ptr right = NULL, _Base_ptr parent = NULL)
			: data(_value), height(1), left_node(left), right_node(right), parent_node(parent) {}

		_Base_ptr _minimum(_Base_ptr _x)
		{
			if (!_x || !_x->left_node)
				return _x;
			return _minimum(_x->left_node);
		}

		_Base_ptr _maximum(_Base_ptr _x)
		{
			if (!_x || !_x->right_node)
				return _x;
			return _maximum(_x->right_node);
		}
	};

	template <typename _Base_ptr>
	_Base_ptr tree_increment(_Base_ptr _x)
	{
		if (_x->right_node)
			_x = _x->_minimum(_x->right_node);
		else
		{
			_Base_ptr _y = _x->parent_node;
			while(_y &&_x == _y->right_node)
			{
				_x = _y;
				_y = _y->parent_node;
			}
			if (_x->right_node != _y)
				_x = _y;
		}
		return _x;
	}

	template <typename _Tp>
	const node<_Tp> *tree_increment(const node<_Tp>* _x)
	{
		return tree_increment(const_cast<node<_Tp>* >(_x));
	}

	template<typename _Tp>
	node<_Tp> *tree_decrement(node<_Tp>* _x)
	{
		node<_Tp>* _y;

		if (!_x && _x->parent_node->parent_node == _x)
		 	_x = _x->right_node;
		else if (_x->left_node)
			_x = _x->_maximum(_x->left_node);
		else
		{
			_y = _x->parent_node;
			while (_x == _y->left_node)
			{
				_x = _y;
				_y = _y->parent_node;
			}
			_x = _y;
		}
		return _x;
	}

	template <typename _Tp>
	const node<_Tp> *tree_decrement(const node<_Tp>* _x)
	{
		return tree_decrement(const_cast<node<_Tp>* >(_x));
	}

}

#endif