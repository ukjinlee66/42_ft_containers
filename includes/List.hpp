/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:49:05 by youlee            #+#    #+#             */
/*   Updated: 2021/03/31 17:49:06 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Normal_Iter.hpp"
#include "Node.hpp"

namespace ft
{
    template <typename T>
    class List
    {
        public:
            typedef std::ptrdiff_t differece_type
            typedef T value_type;
            typedef Node<value_type> node_type;
            typedef node_type* node_pointer;
            typedef value_type* pointer;
            typedef value_type const *const_pointer;
            typedef value_type& reference;
            typedef value_type const &const_reference;
            typedef NormalIter<value_type, node_type> iterator;
            typedef NormalIter<value_type const, node_type const> const_iterator;
            typedef ReverseNormalIter<iterator> reverse_iterator;
            typedef ReverseNormalIter<const_iterator> const_reverse_iterator;
        private:
            node_pointer n_begin;
            node_pointer n_end;
            unsigned long size_type;
            void make_tail()
            {
                this->n_end = new Node<value_type>();
                this->reset_tail();
            }
            void reset_tail()
            {
                this->n_begin = this->n_end;
                this->n_end->prev = NULL;
                this->n_end->next = NULL;
            }
        public:
            List() : n_begin(NULL), n_end(NULL), size_type(0)
            {
                this->make_tail();
            }
            List(unsigned long n, const_reference val=value_type()):n_begin(NULL), n_end(NULL), size_type(0)
            {
                this->make_tail();
                this->assign(n, val);
            }
            
            //general function
            bool empty(void) const
            {
                return (this->size_type == 0);
            }
            unsigned long size(void) const
            {
                return (this->size_type);
            }
            reference front()
            {
                return (this->n_begin->val);
            }
            const_reference front() const
            {
                return (this->n_begin->val);
            }
            reference back()
            {
                return (this->n_end->prev->val);
            }
            const_reference back() const
            {
                return (this->n_end->prev->val);
            }
            void assign(iterator first, iterator last)
            {
                this->clear();
                while (first != last)
                    this->push_back(*first++);
            }
            void assign(const_iterator  first, const_iterator last)
            {
                this->clear();
                while (first != last)
                    this->push_back(*first++);
            }
            void assign(unsigned long size, const_reference val)
            {
                this->clear();
                for (unsigned long i = 0; i < size; i++)
                    this->push_back(val);
            }
            
    };
}
