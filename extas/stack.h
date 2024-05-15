#pragma once
#include<iostream>
using namespace std;


template <typename T>
class node {
public:
    T val;

    node<T>* top;
    node() {
        val = 0;
        top = NULL;

    }
    node(T data) {
        val = data;
        top = NULL;

    }

};

template<typename T>
class stack {
    node<T>* head;
    int size;

public:
    stack() {
        head = NULL;
        size = 0;

    }
    int sizeofstack() {
        return size;
    }
    bool isEmpty() {
        return size == 0;
    }



    void push(T ele) {
        node<T>* n = new node<T>(ele);
        n->top = head;
        head = n;
        size++;
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack empty" << endl;
            return;
        }
        node<T>* temp = head;
        head = head->top;
        temp->top = NULL;
        delete temp;
        size--;
    }
  




    node<T>* Peek() {
        if (isEmpty()) {
            cout << "Stack empty" << endl;
            return 0;
        }
        return head;
    }
    void clear() {

        while (!isEmpty()) {
            pop();
        }


    }


    T TOP() {

        if (isEmpty()) {
            cout << "Stack empty" << endl;
            return 0;
        }
        return head->val;

    }
};
