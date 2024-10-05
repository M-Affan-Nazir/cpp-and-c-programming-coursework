/*

- Linked List
- An Chain of Nodes:
  Each Node stores 1) Data 2) Pointer to next Node

*/


#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *nextNode;  //pointer to the next Node
};

struct LinkedList{
    struct Node *head;      //first node
    int length;
};


struct LinkedList *createList(){
    struct LinkedList *l = malloc(sizeof(struct LinkedList));
    l->length = 0;
    l->head = NULL;
}

void addToFront(struct LinkedList *l, int dataX){
    struct Node *n = malloc(sizeof(struct Node));
    n->data = dataX;
    n->nextNode = NULL;
    if(l->length == 0){
        l->head = n;
        l->length = l->length + 1;
    }
    else{
        struct Node *last = l->head;
        struct Node *headNodeLocation = l->head;
        struct Node *pointerIteration = headNodeLocation;
        for(int j = 0; j<l->length-1; j++){   //-1 ; we need the last Node; AND THEN CHANGE THE POINTER IN THIS NODE
            pointerIteration = pointerIteration->nextNode;
        }
        pointerIteration->nextNode = n;
        l->length = l->length + 1;
    }
    
}

int ith(struct LinkedList *l, int i){
    struct Node *headNodeLocation = l->head;
    struct Node *pointerIteration = headNodeLocation;  //start at head Node
    for(int j = 0; j< i; j++){
        pointerIteration = pointerIteration->nextNode;  //go to next node UNTIL you've reached ith node
    }
    return pointerIteration->data;

}

void removeithItem(struct LinkedList *l, int i){
    if(i == 0){
        struct Node *savingHeadMemoryAddressForFreeingIt = l->head;
        l-> head = l->head->nextNode;   // GOLDEN SYNTAX  
        free(savingHeadMemoryAddressForFreeingIt);
        // free(l->head)    can not do this; since l->head now points to the UPDATED/NEW Node
        l->length -= 1;
    }
    else{

    }
}


void main(){
    struct LinkedList *l = createList();  //creates empty list
    addToFront(l,1);  //adds to list
    addToFront(l,2);
    addToFront(l,3);
    for(int i=0; i<l->length;i++){
        printf("%d\n",ith(l,i));        //ith = gives us the data in the ith Node
    }
    prinf("--------------------\n");
    // int i = 1;
    // removeithItem(l,i);    //removes ith item
}