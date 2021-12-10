#ifndef _H
#define _H

#include <iostream>
#include <stdio.h>

using namespace std;

class Node{
    public:
        char letter;
        Node* next;
        Node(char);
        void set_data(char);
        int get_data();
        void set_next(Node*);
        Node* get_next();
};


class LinkedList{

    Node* head;
    Node* tail;

    public:
       
        LinkedList();
        void reorderList();
        void removeDublicates();
        void reverseList();
        void printList();
        void add_node(char);
};

#endif

/* @Author
Student Name: Barış Berke Yılmaz
Student ID : 150180095
Date: 01.11.2021 */
