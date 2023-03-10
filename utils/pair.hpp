#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft
{
	template<class _T1, class _T2> struct pair
	{
		typedef _T1 first_type;
		typedef _T2 second_type;

		first_type	first;
		second_type	second;

		explicit pair(): first(), second() {};
		
		template<class U, class V>
		pair (const pair<U,V>& pr): first(pr.first), second(pr.second){};

		pair (const first_type& a, const second_type& b): first(a), second(b) {};

		pair& operator=( const pair& other )
		{
			first = other.first;
			second = other.second;
			return *this;
		}

	};

	template< class T1, class T2 >
	bool operator<( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		return (lhs.first < rhs.first || (!( rhs.first < lhs.first) && lhs.second < rhs.second));
	}

	template< class T1, class T2 >
	bool operator==( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template< class T1, class T2 >
	bool operator!=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		return (!(lhs == rhs));
	}

	template< class T1, class T2 >
	bool operator<=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		return (!(rhs < lhs));
	}

	template< class T1, class T2 >
	bool operator>( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		return (rhs < lhs);
	}

	template< class T1, class T2 >
	bool operator>=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		return (!(lhs < rhs));
	}

	template< class T1, class T2 >
	ft::pair<T1, T2> make_pair( T1 t, T2 u )
	{
		return (ft::pair<T1, T2>(t, u));
	}
}


#endif