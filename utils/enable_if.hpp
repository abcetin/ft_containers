#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP

#include "is_integral.hpp"

namespace ft
{
	template< bool, typename>struct enable_if{};
	template<typename _Tp> struct enable_if<true, _Tp>{ typedef _Tp type; };
};

#endif
