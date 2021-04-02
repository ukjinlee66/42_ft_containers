/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:33:17 by youlee            #+#    #+#             */
/*   Updated: 2021/04/02 14:33:19 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP
namespace ft
{
template<typename T>
class Node
{
    private:
        Node<T> *prev;
        Node<T> *next;
        T       val;
    
    public:
        
        //canonical Form
        Node() : prev(NULL), next(NULL), val(NULL) {}
        Node(const Node &no) : prev(no.prev), next(no.next), val(no.val) {}
        Node(T &val2) : prev(NULL), next(NULL), val(val2){}
        virtual ~Node(){}
        Node &operator=(Node const &no)
        {
            if (this == &no)
                return (*this);
            this->prev = no.prev;
            this->next = no.next;
            this->val = no.val;
            return (*this);
        }
        void insert_before(Node *no)
        {
            if (this->prev)
            {
                no->prev = this->prev;
                this->prev->next = no;
            }
            no->next = this;
            this->prev = no;
        }
        void insert_after(Node *no)
        {
            if (this->next)
            {
                no->next = this->next;
                this->next->prev = no;
            }
            no->prev = this;
            this->next = no;
        }
};
}
# endif