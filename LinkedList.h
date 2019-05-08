//
// Created by cvaz on 22/04/19.
//

#ifndef FABRICAVIRTUAL_LINKEDLIST_H
#define FABRICAVIRTUAL_LINKEDLIST_H

#include "Node.h"
#include <iostream>
using namespace std;
template <typename T>

class LinkedList {
public:
    LinkedList(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void push_front(T value){
        Node<T>* nuevoNod = new Node<T>(value);
        if(head== nullptr){
            head=nuevoNod;
            head->setNext(tail);
            tail=nuevoNod;
        } else {
            Node<T>* Tmp = head;
            head = nuevoNod;
            head->setNext(Tmp);
        }
        size+=1;
    };

    void push_back(T value){
        Node<T>* nuevoNod = new Node<T>(value);
        if(head==nullptr){
            head=nuevoNod;
            tail=head;
        }
        else if (head->getNext()==nullptr) {
            tail=nuevoNod;
            head->setNext(tail);
        }
        else{
            Node<T>* tmp = tail;
            tail = nuevoNod;
            tmp->setNext(tail);
        }
        size++;
    }

    void pop_front(){
        if(head==tail){
            head=nullptr;
            tail=head;
        } else{
            head=head->getNext();
        }
        size--;
    }

    void pop_element(int pos){
        Node<T>* tmp = head;
        if(pos==0){
            pop_front();
        }
        else{
            while((pos-=1)!=0 && tmp->getNext()!= nullptr){
                tmp=tmp->getNext();
                pos--;
            }
            tmp->setNext(tmp->getNext()->getNext());
        }
        size--;
    }

    Node<T>* getElemento(int pos) const {
        Node<T>* tmp = head;
        while(pos>0){
            tmp=tmp->getNext();
            pos--;
        }
        return tmp;
    }

    T front() const
    {
        return head->getData();
    }

    int getSize() const
    {
    return size;
    }

    void setSize(int value)
    {
    size = value;
    }

    Node<T>* getHead() const
    {
    return head;
    }

    void setHead(Node<T> *value)
    {
    head = value;
    }

    Node<T>* getTail() const
    {
    return tail;
    }

    void setTail(Node<T> *value)
    {
    tail = value;
    }

    void clearList(){
        int c = 0;
        while(c < this->getSize()){
            this->pop_front();
        }
    }
private:
    Node<T>* head;
    Node<T>* tail;
    int size;
};

#endif //FABRICAVIRTUAL_LINKEDLIST_H
