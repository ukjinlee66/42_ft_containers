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
#define ITERATOR_HPP
typedef int ptrdiff_t;
namespace ft
{
	template<class Category, class T, class Distance = ptrdiff_t,
	class Pointer T*, class Reference = T&>
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
}
#endif
