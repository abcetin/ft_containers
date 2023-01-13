#ifndef	NORMAL_ITERATOR_HPP
#define NORMAL_ITERATOR_HPP

#include "utils.h"
#include "iterator_traits.hpp"
#include "enable_if.hpp"

namespace ft
{
	//__are_same Türlerin eşitliği için.

	template <typename _Iterator, typename _Container>
	class normal_iterator
	{
		protected:
			_Iterator _current;

		public:
			typedef typename ft::iterator_traits<_Iterator>::pointer			pointer;
			typedef typename ft::iterator_traits<_Iterator>::reference			reference;
			typedef typename ft::iterator_traits<_Iterator>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<_Iterator>::difference_type	difference_type;
			typedef typename ft::iterator_traits<_Iterator>::value_type			value_type;
		
		public:
			normal_iterator() : _current(_Iterator()){};

			explicit normal_iterator(const _Iterator& _i) : _current(_i){}

			// Yineleyicinin const_iterator olmasına izin verir
			template<typename _Iter> 
			normal_iterator(const normal_iterator<_Iter,
			typename  ft::enable_if<(std::__are_same<_Iter, typename _Container::pointer>::__value),
            _Container>::__type>& _i) : _current(_i.base()){}

			reference operator*() const {return *_current;}

			pointer operator->() const {return _current;}

			normal_iterator& operator++() {++_current; return *this;}

			normal_iterator operator++(int) {return normal_iterator(_current++);}

			normal_iterator& operator--() {--_current; return *this;}

			normal_iterator operator--(int) {return normal_iterator(_current--);}

			reference operator[](const difference_type& _n) {return _current[_n];}

			normal_iterator& operator+=(const difference_type& _n) {_current += _n; return *this;}

			normal_iterator operator+(const difference_type& _n) const { return normal_iterator(_current + _n);}

			normal_iterator& operator-=(const difference_type& _n) {_current -= _n; return *this;}

			normal_iterator operator-(const difference_type& _n) const {return normal_iterator(_current - _n);}

			const _Iterator& base() const {return _current;}

	};

	//------------------No Member Func------------------------//
	template< typename  Iterator1, typename  Iterator2, typename _Container > bool 
	operator==( const ft::normal_iterator<Iterator1, _Container>& lhs,
    const ft::normal_iterator<Iterator2, _Container>& rhs ){return lhs.base() == rhs.base();}

	template<  typename  Iterator1, typename  Iterator2, typename _Container > bool
	operator!=( const ft::normal_iterator<Iterator1, _Container>& lhs,
    const ft::normal_iterator<Iterator2, _Container>& rhs ){return lhs.base() != rhs.base();}

	template<  typename  Iterator1, typename  Iterator2, typename _Container >bool
	operator<( const ft::normal_iterator<Iterator1, _Container>& lhs,
    const ft::normal_iterator<Iterator2, _Container>& rhs ){return lhs.base() < rhs.base();}

	template<  typename  Iterator1, typename  Iterator2, typename _Container >bool
	operator<=( const ft::normal_iterator<Iterator1, _Container>& lhs,
    const ft::normal_iterator<Iterator2, _Container>& rhs ){return lhs.base() <= rhs.base();}

	template<  typename  Iterator1, typename  Iterator2, typename _Container >bool
	operator>( const ft::normal_iterator<Iterator1, _Container>& lhs,
    const ft::normal_iterator<Iterator2, _Container>& rhs ){return lhs.base() > rhs.base();}

	template< typename  Iterator1, typename  Iterator2, typename _Container >bool
	operator>=( const ft::normal_iterator<Iterator1, _Container>& lhs,
    const ft::normal_iterator<Iterator2, _Container>& rhs ){return lhs.base() >= rhs.base();}

	template< typename  Iterator1, typename  Iterator2, typename _Container >typename
	ft::normal_iterator<Iterator1, _Container>::difference_type
    operator+( const ft::normal_iterator<Iterator1, _Container>& lhs,
	const ft::normal_iterator<Iterator2, _Container>& rhs )
	{return lhs.base() + rhs.base();}

	template< typename  Iterator1, typename  Iterator2, typename _Container>typename
	ft::normal_iterator<Iterator1, _Container>::difference_type
    operator-( const ft::normal_iterator<Iterator1, _Container>& lhs,
	const ft::normal_iterator<Iterator2, _Container>& rhs )
	{return lhs.base() - rhs.base();}
}
#endif