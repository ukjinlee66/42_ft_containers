/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 22:24:57 by youlee            #+#    #+#             */
/*   Updated: 2021/07/16 22:24:58 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef UTILS_HPP
#define UTILS_HPP
namespace ft
{
	template < class T1, class T2>
	struct pair
	{
		// member type
		typedef T1	first_type;
		typedef T2	second_type;

		// member variable
		first_type first;
		second_type second;
		//default constructor
		pair() : first(), second() {}
		//copy
		template < class U, class V >
		pair (const pair<U,V>& pr) : first(pr.first) , second(pr.second) {}
		//init
		pair (const first_type& a, const second_type& b) : first(a), second(b){}

		// implicitly declared:
		pair& operator= (const pair& pr)
		{
			if (this == &pr)
				return (*this);
			this->first = pr.first;
			this->second = pr.second;
		}
	};
// relational operators (pair)
template <class T1, class T2>
bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{	return (lhs.first == rhs.first && lhs.second == rhs.second);	}

template <class T1, class T2>
bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{	return !(lhs==rhs);	}

template <class T1, class T2>
bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{	return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second);	}

template <class T1, class T2>
bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{	return !(rhs<lhs);	}

template <class T1, class T2>
bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{	return rhs<lhs;	}

template <class T1, class T2>
bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{	return !(lhs<rhs);	}

//function template make_pair
template <class T1,class T2>
pair<T1,T2> make_pair (T1 x, T2 y)
{
	return ( pair<T1,T2>(x,y) );
}

//enable_if
template<bool Cond, class T = void> struct enable_if {};
template<class T> struct enable_if<true, T> { typedef T type; };

//is_integral
template <class T> struct is_integral
{
	bool	value_type;

};

//lexicographical compare
//default
template <class InputIterator1, class InputIterator2>
bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
{
	while (first1!=last1)
	{
		if (first2==last2 || *first2<*first1) return false;
		else if (*first1<*first2) return true;
		++first1; ++first2;
	}
	return (first2!=last2);
}
//custom
template <class InputIterator1, class InputIterator2, class Compare>
bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2,
Compare comp)
{
	while (first1!=last1)
	{
		if (first2==last2 || comp(*first2, *first1)) return false;
		else if (comp(*first1, *first2)) return true;
		++first1; ++first2;
	}
	return (first2!=last2);
}
//equal
//equality
template <class InputIterator1, class InputIterator2>
bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
{
	while (first1!=last1) 
	{
		if (!(*first1 == *first2))
			return (false);
		++first1; ++first2;
	}
	return (true);
}
//predicate
template <class InputIterator1, class InputIterator2, class BinaryPredicate>
bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
{
	while (first1!=last1) 
	{
		if (!pred(*first1, *first2))
			return (false);
		++first1; ++first2;
	}
	return (true);
}
} // end namespace
#endif