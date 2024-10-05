#include <stdio.h>

void main(){
    int data;
    scanf("%d", &data);
    for(unsigned int i = 1; i<data+1; i++){
        if ((data%i == 0) && (i != data)) {
            printf("%d ",i);
        }
        else if ((data%i == 0) && (i == data)){
            printf("%d\n",i);
        }
    }
}