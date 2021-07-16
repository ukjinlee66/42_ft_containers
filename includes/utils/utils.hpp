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
	pair() : first(), second()
	//copy
	template<class U, class V> 
	pair (const pair<U,V>& pr) : first(pr.first) , second(pr.second){}
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