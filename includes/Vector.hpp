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
	};

    template < class T, class Alloc = std::allocator < T > > class vector
    {
		public:
				typename T value_type;
				typename Alloc allocator_type;
				typedef typename allocator_type::reference			reference;
				typedef typename allocator_type::const_reference	const_reference;
				typedef typename allocator_type::pointer			pointer;
				typedef typename allocator_type::const_pointer		const_pointer;
				//random access iterator
				
				//reverse iterator

				// typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
				typedef typename allocator_type::size_type			size_type;
				//(constructor)
				explicit vector (const allocator_type& alloc = allocator_type());
				explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type());
				template <class InputIterator>
				vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
				vector (const vector& x);
				//(destructor)
				~vector();
				vector& operator= (const vector& x);

				//public member function
				//Capacity
				size_type size() const;
				size_type max_size() const;
				void resize(size_type n, value_type val = value_type());
				size_type capacity() const;
				bool empty() const;
				void reserve (size_type n);
				
				//Element Access
				reference operator[](size_type n);
				const_reference operator[](size_type n) const;
				reference at(size_type n);
				const_reference at(size_type n) const;
				reference front();
				const_reference front() const;
				reference back();
				const_reference back() const;

				//Modifiers
				template <class InputIterator>
				void assign(InputIterator first, InputIterator last);
				void assign(size_type n, const value_type& val);
				void push_back(const value_type& val);
				void pop_back();
				iterator insert(iterator position, const value_type& val);
				void insert(iterator position, size_type n, const value_type& val);
				template <class InputIterator>
				void insert(iterator position, InputIterator first, InputIterator last);
				iterator erase(iterator postion);
				iterator erase(iterator first, iterator last);
				void swap(vector& x);
				void clear();
				allocator_type get_allocator() const;

				//Non-member function overloads
				template <class T, class Alloc>
				bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
				template <class T, class Alloc>
				bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
				template <class T, class Alloc>
				bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
				template <class T, class Alloc>
				bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
				template <class T, class Alloc>
				bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
				template <class T, class Alloc>
				bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
				template <class T, class Alloc>
				void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);
				
    };   
}
# endif
