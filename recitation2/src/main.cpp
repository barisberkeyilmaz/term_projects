#include <iostream> 
#include <stdlib.h>
#include <sstream> 
#include <fstream>

#include "../include/linkedList.h"

using namespace std;

int main(int argc, char* argv[]) {
	system("clear");// make this line as comment if you are compiling on Linux or Mac
	//system("cls"); // make this line as comment if you are compiling on Windows

    LinkedList* newLinkedList = new LinkedList();

    //const char* filename = "input.txt";
    const char* filename = argv[1];

    ifstream my_file(filename);
    if(!my_file){
        cout << "Can not open the file." << endl;
        return EXIT_FAILURE;
    }
    else{
        char letter;
        while(my_file >> letter){
            newLinkedList->add_node(letter);
        }
    }

    cout<<"Readed letters in Circular Linked List: ";
    newLinkedList->printList();

    newLinkedList->reorderList();
    cout<<"After reordering: ";
    newLinkedList->printList();

    newLinkedList->removeDublicates();
    cout<<"After removing dublicates: ";
    newLinkedList->printList();
    
    newLinkedList->reverseList();
    cout<<"Reversed Circular list: ";
    newLinkedList->printList();


    return EXIT_SUCCESS;
}

/* @Author
Student Name: Barış Berke Yılmaz
Student ID : 150180095
Date: 01.11.2021 */
