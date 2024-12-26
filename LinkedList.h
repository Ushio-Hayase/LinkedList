#pragma once
/*
 * LinkedList data structure header file
 */
#include <functional>

#include "Iterator.h"

template <typename T>
struct LinkedListElement
{
    T content;
    LinkedListElement *nextElement = nulli;
    LinkedListElement *prevElement = nulli;
};

template <typename T>
class LinkedList
{
   public:
    using iterator = IIterator<LinkedListElement<T>>;

    inline const T &front() { return this->frontElement->content; }

    inline const T &back() { return this->endElement->content; }

    inline iterator begin() { return iterator(this->frontElement); }

    inline iterator end() { return iterator(this->endElement); }

    inline void push_back(const T &content)
    {
        this->endElement->nextElement = new LinkedListElement<T>();
        this->endElement = this->endElement->nextElement;
        this->endElement->content = content;
    }

    inline void push_front(const T &content)
    {
        this->frontElement->prevElement = new LinkedListElement<T>();
        this->frontElement = this->frontElement->prevElement;
        this->frontElement->content = content;
    }

    inline void pop_back()
    {
        LinkedList<T> *tmp = this->endElement->prevElement;
        delete this->endElement;
        this->endElement = tmp;
        this->endElement->nextElement = nullptr;
    }

    inline void pop_front()
    {
        LinkedList<T> *tmp = this->frontElement->nextElement;
        delete this->frontElement;
        this->frontElement = tmp;
        this->frontElement->prevElement = nullptr;
    }

    inline void insert(const iterator &iter, const T &content)
    {
        LinkedListElement<T> *prevTmp = iter.base()->prevElement;

        iter.base()->prevElement = new LinkedListElement<T>();
        iter.base()->prevElement->content = content;
        prevTmp->nextElement = iter.base()->prevElement;
    }

    inline iterator erase(const iterator &iter)
    {
        LinkedListElement<T> *tmp = iter.base()->nextElement;
        iter.base()->prevElement = tmp;
        tmp->prevElement = iter.base()->prevElement;

        return tmp;
    }

    inline size_t size() { return this->length; }

    void remove(const T &content)
    {
        for (auto iter = this->begin(); iter != this->end(); iter++)
        {
            if (iter.base().content == content) this->erase(iter);
        }
    }

    void reverse()
    {
        for (auto iter = this->begin(); iter != this->end(); iter++)
        {
            LinkedListElement<T> *tmp = iter.base().prevElement;
            iter.base().prevElement = iter.base().nextElement;
            iter.base().nextElement = tmp;
        }

        LinkedListElement<T> *tmp = this->frontElement;
        this->frontElement = this->endElement;
        this->endElement = tmp;
    }

    void sort(std::function<bool(T, T)> func)
    {
        LinkedListElement<T> *L1;
        LinkedListElement<T> *L1End;
        LinkedListElement<T> *L2;
        LinkedListElement<T> *

            LinkedListElement<T> *center = this->frontElement;

        for (auto iter = this->begin(); iter != this.end(); iter++)
        {
            if (!func(center->content, iter.base().content))
                L1.nextElementiter.base());
            else
                L2.push_back(iter.base());
        }
    }

   private:
    LinkedList<T> sortReserve(LinkedList<T> &list,
                              std::function<bool(int, int)> func)
    {
        if (list.size() < 2) return list;

        LinkedList<T> L1;
        LinkedList<T> L2;

        LinkedListElement<T> *center = this->frontElement;

        for (auto iter = this->begin(); iter != this.end(); iter++)
        {
            if (!func(center->content, iter.base().content))
                L1.push_back(iter.base());
            else
                L2.push_back(iter.base());
        }
    }

   private:
    LinkedListElement<T> *frontElement;
    LinkedListElement<T> *endElement;
    size_t length = 0;
};