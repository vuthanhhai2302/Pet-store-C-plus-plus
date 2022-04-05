#pragma once
#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
#include<string>

using namespace std;


struct PET
{
	string petID;
	string petName;
	float petWeight;
	int petAge;
	string petColor;
};
struct Node
{
	PET petData;
	Node *next;
};

struct PetStore
{
	Node *head;
	Node *tail;
};


void createPetData(PET &petData);
void printPetData(PET petData);
void initPetStore(PetStore &psName);
bool isEmptyPetStore(PetStore &psName);
Node *createPetNode(PET petDataInput);
Node* findPetByID(PetStore &psName, string findingPetID);
void addPetAtHead(PetStore &psName, Node *nodeAdded);
void addPetAtTail(PetStore &psName, Node* nodeAdded);
void addPetAfterPetID(PetStore &psName, string afterID, Node* nodeAdded);
void initPetStoreFunction(PetStore &psName);
void addPetAfterIdFunction(PetStore &psName);
void addPetFunction(PetStore &psName);
void delPetAtHead(PetStore &psName);
void delPetAtTail(PetStore &psName);
void delPetByID(PetStore &psName, string afterID);
void delPetByWeight(PetStore &psName);
void updatePetColorFunction(PetStore &psName);
void printPetStoreFunction(PetStore &psName);
void sellPetMenu(PetStore &psName, Node* petSoldData);
void sellPetByIDFunction(PetStore &psName);
void menu();
#endif