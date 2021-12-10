#include <iostream>
#include <stdio.h>

#include "../include/linkedList.h"

using namespace std;

LinkedList::LinkedList(){
    head = NULL;
    tail = NULL;
}

void LinkedList::reorderList(){
    //FILL THIS FUNCTION ACCORDINGLY

    Node* traverse = head;
    Node* prev_traverse = tail;
    Node* p = head;
    Node* prev_p = tail;
    while(p->get_next() != head){
        traverse = p;
        prev_traverse = prev_p;
        while(traverse->get_next() != head || traverse == tail){
            if(traverse->get_data() < p->get_data()){
                if(p == head){
                    prev_traverse->next = traverse->next;
                    traverse->set_next(p);
                    head = traverse;
                    p = head;
                    if(tail == traverse){
                        tail = prev_traverse;
                        tail->next = head;
                        prev_p = tail;
                        prev_traverse = tail;
                    }
                    else{
                        tail->next = head;
                        prev_traverse = tail;
                        prev_p = tail;
                    }
                }
                else{
                    prev_traverse->next = traverse->next;
                    if(traverse == tail)
                        tail = prev_traverse;
                    traverse->next = p;
                    prev_p->next = traverse;
                    tail->next = head;
                    prev_traverse = prev_p;
                    p = traverse;
                    prev_p = prev_traverse;
                }

            }

            traverse = traverse->next;
            prev_traverse = prev_traverse->next;
            if(prev_traverse == tail)
                break;
        }
        p = p->next;
        prev_p = prev_p->next;
    }
};

void LinkedList::removeDublicates(){
    //FILL THIS FUNCTION ACCORDINGLY
    Node* traverse = head;
    while(traverse->get_next()!=head){
        if(traverse->get_data() == traverse->get_next()->get_data()){
            if(traverse->get_next()==tail){
                traverse->next = NULL;
                delete traverse;
                tail = traverse;
                tail->next = head;
            }
            else{
                Node* p = traverse->next;
                traverse->set_next(p->next);
                p->next = NULL;
                delete p;
            }
        }
        if(traverse->get_data()!=traverse->next->get_data()){
            traverse = traverse->next;
        }
    }
};

void LinkedList::reverseList(){
    //FILL THIS FUNCTION ACCORDINGLY
    
    Node* traverse = head;
    Node* prev_traverse = tail;
    Node* p = head;
    
    while(traverse->get_next() != head || traverse == tail){
        if(traverse->get_data() > p->get_data()){
            prev_traverse->next = traverse->next;
            traverse->set_next(p);
            head = traverse;
            if(tail == traverse){
                tail = prev_traverse;
                tail->next = head;
                return;
            }
            else{
                tail->next = head;
            }
            p = head;
            traverse = head;
            prev_traverse = tail;
        }
        else{
            prev_traverse = traverse;
            traverse = traverse->next;
        }
    }
};

void LinkedList::add_node(char letter){
    Node* new_node = new Node(letter);
    if(head==NULL){
        head=new_node;
        tail=new_node;
    }
    else{
        tail->set_next(new_node);
        tail = tail->get_next();
        tail->next = head;
    }

}

void LinkedList::printList(){
    Node* temp = head;
    while(true){
        cout<<temp->letter<<" ";
        temp = temp->next;
        if(temp == head)
            break;
    }
    cout<<endl;
};

Node::Node(char letter){
    this->letter = letter;
    this->next = NULL;
}


void Node::set_data(char letter){
    this->letter=letter;
}

int Node::get_data(){
    return this->letter;
}

void Node::set_next(Node* next){
    this->next=next;
}

Node* Node::get_next(){
    return this->next;
}

/* @Author
Student Name: Barış Berke Yılmaz
Student ID : 150180095
Date: 01.11.2021 */
