#include <vector>
#include <iterator>
#include <iostream>
#include "vector/vector.hpp"
// #include "utils/random_access_iterator.hpp"

int main()
{
	std::vector<char> a;
	ft::vector<char> b;
	int c[] = { 1, 2, 3 };

	a.assign(0, 'c');
	b.assign(0, 'c');
	ft::vector<char>::iterator it;
	std::vector<char>::const_iterator it1;

	it1 = a.begin();
	it = b.begin();
	std::cout << a.size() <<" "<< a.capacity() << std::endl;
	std::cout << b.size() << " " << b.capacity()<< std::endl;

	a.assign(64, 'A');
	b.assign(64, 'A');
	std::cout << a.size() <<" "<< a.capacity() << std::endl;
	std::cout << b.size() << " " << b.capacity()<< std::endl;

	a.assign(32, '5');
	b.assign(32, '5');
	std::cout << a.size() <<" "<< a.capacity() << std::endl;
	std::cout << b.size() << " " << b.capacity()<< std::endl;

	a.assign(49, '8');
	b.assign(49, '8');
	std::cout << a.size() <<" "<< a.capacity() << std::endl;
	std::cout << b.size() << " " << b.capacity()<< std::endl;

	a.assign(77, '2');
	b.assign(77, '2');
	std::cout << a.size() <<" "<< a.capacity() << std::endl;
	std::cout << b.size() << " " << b.capacity()<< std::endl;

}