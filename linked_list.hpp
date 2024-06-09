#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>

template <typename T>
class LinkedList {
    private:
        class Node {
            public:
                Node* pNext;
                T value;

                Node() {
                    pNext = nullptr;
                    value = T();
                }
        };
        
        Node* pHead;
    public:
    LinkedList();
    LinkedList(const LinkedList&);
    LinkedList& operator=(const LinkedList&);
    ~LinkedList();
    void insert(const T, int);
    void remove(int);
    T& get_item(int);
    size_t get_size() const;
    void print_item(int);
    void print_list();
};

template <typename T>
LinkedList<T>::LinkedList() {
    pHead = nullptr;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList& OTHER) {
    if (OTHER.pHead != nullptr) {
        pHead = new Node;
        pHead->value = OTHER.pHead->value;
        pHead->pNext = nullptr;

        Node* current = pHead;
        Node* otherCurrent = OTHER.pHead->pNext;

        while (otherCurrent != nullptr) {
            current->pNext = new Node;
            current = current->pNext;
            current->value = otherCurrent->value;
            otherCurrent = otherCurrent->pNext;
        }    
    }  
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& OTHER) {
    // check self assignment
    if (this != &OTHER) {
        // delete existing list
        if (pHead != nullptr) {
            while (pHead != nullptr) {
                Node* current = pHead;
                pHead = pHead->pNext;
                delete current;
            }
        }

        if (OTHER.pHead != nullptr) {
            pHead = new Node;
            pHead->value = OTHER.pHead->value;
            pHead->pNext = nullptr;

            Node* current = pHead;
            Node* otherCurrent = OTHER.pHead->pNext;

            while (otherCurrent != nullptr) {
                current->pNext = new Node;
                current = current->pNext;
                current->value = otherCurrent->value;
                otherCurrent = otherCurrent->pNext;
            }    
        }  
    }
    return *this;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    while (pHead != nullptr) {
        Node* current = pHead;
        pHead = pHead->pNext;
        delete current;
    }
}

template <typename T>
void LinkedList<T>::insert(const T VALUE, int pos) {
    // linkedlist is empty
    if (pHead == nullptr) {
        pHead = new Node;
        pHead->value = VALUE;
        pHead->pNext = nullptr;
        return;
    }

    int list_size = this->get_size();
    if (pos < 0) pos = 0;
    if (pos >= list_size) pos = list_size;

    // beginning insertion
    if (pos == 0) {
        Node* temp  = new Node;
        temp->value = VALUE;
        temp->pNext = pHead;
        pHead = temp;
        return;
    }

    // middle/end insertion
    Node* current = pHead;
    for (int i = 0; i < pos - 1; i++) {
        current = current->pNext;
    }
    Node* temp = new Node;
    temp->value = VALUE;
    temp->pNext = current->pNext;
    current->pNext = temp;
}

template <typename T>
void LinkedList<T>::remove(int pos) {
    // linkedlist is empty
    if (pHead == nullptr) {
        return; // do nothing
    }

    int list_size = this->get_size();
    if (pos < 0) pos = 0;
    if (pos >= list_size) pos = list_size - 1;

    // remove from beginning
    if (pos == 0) {
        Node* temp = pHead;
        pHead = pHead->pNext;
        delete temp;
        return;
    }

    // remove from middle/end
    Node* current = pHead;
    for (int i = 0; i < pos - 1; i++) {
        current = current->pNext;
    }
    Node* temp = current->pNext;
    current->pNext = temp->pNext;
    delete temp;
}

template <typename T>
T& LinkedList<T>::get_item(int pos) {
    // linkedlist is empty
    if (pHead == nullptr) {
        throw std::out_of_range("LinkedList is empty");
    }

    int list_size = this->get_size();
    if (pos < 0) pos = 0;
    if (pos >= list_size) pos = list_size - 1;

    Node* current = pHead;
    for (int i = 0; i < pos; i++) {
        current = current->pNext;
    }
    return current->value;
}

template <typename T>
size_t LinkedList<T>::get_size() const {
    size_t list_size = 0;
    Node* current = pHead;
    while (current != nullptr) {
        list_size++;
        current = current->pNext;
    }
    return list_size;
}

template <typename T>
void LinkedList<T>::print_item(int pos) {
    // linkedlist is empty
    if (pHead == nullptr) {
        std::cout << "linkedlist is empty" << std::endl;
        return;
    }

    int list_size = this->get_size();
    if (pos < 0) pos = 0;
    if (pos >= list_size) pos = list_size - 1;

    Node* current = pHead;
    for (int i = 0; i < pos; i++) {
        current = current->pNext;
    }
    std::cout << current->value << std::endl;
}

template <typename T>
void LinkedList<T>::print_list() {
    if (pHead == nullptr) {
        std::cout << "linkedlist is empty" << std::endl;
        return;
    }
    Node* current = pHead;
    while (current != nullptr) {
        std::cout << current->value << ", ";
        current = current->pNext;
    }
    std::cout << std::endl;
}

#endif //LINKED_LIST_HPP