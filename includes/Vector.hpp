/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:49:11 by youlee            #+#    #+#             */
/*   Updated: 2021/07/25 20:38:24 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <memory>
# include "Iterator/iterator.hpp"
# include "utils/utils.hpp"

namespace ft
{
	//Random Access iterator
	template <typename T>
	class vector_iterator
	{
		public:
				//Member type
				typedef size_t size_type;
				typedef ptrdiff_t difference_type;
				typedef ft::random_access_iterator_tag iterator_category;
				typedef T value_type;
				typedef T* pointer;
				typedef T& reference;
		private:
				typedef vector_iterator<T> it;
				pointer po;
		public:
				//canonical form
				vector_iterator() : po(NULL) {}
				vector_iterator(const &it) : po(it.po) {}
				~vector_iterator() {}
				vector_iterator(pointer p) : po(p) {}
				it &operator=(const it &in_it)
				{
					po = in_it.po;
					return (*this);
				}
				bool operator==(const it &rhs)
				{
					return (po == rhs.po);
				}
				bool operator!=(const it &rhs)
				{
					return (po != rhs.po);
				}
				reference operator*() const
				{
					return (*po);
				}
				pointer operator->() const
				{
					return (po);
				}
				// incremented
				it &operator++()
				{
					++po;
					return (*this);
				}
				it operator++(int)
				{
					it iter = *this;
					++iter;
					return (iter);
				}
				// decrement
				it &operator--()
				{
					--po;
					return (*this);
				}
				it operator--(int)
				{
					it iter = *this;
					--iter;
					return (iter);
				}
				it &operator+=(size_type off)
				{
					po += off;
					return (*this);
				}
				it &operator-=(size_type off)
				{
					po -= off;
					return (*this);
				}
				reference operator[](difference_type ite) const
				{
					return (*(*this + ite));
				}
				it operator+(size_type off)
				{
					it temp(*this);
					return (temp += off);
				}
				it operator-(size_type off)
				{
					it temp(*this);
					return (temp -= off);
				}
				bool operator<(it const &other) const
				{
					return (this->po < other.po);
				}
				bool operator<=(it const &other) const
				{
					return (this->po <= other.po);
				}
				bool operator>(it const &other) const
				{
					return (this->po > other.po);
				}
				bool operator>=(it const &other) const
				{
					return (this->po >= other.po);
				}
				bool operator==(it const &other) const
				{
					return (this->po == other.po);
				}
				bool operator!=(it const &other) const
				{
					return (this->po != other.po);
				}
	};

    template < class T, class Alloc = std::allocator < T > > class vector
    {
		public:
				typedef T value_type;
				typedef Alloc allocator_type;
				typedef value_type&			reference;
				typedef const value_type&	const_reference;
				typedef value_type*			pointer;
				typedef const value_type*	const_pointer;
				typedef size_t size_type;
				typedef ptrdiff_t difference_type;
		private:
				typedef vector<T> container;

				pointer array;
				size_type _size;
				size_type _len;
		public:
				//random access vector iterator
				typedef vector_iterator<T> iterator;
				typedef vector_iterator<const T> const_iterator;

				//reverse iterator
				typedef ft::reverse_iterator<T> reverse_iterator;
				typedef ft::reverse_iterator<const T> const_reverse_iterator;

				// typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
				typedef typename allocator_type::size_type			size_type;
				//(constructor)
				explicit vector (const allocator_type& alloc = allocator_type()) : array(NULL), _size(0), _len(0)
				{
					this -> allocator_type = alloc;
				}
				explicit vector (size_type n, const value_type& val = value_type(),
                const allocator_type& alloc = allocator_type()) : array(NULL), _size(0), _len(0)
				{
					this -> allocator_type = alloc;
					insert(begin(), n, val);
				}
				template <class InputIterator>
				vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
				{
					this -> allocator_type = alloc;
					insert(begin(), first, last);
				}
				vector (const vector& x) : array(NULL), _size(0), _len(0)
				{
					this -> allocator_type = x.get_allocator();
					insert(begin(), x.begin(), x.end());
					return (*this);
				}
				//(destructor)
				~vector()
				{
					std::allocator<T> all;
					for(size_type i = 0; i < _len; i++)
						all.destroy(&array[i]);
					all.deallocate(array, _len);
				}
				container& operator= (const vector& x) : array(NULL), _size(0), _len(0)
				{
					clear();
					this -> allocator_type = x.get_allocator();
					insert(begin(), x.begin(), x.end());
				}
				vector_iterator begin()
				{
					return (array);
				}
				const_iterator begin() const
				{
					return (array);
				}
				iterator end()
				{
					return (array + _len);
				}
				const_iterator end() const
				{
					return (array + _len);
				}
				reverse_iterator rbegin()
				{
					return (reverse_iterator<vector_iterator<T> >(end()));
				}
				const_reverse_iterator rbegin() const
				{
					return (reverse_iterator<vector_iterator<T> >(end()));
				}
				reverse_iterator rend()
				{
					return (reverse_iterator<vector_iterator<T> >(begin()));
				}
				const_reverse_iterator rend() const
				{
					return (reverse_iterator<vector_iterator<T> >(begin()));
				}

				//public member function
				//Capacity
				size_type size() const
				{
					return (_size);
				}
				size_type max_size() const
				{
					return (std::numeric_limits<difference_type>::max() / sizeof(T));
				}
				void resize (size_type n, value_type val = value_type())
				{
					if (n >= _len)
						insert(end(), n - _len, val);
					else
						erase(begin() + n, end());
				}
				size_type capacity() const
				{
					return (this->_size);
				}
				bool empty() const
				{
					return (this->_len == 0);
				}
				//Requests that the vector capacity be at least enough to contain n elements.
				void reserve (size_type n)
				{
					//If n is greater than the current vector capacity, the function causes the container to reallocate
					//its storage increasing its capacity to n (or greater).
					if (n > this->_size)
					{
						std::allocate<T> alloc;
						T* val = alloc.allocate(n);
						for (size_type i = 0;i<_len;i++)
						{
							alloc.construct((&val[i], array[i])); // copy current array.
							alloc.destroy(&array[i]); // delete current array.
						}
						alloc.deallocate(array, _size);
						array = val; // copy new array.
						_size = n; // copy new array capacity.
					}
					else if(!n || n <= this->_size)
					{
						//In all other cases, 
						//the function call does not cause a reallocation and the vector
						//capacity is not affected.
						return ;
					}
				}
				//Element Access
				reference operator[](size_type n)
				{
					return (array[n]);
				}
				const_reference operator[](size_type n) const
				{
					return (array[n]);
				}
				reference at(size_type n)
				{
					if (n >= size())
					{
						std::stringstream ss;
						ss << "index " << n << "out of bound (size() is " << size() <<")";
						throw std::out_of_range(ss.str()); 
					}
					return (array[pos]);
				}
				const_reference at(size_type n) const
				{
					if (n >= size())
					{
						std::stringstream ss;
						ss << "index " << n << "out of bound (size() is " << size() <<")";
						throw std::out_of_range(ss.str()); 
					}
					return (array[pos]);
				}
				reference front()
				{
					return (array[0]);
				}
				const_reference front() const
				{
					return (array[0]);
				}
				reference back()
				{
					return (array[_len - 1]);	
				}
				const_reference back() const
				{
					return (array[_len - 1]);
				}
				//Modifiers
				template <class InputIterator>
				void assign(InputIterator first, InputIterator last)
				{
					clear();
					insert(begin(), first, last);
				}
				void assign(size_type n, const value_type& val)
				{
					clear();
					insert(begin(), n, val);
				}
				void push_back(const value_type& val)
				{
					insert(end(), val);
				}
				void pop_back()
				{
					erase(end() - 1);
				}
				iterator insert(iterator position, const value_type& val)
				{
					insert(position, 1, val);
					return (position);
				}
				void insert(iterator position, size_type n, const value_type& val)
				{
					std::allocator<T> alloc;
					size_type siz = position.po - array;
					if (!n) return;
					reserve(_len + n);
					for (ptrdiff_t i = _len -1;i>=(ptrdiff_t)siz;i--)
					{
						alloc.construct(&array[i + n], array[i]);
						alloc.destroy(&array[i]);
					}
					for (size_type i = siz;i < siz + n; i++)
						alloc.construct(&array[i], val);
					_len += n;
				}
				template <class InputIterator>
				void insert(iterator position, InputIterator first, InputIterator last)
				{
					std::allocator<T> alloc;
					size_type siz = position.po - array;
					size_type dist = distance(first, last);
					if (!dist) return;
					reserve(_len + dist);
					for (ptrdiff_t i = _len -1;i>=(ptrdiff_t)siz;i--)
					{
						alloc.construct(&array[i + dist], array[i]);
						alloc.destroy(&array[i]);
					}
					for (size_type i = siz;i < siz + dist; i++)
						alloc.construct(&array[i], val);
					_len += dist;
				}
				iterator erase(iterator postion)
				{
					return erase(position, position + 1);
				}
				iterator erase(iterator first, iterator last)
				{
					std::allocator<T> alloc;
					size_type dist = last - first;
					size_type idx = first.po - array;
					for (size_type i = idx;i<idx + dist;i++)
						alloc.destroy(&array[i]);
					for (size_type i = idx + dist;i < _len; i++)
					{
						alloc.construct(&array[i - dist], array[i]);
						alloc.destroy(&array[i]);
					}
					_len -= dist;
					return (first);
				}
				void swap(vector& x)
				{
					std::swap(array, x.array);
					std::swap(_len, x._len);
					std::swap(_size, x._size);
				}
				void clear()
				{
					erase(begin(), end());
				}
				allocator_type get_allocator() const
				{

				}
    };
	//Non-member function overloads
	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size()) return false;
		return equal(lhs.begin(),lhs.end(),rhs.begin());
	}
	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (lhs != rhs);
	}
	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (lhs <= rhs);
	}
	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (lhs > rhs);
	}
	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (lhs >= rhs);
	}
	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		y.swap(x);
	}
} // namespace end.
# endif
