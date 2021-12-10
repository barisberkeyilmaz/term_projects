#ifndef _H
#define _H

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

class materialNode{
    public:
        char id;
        int weight;
        materialNode* next;
        
        materialNode(char, int);
};

class wagonNode{
    public:
        int wagonId;
        materialNode* material;
        wagonNode* next;
};

class Train{  

    wagonNode* head;
    wagonNode* tail;
    
    public:
        void create();
        void addMaterial(char,int);
        void deleteFromWagon(char, int); 
        void printWagon(); //Prints wagon info
        int getLastWagonId();
        void reorderMaterials();
        int checkHowMuch(char);
        void deleteZeros();
        void deleteWagon();
};

#endif