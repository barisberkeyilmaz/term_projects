#include <iostream>
#include <stdio.h>
#include <string.h>

#include "linkedList.h"

using namespace std;

void Train::create(){
    head = NULL;
    tail = NULL;
}; 

void Train::addMaterial(char material, int weight){
        //FILL THIS FUNCTION ACCORDINGLY

    wagonNode* traverse = head;
    if(traverse == NULL){
        int temp_id = 1;
        while(weight >= 2000){
            materialNode* new_materialNode = new materialNode(material,2000);
            wagonNode* new_wagon = new wagonNode;
            new_wagon->next = NULL;
            new_wagon->wagonId = temp_id;
            new_wagon->material = new_materialNode;
            if(temp_id == 1){
                traverse = new_wagon;
                head = traverse;
                tail = head;
            }
            else{
                traverse->next = new_wagon;
                traverse = traverse->next;
                tail = traverse;
            }
            temp_id++;
            weight = weight - 2000;
        }
        while(weight != 0){
            materialNode* new_materialNode = new materialNode(material,weight);
            wagonNode* new_wagon = new wagonNode;
            new_wagon->next = NULL;
            new_wagon->wagonId = temp_id;
            new_wagon->material = new_materialNode;
            if(head==NULL){
                head = new_wagon;
                tail = new_wagon;
            }
            else{
                tail->next = new_wagon;
                tail = tail->next;
            }
            temp_id++;
            weight = weight - weight;
        }
        
    }
    else{
        
        while(weight > 0){
            materialNode* p = traverse->material; 
            while(p != NULL){
                if(p->id == material){
                    if(p->weight == 2000){
                        if(traverse->next == NULL){
                            if(weight>=2000){
                                materialNode* new_materialNode = new materialNode(material,2000);
                                wagonNode* new_wagon = new wagonNode;
                                new_wagon->next = NULL;
                                new_wagon->wagonId = getLastWagonId() + 1;
                                new_wagon->material = new_materialNode;
                                tail->next = new_wagon;
                                tail = tail->next;
                                weight = weight - 2000;
                                break;
                            }
                            else{
                                materialNode* new_materialNode = new materialNode(material,weight);
                                wagonNode* new_wagon = new wagonNode;
                                new_wagon->next = NULL;
                                new_wagon->wagonId = getLastWagonId() + 1;
                                new_wagon->material = new_materialNode;
                                tail->next = new_wagon;
                                tail = tail->next;
                                weight = weight - weight;
                                break;
                            }
                        }
                        else{
                            traverse = traverse->next;
                            break;
                        }
                    }
                    else{
                        int temp_weight = weight + p->weight;
                        if(temp_weight >= 2000){
                            p->weight = 2000;
                            temp_weight = temp_weight - 2000;
                            weight = temp_weight;
                            break;
                        }
                        else{
                            p->weight = temp_weight;
                            weight = 0;
                            break;
                        }
                    }
                }
                else{
                    if(p->next == NULL){
                        if(weight>=2000){
                                materialNode* new_materialNode = new materialNode(material,2000);
                                p->next = new_materialNode;
                                weight = weight - 2000;
                                break;
                            }
                            else{
                                materialNode* new_materialNode = new materialNode(material,weight);
                                p->next = new_materialNode;
                                weight = weight - weight;
                                break;
                            }
                    }
                    else{
                        p = p->next;
                    }
                }
            }
        }
    }

    reorderMaterials();
        
}; 

void Train::deleteFromWagon(char material, int weight){
        //FILL THIS FUNCTION ACCORDINGLY
    
    int temp_weight = checkHowMuch(material);
    deleteZeros();
    deleteWagon();
    temp_weight = temp_weight - weight;
    addMaterial(material,temp_weight);
};  

void Train::reorderMaterials(){
    wagonNode* traverse = head;
    while(traverse != NULL){
        
        materialNode* cont = traverse->material;

        while(cont != NULL){

            materialNode* p = cont;

            while(p != NULL){
                if(p->id < cont->id){
                    materialNode* temp = new materialNode(cont->id,cont->weight);
                    cont->id = p->id;
                    cont->weight = p->weight;
                    p->id = temp->id;
                    p->weight = temp->weight;
                    cont = head->material;
                    p = head->material;
                    traverse = head;
                    delete temp;
                }
                else{
                    p = p->next;
                }
            }

            cont = cont->next;
        }

        traverse = traverse->next;
    }
};

int Train::getLastWagonId(){
    wagonNode* traverse = head;
    while(traverse != NULL){
        if(traverse->next == NULL)
            return traverse->wagonId;
        traverse = traverse->next;
    }
    return 0;
};

void Train::deleteZeros(){
    wagonNode* traverse = head;
    while(traverse != NULL){
        materialNode* p = traverse->material;
        materialNode* prev_p = p;
        while(p != NULL){
            if(p->weight == 0 && p == traverse->material){
                traverse->material = traverse->material->next;
            }
            else if(p->weight == 0 && p != traverse->material){
                prev_p->next = p->next;
            }
                prev_p = p;
                p = p->next; 
        }

        traverse = traverse->next;
    }
};

int Train::checkHowMuch(char material){
    wagonNode* traverse = head;
    int temp_weight = 0;
    while(traverse != NULL){
        materialNode* p = traverse->material;
        while(p != NULL){
            if(p->id == material){
                if(p->weight != 0){
                    temp_weight += p->weight;
                    p->weight = 0;
                    p = p->next;
                }
                else{
                    p = p->next;
                }
            }
            else{
                p = p->next;
            }
        }

        traverse = traverse->next;
    }
    return temp_weight;
};

void Train::deleteWagon(){
    wagonNode* traverse = head;
    wagonNode* prev_traverse = head;
    while(traverse != NULL){
        if(traverse->material == NULL && traverse == head){
            create();
        }
        else if(traverse->material == NULL){
            prev_traverse->next = NULL;
            tail = prev_traverse;
            traverse = head;
            prev_traverse = head;
        }
        else{
            prev_traverse = traverse;
            traverse = traverse->next;
        }
    }
};

materialNode::materialNode(char id, int weight){
    this->id = id;
    this->weight = weight;
    this->next = NULL;
};


void Train::printWagon(){
    wagonNode* tempWagon = head;

    if(tempWagon == NULL){
            cout<<"Train is empty!!!"<<endl;
            return;
    }

    while(tempWagon != NULL){
        materialNode* tempMat = tempWagon->material;
        cout<<tempWagon->wagonId<<". Wagon:"<<endl; 
        while (tempMat != NULL){
            cout<<tempMat->id<<": "<<tempMat->weight<<"KG, "; 
            tempMat = tempMat->next;  
        }
        cout<<endl; 
        tempWagon = tempWagon->next;
    }
    cout<<endl;
}; 