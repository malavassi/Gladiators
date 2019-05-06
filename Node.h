//
// Created by fabian152195 on 29/04/19.
//

#ifndef GLADIATORS_NODE_H
#define GLADIATORS_NODE_H

//using namespace std;

using namespace std;
template <typename T>

class Node {
public:
    Node(){
        data= nullptr;
        next= nullptr;
        id=0;
    };

    /**
     * Contructor
     * @param valor Valor del nodo
     * */
    Node(T valor){
        data=&valor;
        next= nullptr;
    };

    T getData() {
        return *data;
    }

    void setData(T data) {
        Node::data = data;
    }

    Node<T> *getNext() const {
        return next;
    }

    void setNext(Node<T> *next) {
        Node::next = next;
    }

    int getId() const {
        return id;
    }

    void setId(int id) {
        Node::id = id;
    }


private:
    T* data;  /** Dato del nodo*/
    Node<T>* next;  /** Puntero al siguiente nodo */
    int id;
};

#endif //GLADIATORS_NODE_H
