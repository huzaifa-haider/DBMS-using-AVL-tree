#pragma once
#include<iostream>
using namespace std;

template<typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node(T data) {
        this->data = data;
        next = NULL;
    }
    void setdata(T data) {
        this->data = data;
    }
    T getdata() {
        return data;
    }


};

template<typename T>
class Queue {

public:
    Node<T>* head;
    Node<T>* tail;
    int size;
    Queue() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    int getSize() {
        return size;
    }
    bool isEmpty() {
        return size == 0;
    }
    void enqueue(T ele) {
        Node<T>* n = new Node<T>(ele);
        if (head == NULL) {
            head = n;
            tail = n;
        }
        else {
            tail->next = n;
            tail = n;
        }
        size++;
    }
    T front() {
        if (isEmpty()) {
            return 0;
        }
        return head->data;
    }
    void dequeue() {
        if (isEmpty()) {
            return;
        }
        Node<T>* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        size--;
    }


    int getsize() {
        return size;
    }

};