#ifndef INSERT_DELETE_HPP
#define INSERT_DELETE_HPP

#include "../utils.hpp"
#include "tree_utils.hpp"
namespace ft
{
	template <typename _Base_ptr, typename _Value, typename _Alloc>
	void create_node(_Base_ptr *_node, _Value _value, _Alloc _allocator)
	{
		*_node = _allocator.allocate(1);
		_allocator.construct(*_node, _value);
	}

	template <typename _Base_ptr, typename _Value, typename _Compare, typename _Alloc>
	_Base_ptr _add_with_balance(_Base_ptr _node, const _Value &_value, _Base_ptr parent, _Compare _comp, _Alloc _allocator)
	{
		if (!_node)
		{
			create_node(&_node, _value, _allocator);
			_node->parent_node = parent;
			return _node;
		}
		else if (_value.first < _node->data.first)
			_node->left_node = _add_with_balance(_node->left_node, _value, _node, _comp, _allocator);
		else if (_value.first >= _node->data.first)
			_node->right_node = _add_with_balance(_node->right_node, _value, _node, _comp, _allocator);
		else
			return _node;
		_node->height = 1 + std::max(height(_node->left_node), height(_node->right_node));
		_node = balance(_node);
		return _node;
	}

	template <typename _Base_ptr, typename _Val, typename _Alloc>
	_Base_ptr _delete_node(_Base_ptr _node, const _Val &_value, _Alloc _alloc)
	{
		_Base_ptr *temp;
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
				// free(temp); // deallocate yap unutma
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

	template <typename _Base_ptr, typename _Val, typename _Alloc>
	_Base_ptr _copy(_Base_ptr tree, _Base_ptr first, _Alloc _alloc)
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