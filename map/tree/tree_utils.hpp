#ifndef TREE_UTILS_HPP
#define TREE_UTILS_HPP

#include "../utils.hpp"

namespace ft
{
	template <typename T>
	int height(node<T> *_node)
	{
		if (_node == NULL)
			return 0;
		return _node->height;
	}

	template <typename T>
	int _get_balance(node<T> *_node)
	{
		if (!_node)
			return 0;
		return (height(_node->left_node) - height(_node->right_node));
	}

	template <typename T>
	node<T> *balance(node<T> *_node)
	{
		int balance = _get_balance(_node);
		int right_balance = _get_balance(_node->right_node);
		int left_balance = _get_balance(_node->left_node);
		if (balance >= -1 && balance <= 1)
			return _node;
		if (_node->left_node && balance > 1 && left_balance >= 1)
			return LL(_node);
		if (_node->right_node && balance < -1 && right_balance <= -1)
			return RR(_node);
		if (_node->left_node && balance > 1 && left_balance <= -1)
		{
			_node->left_node = RR(_node->left_node);
			return LL(_node);
		}
		if (_node->right_node && balance < -1 && right_balance >= 1)
		{
			_node->right_node = LL(_node->right_node);
			return RR(_node);
		}
		return _node;
	}
};

#endif
