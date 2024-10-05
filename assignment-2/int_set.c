#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int ascend(int *array, int length){
    int n = length;
    int swapped = 0;
    do {
        swapped = 0;
        for(int i = 1; i < n; i++){
            if(array[i-1] > array[i]){
                int temp = array[i];
                array[i] = array[i-1];
                array[i-1] = temp;
                swapped = 1;
            }
        }
        n = n - 1;
    } while(swapped != 0);
    return 1;
}

int add(int **set, int num, int *length){
    if(*length == 0){
        (*set)[0] = num;
        *length = *length + 1;
    }
    else{
        int isInSet = 0;
        for(int i = 0; i < *length; i++){
            if((*set)[i] == num){
                isInSet = 1;
            }
        }

        if(isInSet == 0){
            int *newSet = malloc(sizeof(int)*( (*length) +1));
            for(int i=0; i<=(*length)-1;i++){            
                newSet[i] = (*set)[i];   
            }

            newSet[(*length)] = num;
            *length = (*length) +1;
            free(*set);
            ascend(newSet, *length);
            *set = newSet;
            
        }
    }
    return 1;
}

int removeFromSet(int **set, int num, int *length){
    if(*length != 0){

        int count = 0;
        for(int i = 0; i < *length; i++){
            if((*set)[i] == num){
                count++;
            }
        }

        if(count == 0){
            return 0;
        }

        int newSetIndex = 0;

        int *newSet = malloc(sizeof(int)*( (*length) - count));
        for(int i=0; i<*length;i++){
            if((*set)[i] != num){
                newSet[newSetIndex] = (*set)[i];
                newSetIndex++;
            }
        }
        *length = (*length) - count;
        free(*set); 
        ascend(newSet, *length);
        *set = newSet;
    }
    return 1;
}

int print(int *set, int *length){
    if(*length != 0){
        for(int i=0; i<*length; i++){
            if(i == (*length-1)){
                printf("%d", set[i]);

            }
            else{
                printf("%d ", set[i]);
            }
        }
        printf("\n");
    }
    return 1;
}

int printIntersection(int *x, int *y,  int *xLength,  int *yLength){
    int *array = malloc((*xLength)*(*yLength)*sizeof(int));
    int arrayIndex = 0;
    int anyCommon = 0;
    for(int i = 0;i <(*xLength)*(*yLength); i++){
        array[i] = 9872390;
    }
    for(int i= 0; i <*xLength; i++){
        for(int j=0;j<*yLength; j++){
            if(x[i] == y[j]){
                anyCommon = 1;
                array[arrayIndex] = x[i];
                arrayIndex++;
            }
        }
    }

    int count = 0;

    for(int i = 0; i<(*xLength)*(*yLength); i++){
        if(array[i] != 9872390){
            count++;
        }
    }
    ascend(array, (*xLength)*(*yLength));
    for(int i=0; i<count; i++){
        if(i == count-1){
            printf("%d",array[i]);    
        }
        else{
            printf("%d ",array[i]);
        }
    }

    if(anyCommon == 1){
        printf("\n");
    }
    
    free(array);
    return 1;
}

int printUnion(int *x, int *y, int *xLength,  int *yLength){
    int *array = malloc((*xLength)*(*yLength)*sizeof(int));
    int arrayIndex = 0;
    for(int i = 0;i <(*xLength)*(*yLength); i++){
        array[i] = 9872390;
    }
    for(int i= 0; i <*xLength; i++){
        array[arrayIndex] = x[i];
        arrayIndex++;
    }
    for(int i= 0; i <*yLength; i++){
        int isInSet = 0;
        for(int j = 0; j<(*xLength)*(*yLength); j++){
            if(y[i] == array[j]){
                isInSet = 1;
            }
        }
        if(isInSet == 0){
            array[arrayIndex] = y[i];
            arrayIndex++;
        }
        
    }

    if(*xLength == 0 && *yLength == 0){

    }
    else if(*xLength == 0 && *yLength != 0){
        for(int i = 0; i<*yLength; i++){
            if(i == *yLength - 1){
                printf("%d", y[i]);
            }
            else{
                 printf("%d ", y[i]);
            }
        }
        printf("\n");
    }
    else if(*yLength == 0 && *xLength != 0){
        for(int i = 0; i<*xLength; i++){
            if(i == *xLength - 1){
                printf("%d", x[i]);
            }
            else{
                 printf("%d ", x[i]);
            }
        }
        printf("\n");
    }
    else{
        int count = 0;
        
        for(int i = 0; i<(*xLength)*(*yLength); i++){
            if(array[i] != 9872390){
                count++;
            }
        }

        ascend(array, (*xLength)*(*yLength));
        for(int i=0; i<count; i++){
            if(i == count-1){
                printf("%d",array[i]);    
            }
            else{
                printf("%d ",array[i]);
            }
        }
        printf("\n");

    }
    
    free(array);
    return 1;
}

int main(){

    int *x = malloc(sizeof(int)*1);
    int *y = malloc(sizeof(int)*1);
    
    int xLength = 0;
    int yLength = 0;

    int exit = 0;

    

    while(exit == 0){
        char input[sizeof(char)*33];
        fgets(input, sizeof(input), stdin);
        char delimiter[] = " ";
        char *token = strtok(input, delimiter);
        
        int operation = 0;  //1 = add, 2 = remove, 3 = print, 4 = union; 5 = intersection;
        int target = -1;   //0 = x; 1 = y

        if(*token == 'u'){
            printUnion(x, y, &xLength, &yLength);
        }
        else if(*token == 'i'){
            printIntersection(x,y, &xLength, &yLength);
        }
        else{
             while(token != NULL){
            if(operation == 0){
                // operation
                if(*token == 'a'){
                    operation = 1;
                }
                else if(*token == 'r'){
                    operation = 2;
                }
                else if(*token == 'p'){
                    operation = 3;
                }
                else if(*token == 'q'){
                    exit = 1;
                }
            }
            else{
                //elaboration:
                if(operation <=2){
                    //add OR Remove
                    if(target == -1){
                        //no target yet specified
                        if(*token == 'x'){
                            target = 0;
                        }
                        else{
                            target = 1;
                        }
                    }
                    else{
                        //target specified
                        int num;
                        sscanf(token,"%d",&num);
                        if(operation == 1){
                            if(target == 0){
                                add(&x,num, &xLength);
                            }
                            else{
                                add(&y,num, &yLength);
                            }
                        }
                        else{
                            if(target == 0){
                                removeFromSet(&x,num, &xLength);
                            }
                            else{
                                removeFromSet(&y,num, &yLength);
                            }
                        }
                    }

                }
                else if(operation == 3){
                    //print
                    if(*token == 'x'){
                        print(x, &xLength);
                    }
                    else{
                        print(y, &yLength);
                    }

                }
            }
            token = strtok(NULL, delimiter);
        }
        }
    }

    free(x);
    free(y);

    return 1;
}