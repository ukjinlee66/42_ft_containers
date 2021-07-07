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
namespace ft
{
	template<class Category, class T, class Distance = ptrdiff_t,
	class Pointer T*, class Reference = T&>
	class iterator
	{
		public:
				typedef typename Distance	difference_type;
				typedef typename T			value_type;
				typedef typename T*			pointer;
				typedef typename T&			reference;
				typedef typename Category	iterator_category;
	};
}
//iterator_traits
namespace ft
{

}
#endif
