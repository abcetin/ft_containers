#include <vector>
#include <iterator>
#include <iostream>
#include "vector/vector.hpp"
#include <stack>
// #include "utils/random_access_iterator.hpp"

int main()
{
	std::vector<char> a;
	ft::vector<int> b;
	// int c[] = { 1, 2, 3 };

	// a.assign(0, 'c');
	// b.assign(0, 'c');
	// ft::vector<char>::iterator it;
	// std::vector<char>::const_iterator it1;

	// it1 = a.begin();
	// it = b.begin();

	// std::cout << a.size() <<" "<< a.capacity() << std::endl;
	// std::cout << b.size() << " " << b.capacity()<< std::endl;

	a.assign(64, 'A');
	b.assign(64, 'A');
	// std::cout << *(42 + it1) << std::endl;
	// std::cout << a.size() <<" "<< a.capacity() << std::endl;
	// std::cout << b.size() << " " << b.capacity()<< std::endl;

	// a.assign(32, '5');
	// b.assign(32, '5');
	// std::cout << a.size() <<" "<< a.capacity() << std::endl;
	// std::cout << b.size() << " " << b.capacity()<< std::endl;

	// a.assign(49, '8');
	// b.assign(49, '8');
	// std::cout << a.size() <<" "<< a.capacity() << std::endl;
	// std::cout << b.size() << " " << b.capacity()<< std::endl;

	// a.assign(77, '2');
	// b.assign(77, '2');
	// std::cout << a.size() <<" "<< a.capacity() << std::endl;
	// std::cout << b.size() << " " << b.capacity()<< std::endl;
	// for (std::size_t i = 0; i < 10000; ++i) {
    //       b.insert(b.begin(), 5, -1);
    //     }
	// b.push_back(1);
	// b.insert(b.begin(), 5, -1);
	// int j = 0;
	// for (ft::vector<int>::iterator i = b.begin(); i != b.end(); i++)
	// {
	// 	std::cout << *i << std::endl;
	// 	j++;
	// }
	// std::cout << j << std::endl;
	
	// std::stack<int> v;
	typedef typename std::iterator_traits<std::vector<int>::iterator>::iterator_category it;
	typedef typename std::iterator_traits<ft::vector<int>::iterator>::iterator_category it1;
	std::cout << std::__are_same<it, std::output_iterator_tag>::__value << std::endl;
	std::cout << std::__are_same<it1, std::output_iterator_tag>::__value << std::endl;
	std::cout << (a.end() - a.begin()) << std::endl;
	std::cout << (b.end() - b.begin()) << std::endl;
}

// size_type len = end() - pos;
				// size_type len2 = pos - begin();
				// if (size() + count > capacity())
				// {
				// 	if (size() + count > capacity() * 2)
				// 		reserve(size() + count);
				// 	else
				// 		reserve(capacity() * 2);
				// }
				// for (size_t i = 0; i < count; i++)
				// {
				// 	this->_allocator_type.construct(this->_finish, value);
				// 	this->_finish++;
				// }
				
				// std::swap_ranges(rbegin(), rbegin() + len, reverse_iterator(pos + count));
				
				
				// // for (size_type i = 0; i < len; i++)
				// // {
				// // 	*(_it + count) = *_it;
				// // 	_it--;
				// // }
				// for (size_t i = 0; i < count; i++, len2++)
				// 	this->_allocator_type.construct((this->_start + len2), value);
				// this->_finish = this->_start + (size() + count);