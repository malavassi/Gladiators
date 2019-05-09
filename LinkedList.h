//
// Created by fabian152195 on 29/04/19.
//

#ifndef GLADIATORS_LINKEDLIST_H
#define GLADIATORS_LINKEDLIST_H

#include "Node.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;
template <typename T>

class LinkedList {
public:
    LinkedList(){
        head = nullptr;
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

    T pop_front(){
        Node<T>* returnin = head;
        if(head==tail){
            head=nullptr;
            tail=head;
        } else{
            head=head->getNext();
        }
        size--;
        if(returnin){
        return returnin->getData();
        }else{
            return NULL;
        }

    }

    void randomize(){
        for(int i=0; i<size; i++) {
            int pos = (int) (rand()%size);
            while(pos<0){
                pos = (int) (rand()%size);
            }
            push_back(pop_element(pos));
        }
    }

    T pop_element(int pos){
        Node<T>* returnin = head;
        Node<T>* tmp = head;
        if(pos==0){
            size--;
            return pop_front();
        }
        else{
            while((pos-=1)>0 && tmp->getNext()!= nullptr){
                tmp=tmp->getNext();
                pos--;
            }
            returnin = tmp->getNext();
            tmp->setNext(tmp->getNext()->getNext());
        }
        size--;
        return returnin->getData();
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

private:
    Node<T>* head;
    Node<T>* tail;
    int size;
};


#endif //GLADIATORS_LINKEDLIST_H
