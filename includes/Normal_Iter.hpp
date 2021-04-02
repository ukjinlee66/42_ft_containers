/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Normal_Iter.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 15:27:49 by youlee            #+#    #+#             */
/*   Updated: 2021/04/02 15:27:50 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORMAL_ITER_HPP
# define NORMAL_ITER_HPP
#include "Node.hpp"
#include <List>
namespace ft
{
    std::list<int>::iterator vec;
    template<typename Category, typename T>
    struct  IteratorTrait
    {
        typedef T               value_type;
        typedef std::ptrdiff_t  difference_type;
        typedef T*              pointer;
        typedef T&              reference;
        typedef Category        iterator_category;
    };
    template <typename T, typename N>
    class NormalIter : public IteratorTrait<std::bidirectional_iterator_tag, T>
    {
        public:
            typedef IteratorTrait<std::bidirectional_iterator_tag, T>  trait_type;
            typedef trait_type::value_type              value_type; 
            typedef trait_type::difference_type         difference_type;
            typedef trait_type::pointer                 pointer;
            typedef trait_type::pointer const *         const_pointer;
            typedef trait_type::reference               reference;
            typedef trait_type::reference const &       const_reference;
            typedef N                                   node_type;
            typedef node_type*                          node_pointer;
        protected:
            node_pointer                                p;
        public:
            NormalIter() : cur(NULL){}
            NormalIter(NormalIter const *no) : cur(no->cur) {}
            T &operator*()
            {
                return (cur->val);
            }
            bool operator==(const NormalIter &no)
            {
                return (cur == no.cur);
            }
            bool operator!=(const NormalIter &no)
            {
                return (cur != no.cur);
            }
            virtual ~NormalIter(){}
            
    };
}

#endif