#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "utils.hpp"

namespace ft
{
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

		_Self& operator--()
		{
			_M_node = tree_decrement(_M_node);
			return *this;
		}

		_Self operator--(int)
		{
			tree_iterator _temp = *this;
			_M_node = tree_decrement(_M_node);
			return _temp;
		}

		bool operator!=(const _Self &_x)
		{
			return _x._M_node != _M_node;
		}

		bool operator==(const _Self &_x)
		{
			return _x._M_node == _M_node;
		}
	};

	template <typename _Tp>
	struct const_tree_iterator
	{
		typedef _Tp		value_type;
		typedef _Tp&	reference;
		typedef _Tp*	pointer;

		typedef std::ptrdiff_t 							difference_type;
		typedef std::bidirectional_iterator_tag			iterator_category;
		typedef tree_iterator<_Tp>						iterator;

		typedef const_tree_iterator<_Tp>				_Self;
		typedef typename node<_Tp>::_Const_Base_ptr		_Base_ptr;

		_Base_ptr _M_node;

		const_tree_iterator(): _M_node(_Tp()) {}

		explicit const_tree_iterator(const _Base_ptr _x) : _M_node(_x) {}

		const_tree_iterator(const_tree_iterator& _it) : _M_node(_it._M_node) {}

		reference operator*() const { return _M_node->data; }

		pointer operator->() const { return &_M_node->data; }

		_Self& operator++()
		{
			_M_node = tree_increment(_M_node);
			return *this;
		}

		_Self operator++(int)
		{
			const_tree_iterator _temp = *this;
			_M_node = tree_increment(_M_node);
			return _temp;
		}

		_Self& operator--()
		{
			_M_node = tree_decrement(_M_node);
			return *this;
		}

		_Self operator--(int)
		{
			const_tree_iterator _temp = *this;
			_M_node = tree_decrement(_M_node);
			return _temp;
		}

		bool operator!=(const _Self &_x)
		{
			return _x._M_node != _M_node;
		}

		bool operator==(const _Self &_x)
		{
			return _x._M_node == _M_node;
		}
	};

	template <typename _T> bool operator==(const tree_iterator<_T>& _x, const const_tree_iterator<_T>& _y)
	{ return _x._M_node == _y._M_node; }

	template <typename _T> bool operator!=(const tree_iterator<_T>& _x, const const_tree_iterator<_T>& _y)
	{ return _x._M_node != _y._M_node; }
}


#endif