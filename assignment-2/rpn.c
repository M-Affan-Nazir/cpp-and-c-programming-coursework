#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *createStack(){
    int *stack = malloc(sizeof(int)*1);   //stack = pointer TO the memory address where the space is allocated
    return stack;

}

void addToStack(int **prevStack, int *length, int newNumber){
    // create new virtual-stack using heap with +1 length
    //copy all contents to new heap
    //add new number to it
    int *newStack = malloc(sizeof(int)*( (*length) +1));
    for(int i=0; i<=(*length)-1;i++){            // = 
        newStack[i] = (*prevStack)[i];      //prevstack = pointer TO the pointer of the memory location
    }

    newStack[(*length)] = newNumber;
    *length = (*length) +1;
    free(*prevStack);
    *prevStack = newStack;
    
}


void operationInStackint(int **prevStack, int *length, int operation){
    //1 = add, 2 = subtract, 3 = multiply, 4 = divide
    int num1 = (*prevStack)[*length-2];
    int num2 = (*prevStack)[*length-1];
    // printf("%d , %d", num1, num2);
    int answer;
    if(operation == 1){
        answer = num1 + num2;
    }
    else if(operation == 2){
        answer = num1 - num2;
    }
    else if(operation == 3){
        answer = num1 * num2;
    }
    else if(operation == 4){
        answer = num1 / num2;
    }
    int *newStack = malloc(sizeof(int)*( (*length) - 1));
    for(int i=0; i<*length-2;i++){
        newStack[i] = (*prevStack)[i];      //prevstack = pointer TO the pointer of the memory location
    }
    newStack[*length-2] = answer;
    *length = *length - 1;
    free(*prevStack); 
    *prevStack = newStack;

}

int main(){
    char input[sizeof(char)*33];
    fgets(input, sizeof(input), stdin);
    char delimiter[] = " ";
    char *token = strtok(input, delimiter);

    int *stack = createStack(); 
    int currentLength = 1;   // 0 = 1st index
    int firstNumer = 1;
    

    while(token != NULL){
        int num;
        if(sscanf(token,"%d",&num) == 1){    // sscanf()
            //a Number
            if(firstNumer == 1){
                stack[0] = num;
                firstNumer = 0;

            }
            else{
                //stack Full
                addToStack(&stack,&currentLength,num);   // &stack
            }

        }     
        else{
            //an operator
            if(*token == 'p'){
                operationInStackint(&stack, &currentLength, 1);
            }
            else if(*token == 's'){
                operationInStackint(&stack, &currentLength, 2);
            }
            else if(*token == '*'){
                operationInStackint(&stack, &currentLength, 3);
            }
            else if(*token == '/'){
                operationInStackint(&stack, &currentLength, 4);
            }
        }
        token = strtok(NULL, delimiter);
    }
    
    if(currentLength == 1){
        printf("%d\n",stack[0]);
    }
    else{
        printf("Invalid input, not all operands consumed\n");
        printf("%d\n",stack[0]);
    }
    free(stack);

    return 1;
}