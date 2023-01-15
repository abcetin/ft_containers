#ifndef ROTATION_HPP
#define ROTATION_HPP


#include "../utils.hpp"
#include "tree_utils.hpp"

namespace ft
{

	template <typename _Base_ptr>
	_Base_ptr RR(_Base_ptr x)
	{
		std::cout << "rr\n";
		_Base_ptr y = x->right_node;
		_Base_ptr z = y->left_node;
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

	template <typename _Base_ptr>
	_Base_ptr LL(_Base_ptr x)
	{
		std::cout << "ll\n";
		_Base_ptr y = x->left_node;
		_Base_ptr z = y->right_node;
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
};
#endif