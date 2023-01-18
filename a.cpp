// void _Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::
// 	swap(_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc> &__t)
// {
// 	if (_M_root() == 0)
// 	{
// 		if (__t._M_root() != 0)
// 		{
// 			_M_root() = __t._M_root();
// 			_M_leftmost() = __t._M_leftmost();
// 			_M_rightmost() = __t._M_rightmost();
// 			_M_root()->_M_parent = _M_end();

// 			__t._M_root() = 0;
// 			__t._M_leftmost() = __t._M_end();
// 			__t._M_rightmost() = __t._M_end();
// 		}
// 	}
// 	else if (__t._M_root() == 0)
// 	{
// 		__t._M_root() = _M_root();
// 		__t._M_leftmost() = _M_leftmost();
// 		__t._M_rightmost() = _M_rightmost();
// 		__t._M_root()->_M_parent = __t._M_end();

// 		_M_root() = 0;
// 		_M_leftmost() = _M_end();
// 		_M_rightmost() = _M_end();
// 	}
// 	else
// 	{
// 		std::swap(_M_root(), __t._M_root());
// 		std::swap(_M_leftmost(), __t._M_leftmost());
// 		std::swap(_M_rightmost(), __t._M_rightmost());

// 		_M_root()->_M_parent = _M_end();
// 		__t._M_root()->_M_parent = __t._M_end();
// 	}
// 	// No need to swap header's color as it does not change.
// 	std::swap(this->_M_impl._M_node_count, __t._M_impl._M_node_count);
// 	std::swap(this->_M_impl._M_key_compare, __t._M_impl._M_key_compare);

// 	// _GLIBCXX_RESOLVE_LIB_DEFECTS
// 	// 431. Swapping containers with unequal allocators.
// 	std::__alloc_swap<_Node_allocator>::
// 		_S_do_it(_M_get_Node_allocator(), __t._M_get_Node_allocator());
// }