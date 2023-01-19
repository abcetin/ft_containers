#ifndef TREE_UTILS_HPP
#define TREE_UTILS_HPP

#include "../utils.hpp"

namespace ft
{
	template <typename _Base_ptr>
	int height(_Base_ptr _node)
	{
		if (_node == NULL)
			return 0;
		return _node->height;
	}

	template <typename _Base_ptr>
	int _get_balance(_Base_ptr _node)
	{
		if (!_node)
			return 0;
		return (height(_node->left_node) - height(_node->right_node));
	}

	template <typename _Base_ptr>
	_Base_ptr balance(_Base_ptr _node)
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

	template <typename map>
	void print_tree(map avl, std::string str)
	{
		if (avl == NULL)
			return;
		std::cout << str << " " << avl->data.first << " " << avl->data.second << " ";
		if (avl->parent_node)
			std::cout << "parent :"<< avl->parent_node->data.first << " " << avl->parent_node->data.second;
		std::cout << std::endl;
		print_tree(avl->left_node, str + " left");
		print_tree(avl->right_node, str + " right");
	}

};

#endif
