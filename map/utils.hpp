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

		node(const T &_value, node<T> *left = NULL, node<T> *right = NULL)
			: data(_value), height(1), left_node(left), right_node(right) {}

		// minimum maxmimum bulan fonksiyonun buraya al;
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

		_Base_ptr _M_node;

		tree_iterator(): _M_node() {}

		explicit tree_iterator(const _Base_ptr _x) : _M_node(_x) {}

		reference operator*() const { return (_M_node->data); }
		pointer operator->() const { return &(_M_node)->data; }
		// explicit tree_iterator(const node<_Tp> *_x) : _node(_x) {}
		//  node<_Tp> *bigger_than_self(const _Tp &_value)
		//  {
		//  	node<_Tp> *temp = _node;
		//  	if (!temp)
		//  		return temp;
		//  	while (temp)
		//  	{
		//  		if (_value <= temp->data && (temp->left_node->data == _value || temp->right_node->data == _value))
		//  			return temp;
		//  		else if (_value <= _node->data && temp->left_node->data != _value)
		//  			temp = temp->left_node;
		//  		else if (_value >= _node->data && temp->right_node->data != _value)
		//  			temp = temp->right_node;
		//  	}
		//  }
		//  tree_iterator &operator++()
		//  {
		//  	if (!_node)
		//  		return *this;
		//  	if (_node->right_node)
		//  		_node = _minimum(_node->right_node);
		//  	else
		//  	{
		//  		node<_Tp> *_parent = bigger_than_self(_node->data);
		//  		while (_node && _node == _parent->right_node)
		//  		{
		//  			_node = _parent;
		//  			_parent = bigger_than_self(_parent->data);
		//  		}
		//  		_node = _parent;
		//  	}
		//  	return *this;
		//  }
	};
}

#endif