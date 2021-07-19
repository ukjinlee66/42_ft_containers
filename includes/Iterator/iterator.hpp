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
}
//iterator_traits
namespace ft
{
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
template<class InputIterator> typename iterator_traits<InputIterator>::difference_type
distance (InputIterator first, InputIterator last)
{
	
}

// iterator advance base function overloading
// Input iterator tag
template <class InputIterator, class Distance>
void advance (InputIterator& it, Distance n)
{

}
// Output Iterator tag
template <class OutputIterator, class Distance>
void advance (OutputIterator& it, Distance n)
{

}
// forward Iterator tag
template <class ForwardIterator, class Distance>
void advance (ForwardIterator& it, Distance n)
{

}
// bidirectional iterator tag
template <class BidirectionalIterator, class Distance>
void advance (BidirectionalIterator& it, Distance n)
{

}
// randomaccess iterator tag
template <class RandomaccessIterator, class Distance>
void advance (RandomaccessIterator& it, Distance n)
{

}
// iterator distance base function overloading

};//end namespace
#endif
