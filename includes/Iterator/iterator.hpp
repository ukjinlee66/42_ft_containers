/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 18:03:10 by youlee            #+#    #+#             */
/*   Updated: 2021/07/07 18:03:36 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP
typedef int ptrdiff_t;
namespace ft
{
	template<class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T& >
	class iterator
	{
		public:
				typedef typename Distance						difference_type;
				typedef typename T								value_type;
				typedef typename T*								pointer;
				typedef typename T&								reference;
				typedef typename Category						iterator_category;
	};
	//iterator_traits
	template <class iterator> 
	class iterator_traits
	{
		public:
				typedef typename iterator::difference_type		difference_type;
				typedef typename iterator::value_type			value_type;
				typedef typename iterator::pointer				pointer;
				typedef typename iterator::reference			reference;
				typedef typename iterator::iterator_category	iterator_category;
	};
	template <class T> class iterator_traits<T*>
	{
		public:
				typedef typename ptrdiff_t						difference_type;
				typedef typename T								value_type;
				typedef typename T*								pointer;
				typedef typename T&								reference;
				typedef typename random_access_iterator_tag		iterator_category;

	};
	template <class T> class iterator_traits<const T*>
	{
		public:
				typedef typename ptrdiff_t						difference_type;
				typedef typename T								value_type;
				typedef typename const T*						pointer;
				typedef typename const T&						reference;
				typedef typename random_access_iterator_tag		iterator_category;
	};
	struct input_iterator_tag
	{      
	// identifying tag for input iterators
	};
	
	struct output_iterator_tag
	{      
	// identifying tag for output iterators
	};
	
	struct forward_iterator_tag
		: public input_iterator_tag, output_iterator_tag
	{      
	// identifying tag for forward iterators
	};
	
	struct bidirectional_iterator_tag
		: public forward_iterator_tag
	{      
	// identifying tag for bidirectional iterators
	};
	
	struct random_access_iterator_tag
		: public bidirectional_iterator_tag
	{      
	// identifying tag for random-access iterators
	};

	// iterator distance base function overloading

	/*
	*	Calculates the number of elements between first and last.
	*	If it is a random-access iterator, the function uses operator- to calculate this.
	*	Otherwise, the function uses the increase operator (operator++) repeatedly.
	*/

	// randomaccess iterator
	template<class RandomaccessIterator> typename iterator_traits<RandomaccessIterator>::difference_type
	distance (RandomaccessIterator first, RandomaccessIterator last, random_access_iterator_tag)
	{
		return (last - first);
	}

	// Nonrandomaccess iterator
	template<class NonRandomaccessIterator> typename iterator_traits<NonRandomaccessIterator>::difference_type
	distance (NonRandomaccessIterator first, NonRandomaccessIterator last, input_iterator_tag)
	{
		iterator_traits<NonRandomaccessIterator>::difference_type dist = 0;
		for(;first!=last;first++)
			dist++;
		return (dist);
	}

	// default distance method
	template<class InputIterator> typename iterator_traits<InputIterator>::difference_type
	distance (InputIterator first, InputIterator last)
	{
		return distance(first, last, iterator_traits<InputIterator>::iterator_category());	
	}

	// iterator advance base function overloading

	/*
	*	Advances the iterator it by n element positions.
	*	If it is a random-access iterator, the function uses just once operator+ or operator-. 
	*	Otherwise, the function uses repeatedly the increase or decrease operator 
	*	(operator++ or operator--) until n elements have been advanced.
	*/

	// randomaccess iterator
	template <class RandomaccessIterator, class Distance>
	void advance (RandomaccessIterator& it, Distance n, random_access_iterator_tag)
	{
		it += n;
	}

	// non randomaccess iterator tag
	template <class NonRandomaccessIterator, class Distance>
	void advance (NonRandomaccessIterator& it, Distance n, input_iterator_tag)
	{
		for (ptrdiff_t i = 0; i < n; i++)
			++it;
	}

	//default advance method
	template <class InputIterator, class Distance>
	void advance (InputIterator& it, Distance n)
	{
		return advance(it, n, typename iterator_traits<InputIterator>::iterator_category());
	}

	// reverse iterator
	template <class Iterator> class reverse_iterator
	{
		private:
				// iterator variable
				Iterator ite;
				//default Constructs
				reverse_iterator();
		public:
				// Member type
				typedef Iterator iterator_type;
				typedef iterator_traits<Iterator>::iterator_category iterator_category;
				typedef iterator_traits<Iterator>::value_type value_type;
				typedef iterator_traits<Iterator>::difference_type difference_type;
				typedef iterator_traits<Iterator>::pointer pointer;
				typedef iterator_traits<Iterator>::reference reference;

				// Member functions
				//initialization
				explicit reverse_iterator (iterator_type it) : ite(it) {}
				//copy
				template <class Iter> reverse_iterator (const reverse_iterator<Iter>& rev_it) : ite(rev_it.ite) {}
				//default Deconstructor
				~reverse_iterator();

				Iterator base() const
				{
					return (ite);
				}

				// Operator
				reference operator*() const
				{
					Iterator it(this->ite);
					return (*(--it));
				}
				reverse_iterator operator+ (difference_type n) const
				{
					--this->ite;
					this->ite -= n;
					return (*this);
				}
				reverse_iterator& operator++()
				{
					--this->ite;
					return (*this);
				}
				reverse_iterator  operator++(int)
				{
					reverse_iterator it(this->ite--);
					return (it);
				}
				reverse_iterator operator- (difference_type n) const
				{
					++this->ite;
					this->ite += n;
					return (*this);
				}
				reverse_iterator& operator--()
				{
					++this->ite;
					return (*this);
				}
				reverse_iterator  operator--(int)
				{
					reverse_iterator it(this->ite++);
					return (it);
				}
				reverse_iterator& operator+= (difference_type n)
				{
					this->ite -= n;
					return (*this);
				}
				reverse_iterator& operator-= (difference_type n)
				{
					this->ite += n;
					return (*this);
				}
				pointer operator->() const
				{
					Iterator it(this->ite);
					--it;
					return (it.operator->());
				}
				reference operator[] (difference_type n) const
				{
					Iterator it(this->ite);
					--it;
					return (*it);
				}
	};
	//Non-member function overloads
	template <class Iterator>
	bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() == rhs.base());
	}
	template <class Iterator>
	bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() != rhs.base());
	}
	template <class Iterator>
	bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() > rhs.base());
	}
	template <class Iterator>
	bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() >= rhs.base());
	}
	template <class Iterator>
	bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() < rhs.base());
	}
	template <class Iterator>
	bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() <= rhs.base());
	}
	template <class Iterator>
	reverse_iterator<Iterator> operator+ ( typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
	{
		reverse_iterator<Iterator> rit(rev_it.base() - n);
		return (rit);
	}
	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator- ( const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (rhs.base() - lhs.base());
	}
}//end namespace
#endif
