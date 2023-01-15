#ifndef INSERT_DELETE_HPP
#define INSERT_DELETE_HPP

#include "../utils.hpp"
#include "tree_utils.hpp"
namespace ft
{

	//template <typename T, typename _Compare = std::less<T>, typename _Allocator = std::allocator<T> >
	

	template <typename T, typename _Allocator = std::allocator<T>>
	node<T> *_delete_node(node<T> *_node, const T &_value, const _Allocator _alloc = _Allocator())
	{
		node<T> *temp;
		if (!_node)
			return _node;
		if (_value > _node->data)
			_node->right_node = _delete_node(_node->right_node, _value);
		else if (_value < _node->data)
			_node->left_node = _delete_node(_node->left_node, _value);
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
				_alloc.destroy(temp);
				_alloc.deallocate(temp, 1);
				//free(temp); // deallocate yap unutma
				return _node;
			}
			else
			{
				temp = _node->_maxmimum(_node);
				_node->data = temp->data;
				_node->left_node = _delete_node(_node->left_node, temp->data);
			}
		}
		_node->height = 1 + std::max(height(_node->left_node), height(_node->right_node));
		_node = balance(_node);
		return _node;
	}

	template<typename _Val, typename _Alloc = std::allocator<_Val> >
	node<_Val> *_copy(node<_Val>* tree, node<_Val> *first, const _Alloc _alloc = _Alloc())
	{
		if (first)
		{
			tree = _alloc.allocate(1);
			_alloc.construct(tree, first->data);
			_copy(tree->left_node, first->left_node);
			_copy(tree->right_node, first->right_node);
		}
		else
		{
			if (tree->right_node)
				tree->right_node->parent_node = tree;
			if (tree->left_node)
				tree->left_node->parent_node = tree;
			return tree;
		}
	}

};

#endif