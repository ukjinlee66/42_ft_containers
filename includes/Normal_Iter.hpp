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
            node_pointer                                cur;
        public:
            NormalIter() : cur(NULL){}
            NormalIter(NormalIter const &no) : cur(no.cur) {}
            NormalIter(node_pointer p) : cur(p) {}
            virtual ~NormalIter() {}

            node_pointer &ptr()
            {
                return (this->cur);
            }
            node_pointer get_node() const
            {
                return (this->cur);
            }
            reference operator*()
            {
                return (this->cur->val);
            }
            const_reference operator*()
            {
                return (this->cur->val);
            }
            pointer operator->()
            {
                return (&this->cur->val);
            }
            const_pointer operator->() const
            {
                return (&this->cur->val);
            }
            NormalIter &operator++()
            {
                this->cur = this->cur->next;
                return (*this);
            }
            NormalIter operator++(int)
            {
                NormalIter temp(*this);
                this->cur = this->cur->next;
                return (temp);
            }
            NormalIter &operator--()
            {
                this->cur = this->cur->prev;
                return (*this);
            }
            NormalIter operator--(int)
            {
                NormalIter temp(*this);
                this->cur = this->cur->prev;
                return (temp);
            }
            NormalIter &operator+=(int val)
            {
                if (val > 0)
                {
                    for(int i=0;i<val;i++)
                        this->cur = this->cur->next;
                }
                else
                {
                    for(int i= val;i>0;i--)
                        this->cur = this->cur->prev;
                }
            }
            NormalIter operator+(int val) const
            {
                NormalIter temp(*this);
                return (temp += val);
            }
            NormalIter &operator-=(int val)
            {
                operator+=(-val);
                return (*this);
            }
            NormalIter operator-(int val) const
            {
                NormalIter temp(*this);
                return (temp -= val);
            }
            bool operator==(NormalIter const &no)
            {
                return (this->cur == no.cur);
            }
            bool operator!=(NormalIter const &no)
            {
                return (this->cur != no.cur);
            }
            bool operator<(NormalIter const &no)
            {
                return (this->cur < no.cur);
            }
            bool operator<=(NormalIter const &no)
            {
                return (this->cur <= no.cur);
            }
            bool operator>(NormalIter const &no)
            {
                return (this->cur > no.cur);
            }
            bool operator>=(NormalIter const &no)
            {
                return (this->cur >= no.cur);
            }
            
    };
    template <typename It>
    class ReverseNormalIter : public It
    {
        public:
            using typename it::value_type;
            using typename It::pointer;
            using typename It::const_pointer;
            using typename It::reference;
            using typename It::const_reference;
            using typename It::difference_type;
        public:
            ReverseNormalIter(): It() {}
            ReverseNormalIter(It const &it) : It(it) {}
            ReverseNormalIter(ReverseNormalIter const &re) : It(re.p) {}
            ReverseNormalIter &operator=(ReverseNormalIter const &re)
            {
                this->p = re.p;
                return (*this);
            }
            ReverseNormalIter operator*()
            {
                It temp(*this);
                return (*--temp);
            }
            const_reference operator*() const
            {
                It temp(*this);
                return (*--temp);
            }
            pointer operator->()
            {
                It temp(*this);
                return (&*--temp);
            }
            const_pointer operator->() const
            {
                It temp(*this);
                return (&*--temp);
            }
            ReverseNormalIter operator++(int)
            {
                ReverseNormalIter temp(*this);
                operator++();
                return (temp);
            }
            It &operator++()
            {
                return (this->It::operator--());
            }
            ReverseNormalIter operator--(int)
            {
                ReverseNormalIter temp(*this);
                operator--();
                return (temp);
            }
            It &operator--()
            {
                return (this->It::operator++());
            }
    };
}
#endif