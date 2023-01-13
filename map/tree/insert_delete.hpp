#ifndef INSERT_DELETE_HPP
#define INSERT_DELETE_HPP

#include "../utils.hpp"
#include "tree_utils.hpp"
namespace ft
{
	template <typename T>
	node<T> *add_with_balance(node<T> *_node, const T &_value, node<T> *parent)
	{
		if (!_node)
			return (new node<T>(_value, NULL, NULL, parent)); // allocator ile değiştir
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

	template <typename T>
	node<T> *_delete_node(node<T> *_node, const T &_value)
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
				free(temp); // deallocate yap unutma
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
};

#endif