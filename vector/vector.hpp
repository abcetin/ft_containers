#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "../utils/utils.h"
#include "../utils/iterator_traits.hpp"
#include "../utils/normal_iterator.hpp"
#include "../utils/enable_if.hpp"
#include "../utils/reverse_iterator.hpp"
#include <iterator>
#include <algorithm>
#include <memory>
#include <limits>

namespace ft
{
    template< class T, class Allocator = std::allocator<T> > class vector
    {
		public:
        	// ------------Member Types---------- //
        	typedef T														value_type; // value type => T
        	typedef Allocator												allocator_type;// allocator_type => Allocator
        	typedef typename std::size_t									size_type;// size_type => Unsigned integer type (usually std::size_t)
        	typedef typename std::ptrdiff_t									difference_type;// difference_type	Signed integer type (usually std::ptrdiff_t)
        	typedef typename allocator_type::reference						reference;// reference	value_type&
        	typedef typename allocator_type::const_reference				const_reference;// const_reference	const value_type&
			typedef	typename allocator_type::pointer						pointer;
			typedef typename allocator_type::const_pointer					const_pointer;
			typedef ft::normal_iterator<pointer, vector>					iterator;
			typedef ft::normal_iterator<const_pointer, vector>				const_iterator;	
			typedef ft::reverse_iterator<iterator>							reverse_iterator;//reverse_iterator	std::reverse_iterator<iterator>
			typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;//const_reverse_iterator	std::reverse_iterator<const_iterator>
		
		protected:
			allocator_type	_allocator_type;
			pointer			_start;
			pointer			_finish;
			pointer			_end_of_capacity;
		
		private:

			template< class randIt >
			void _insert(iterator pos, randIt first, randIt last, std::random_access_iterator_tag)
			{
				if (first == last)
					return;
				size_type len = (last - first);
				size_type oldCap = capacity();
				size_type newCap = !oldCap ? len : size() + len;
				pointer newData = this->_allocator_type.allocate(newCap);
				pointer newEnd = newData;
				for(iterator it = begin(); it != pos; it++, newEnd++)
						this->_allocator_type.construct(newEnd, *it);
				for(; first != last; first++, newEnd++)
					this->_allocator_type.construct(newEnd, *first);
				for(iterator it = pos; it != end(); it++, newEnd++)
					this->_allocator_type.construct(newEnd, *it);
				if (oldCap)
				{
					clear();
					this->_allocator_type.deallocate(this->_start, oldCap);
				}
				this->_start = newData;
				this->_finish = newEnd;
				this->_end_of_capacity = this->_start + newCap;
			}
			template< class InputIt >
			void _insert(iterator pos, InputIt first, InputIt last, std::input_iterator_tag)
			{
				for(; first != last; first++, pos++)
					pos = insert(pos, *first);
			}

			iterator move(iterator first, iterator last, iterator result)
			{
				for(; first != last; ++result, ++first)
					*result = *first;
				return result;
			}

		public:
			vector() 
			{
				this->_start = 0;
				this->_finish = 0;
				this->_end_of_capacity = 0;
			}

        	explicit vector(const allocator_type& alloc): _allocator_type(alloc), _start(0), _finish(0), _end_of_capacity(0){};//

            explicit vector(size_type count, const T& value = T(), const Allocator& alloc = Allocator()): 
			_allocator_type(alloc), _start(0), _finish(0), _end_of_capacity(0) //
			{
				size_type i = 0;

				if (count > max_size())
					throw std::length_error("Length Error");
				if (count)
				{
					this->_start = this->_allocator_type.allocate(count);
					this->_finish = this->_start;
					this->_end_of_capacity = this->_start + count;
					while(i < count)
					{
						this->_allocator_type.construct(this->_finish, value);
						this->_finish++;
						i++;
					}
				}
			}

            vector( const vector& other ) : _allocator_type(other.get_allocator()) 
			{
				this->_start = this->_allocator_type.allocate(other.capacity());
				this->_finish = this->_start;
				this->_end_of_capacity = this->_start + other.capacity();
				for (size_t i = 0; i < other.size(); i++)
				{
					this->_allocator_type.construct(this->_finish, other[i]);
					this->_finish++;
				}
			}
			
			template<typename InputIt> vector(InputIt first, InputIt last, const Allocator& alloc = Allocator(), typename ft::enable_if<!is_integral<InputIt>::value, bool>::type = true) :
			_allocator_type(alloc), _start(0), _finish(0), _end_of_capacity(0)
			{
				assign(first, last);
			}

            ~vector()
			{
				if (capacity())
				{
					clear();
					this->_allocator_type.deallocate(this->_start, capacity());
				}
			}

            vector& operator=(const vector& other)
			{
				if (this != &other)
				{
					const size_type len = other.size();
					if (len > capacity())
					{
						pointer temp_start = this->_allocator_type.allocate(len);
						pointer temp_finish = temp_start;
						for (size_t i = 0; i < other.size(); i++)
						{
							this->_allocator_type.construct(temp_finish, other[i]);
							temp_finish++;
						}
						clear();
						if (capacity())
							this->_allocator_type.deallocate(this->_start, capacity());
						this->_start = temp_start;
						this->_finish = temp_finish;
						this->_end_of_capacity = this->_start + len;
					}
					else if (size() > len)
					{
						clear();
						assign(other.begin(), other.end());
					}
					else if (capacity())
						assign(other.begin(), other.end());
				}
				return(*this);
			}

            void assign( size_type count, const T& value )
			{
				clear();
				if (count > capacity())
				{
					if (capacity())
						this->_allocator_type.deallocate(this->_start, this->capacity());
					this->_start = this->_allocator_type.allocate(count);
					this->_finish = _start;
					this->_end_of_capacity = this->_start + count; 
				}
				for (size_t i = 0; i < count; i++)
				{
					this->_allocator_type.construct(this->_finish, value);
					this->_finish++;
				}
				
			}

            template< class InputIterator > void assign( InputIterator first, InputIterator last, typename ft::enable_if<!is_integral<InputIterator>::value, bool>::type = true)
			{
				typedef typename std::iterator_traits<InputIterator>::iterator_category iter;
				if (ft::__are_same<iter, std::random_access_iterator_tag>::__value)
				{
					difference_type _len = std::distance(first, last);
					clear();
					if (_len > (difference_type)capacity())
					{
						if (capacity())
							this->_allocator_type.deallocate(this->_start, capacity());
						this->_start = this->_allocator_type.allocate(_len);
						this->_finish = this->_start;
						this->_end_of_capacity = this->_start + _len;
					}
					while(first != last)
					{
						this->_allocator_type.construct(this->_finish, *first);
						first++;
						this->_finish++;
					}	
				}
				else
				{
					iterator pos(begin());

					while ((pos != end()) && (first != last))
					{
						*pos = *first;
						++first;
						++pos;
					}
					if (first == last)
						erase(pos, end());
					else
						insert(end(), first, last);
				}
			}

            allocator_type get_allocator() const{ return this->_allocator_type;}

            reference at( size_type pos )
			{
				if (pos >= size())
					throw(std::out_of_range("vector::out_of_range"));
				return reference(this->_start[pos]);
			}
            const_reference at( size_type pos ) const
			{
				if (pos >= size())
					throw(std::out_of_range("vector::out_of_range"));
				return const_reference(this->_start[pos]);
			}

            reference operator[]( size_type pos ){return reference(this->_start[pos]);}

            const_reference operator[]( size_type pos ) const {return const_reference(this->_start[pos]);}

            reference front(){return *begin();}

            const_reference front() const{return *begin();}

			reverse_iterator rbegin() {return reverse_iterator(end());}

			const_reverse_iterator	rbegin() const {return const_reverse_iterator(end());}

			reverse_iterator rend() {return reverse_iterator(begin());}

			const_reverse_iterator rend() const {return const_reverse_iterator(begin());}

            reference back(){return *(end() - 1);}
            const_reference back() const{return *(end() - 1);}

            T* data(){return pointer(this->_start);}
            const T* data() const{return const_pointer(this->_start);}

			iterator begin(){return iterator(this->_start);}
			const_iterator begin() const {return const_iterator(this->_start);}

			iterator end(){return iterator(this->_finish);}
			
			const_iterator end() const{return const_iterator(this->_finish);}

            bool empty() const {return begin() == end();}

            size_type size() const {return size_type(this->_finish - this->_start);}

            size_type max_size() const{return std::min<size_type>(this->_allocator_type.max_size(), std::numeric_limits<difference_type>::max());}

            void reserve( size_type new_cap )
			{
				if (new_cap > max_size())
					throw std::length_error("vector::reserve");
				if (new_cap > capacity())
				{
					if (this->_start)
					{
						pointer temp = _allocator_type.allocate(new_cap);
						size_type _size = size();
						for (size_t i = 0; i < _size; i++)
						{
							this->_allocator_type.construct(temp + i, this->_start[i]);
							this->_allocator_type.destroy(this->_start + i);
						}
						if (capacity())
							this->_allocator_type.deallocate(this->_start, capacity());
						this->_start = temp;
						this->_finish = this->_start + _size;
						this->_end_of_capacity = this->_start + new_cap;
					}
					else
					{
						this->_start = this->_allocator_type.allocate(new_cap);
						this->_finish = this->_start;
						this->_end_of_capacity = this->_start + new_cap;
					}
				}
			}

            size_type capacity() const {return size_type(this->_end_of_capacity - this->_start);}

            void clear()
			{
				for (size_t i = 0; i < size(); i++)
					this->_allocator_type.destroy(&this->_start[i]);
				this->_finish = this->_start;
			}

            iterator insert(iterator pos, const T& _value)
			{
				size_type _new_pos = size_type(pos - begin());
				if (this->_finish != this->_end_of_capacity && pos == end())
					this->_allocator_type.construct(this->_finish++, _value);
				else if (size() + 1 < capacity())
				{
					size_type _pos = (end() - pos);
					this->_allocator_type.construct(this->_finish++, _value);
					std::swap_ranges(rbegin(), rbegin() + _pos, rbegin() + 1);
				}
				else
				{
					size_type oldCap = capacity();
					size_type newSize = size() ? oldCap * 2 : 1;
					pointer newData = this->_allocator_type.allocate(newSize);
					pointer newEnd = newData;

					for(iterator it = begin(); it != pos; it++, newEnd++)
						this->_allocator_type.construct(newEnd, *it);
					this->_allocator_type.construct(newEnd++, _value);
					for(iterator it = pos; it != end(); it++, newEnd++)
						this->_allocator_type.construct(newEnd, *it);
					if (oldCap)
					{
						clear();
						this->_allocator_type.deallocate(this->_start, oldCap);
					}
					this->_start = newData;
					this->_finish = newEnd;
					this->_end_of_capacity = this->_start + newSize;
				}
				return iterator(this->_start + _new_pos);
			}

			iterator insert(iterator pos, size_type count, const T& value )
			{
				size_type _new_pos = size_type(pos - begin());
				size_type len = end() - pos;
				if (count > max_size())
					throw std::length_error("Length Error");
				if (count == 0)
					return pos;
				if (size() + count > capacity())
				{
					if (size() + count > capacity() * 2)
						reserve(size() + count);
					else
						reserve(capacity() * 2);
				}
				for (size_type i = 0; i < count; i++)
				{
					this->_allocator_type.construct(this->_finish, value);
					this->_finish++;
				}
				std::swap_ranges(rbegin(), rbegin() + len, rbegin() + count);
				return iterator(this->_start + _new_pos);
			}

            template< class InputIt >
			iterator insert(iterator pos, InputIt first, InputIt last,
			typename ft::enable_if<!is_integral<InputIt>::value, bool>::type = true)
			{
			 	typedef typename std::iterator_traits<InputIt>::iterator_category iter;
				_insert(pos, first, last, iter());
				return pos;
			}
			
            iterator erase( iterator pos ) 
			{
				if (pos + 1 != end())
					move(pos + 1, end(), pos);
				this->_finish--;
				this->_allocator_type.destroy(this->_finish);
				return(pos);
			}

            iterator erase(iterator first, iterator last) 
			{
				if (first != last)
				{
					size_type len = (last - first);
					if (last != end())
						move(last, end(), first);
					for (size_type i = 0; i < len; i++)
						pop_back();
				}
				return (first);
			}

            void push_back( const T& value ) 
			{
				if (this->_finish != this->_end_of_capacity)
				{
					this->_allocator_type.construct(this->_finish, value);
					this->_finish++;
				}
				else if (capacity() && this->_finish == this->_end_of_capacity)
				{
					reserve(capacity() * 2);
					push_back(value);
				}
				else
					insert(end(), value);
			}

            void pop_back()
			{
				--this->_finish;
				this->_allocator_type.destroy(this->_finish);
			}

            void resize( size_type count, T value = T()) 
			{
				size_type _end = size();
				if (count > _end)
					insert(end(), count - _end, value);
				else
				{
					while(count < _end)
					{
						this->_allocator_type.destroy(this->_start + count);
						this->_finish--;
						count++;
					}
				}
			}

            void swap( vector& other )
			{
				std::swap(this->_start, other._start);
				std::swap(this->_finish, other._finish);
				std::swap(this->_end_of_capacity, other._end_of_capacity);
			}
    };

	//----------------------------No Member Func-------------------------------//
	template< class T, class Alloc >bool operator==( const ft::vector<T,Alloc>& lhs,const ft::vector<T,Alloc>& rhs )
	{
		return(lhs.size() == rhs.size() && (ft::equal(lhs.begin(), lhs.end(), rhs.begin())));
	}
	
	template< class T, class Alloc >bool operator!=( const ft::vector<T,Alloc>& lhs,const ft::vector<T,Alloc>& rhs )
	{
		return (!(lhs == rhs));
	}

	template< class T, class Alloc > bool operator<( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template< class T, class Alloc > bool operator<=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
	{
		return !(rhs < lhs);
	}

	template< class T, class Alloc > bool operator>( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
	{
		return (rhs < lhs);
	}

	template< class T, class Alloc > bool operator>=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
	{
		return (!(lhs < rhs));
	}

	template< class T, class Alloc > void swap( ft::vector<T,Alloc>& lhs, ft::vector<T,Alloc>& rhs )
	{
		lhs.swap(rhs);
	}
}

#endif