#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <iterator>
#include "avl_tree.hpp"
#include "../utils/iterator_traits.hpp"

namespace ft
{
	template <typename T>
	struct node
	{
		T data;
		int height;
		node<T> *left_node;
		node<T> *right_node;

		node(const T& _value, node<T> *left = NULL, node<T> *right = NULL)
		: data(_value), height(1), left_node(left), right_node(right) {}
	};

	template <class _Tp>
	struct tree_iterator : std::iterator<std::bidirectional_iterator_tag, _Tp>
	{
		typedef _Tp												iterator_type;
		typedef typename ft::iterator_traits<_Tp>::value_type	value_type;
		typedef typename ft::iterator_traits<_Tp>::pointer		pointer;
		typedef typename ft::iterator_traits<_Tp>::reference	reference;
		typedef std::bidirectional_iterator_tag 				iterator_category;
		typedef std::ptrdiff_t									difference_type;

		const node<_Tp>* _node;

		tree_iterator(const ft::node<_Tp>* _x) : _node(_x){}

		const reference operator*() const { return (_node->data); }

		pointer operator->() const {return (_node); }

		//explicit tree_iterator(const node<_Tp> *_x) : _node(_x) {}

		// node<_Tp> *bigger_than_self(const _Tp &_value)
		// {
		// 	node<_Tp> *temp = _node;
		// 	if (!temp)
		// 		return temp;
		// 	while (temp)
		// 	{
		// 		if (_value <= temp->data && (temp->left_node->data == _value || temp->right_node->data == _value))
		// 			return temp;
		// 		else if (_value <= _node->data && temp->left_node->data != _value)
		// 			temp = temp->left_node;
		// 		else if (_value >= _node->data && temp->right_node->data != _value)
		// 			temp = temp->right_node;
		// 	}
		// }

		// tree_iterator &operator++()
		// {
		// 	if (!_node)
		// 		return *this;
		// 	if (_node->right_node)
		// 		_node = _minimum(_node->right_node);
		// 	else
		// 	{
		// 		node<_Tp> *_parent = bigger_than_self(_node->data);
		// 		while (_node && _node == _parent->right_node)
		// 		{
		// 			_node = _parent;
		// 			_parent = bigger_than_self(_parent->data);
		// 		}
		// 		_node = _parent;
		// 	}
		// 	return *this;
		// }
	};
}

#endif