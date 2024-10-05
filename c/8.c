/*

- sizeof(array1)/sizeof(char))   [size of string]
- %s = string

*/

#include <stdio.h>
#include <string.h>

unsigned int stringLength(char *s){
    unsigned int i = 0;
    while(*s != '\0'){
        ++i, ++s;  //i== number of characters; '++s' = going to the next character in array (incrementing pointer; pointer arthmetic)
    }
    return i;

}

void stringReplace(char *s, char find, char replace ){
    int flag = 0;
    int i = 0;
    while(flag == 0){
        char character = *(s+i);
        if(character == find){
            *(s+i) = replace;
        }
        i++;
        if (character == '\0'){     //single quotation marks 
            flag = 1;
        }
    }

}

void concatenateString(){
    char s1[10] = "abcd";   //abcd = 5 characters. array length = 10. This string can adjust 5 more characters!
    char s2[] = "xxxx";

}

void main(){
    char array1[] = "abcd";
    char sameAsArray1[] = {'a','b','c','d','\0'};   // C strings ALWAYS end with 
    printf("%lu\n", sizeof(array1)/sizeof(char));
    
    //-----------------------------------------
    
    char arrayX[] = "aaaaaaaab";
    stringReplace(arrayX,'a','x');
    int flag = 0;
    int i = 0;
     while(flag == 0){
        char character = *(arrayX+i);       //array itself is a pointer!
        printf("%c",character);
        i++;
        if (character == '\0'){     //single quotation marks 
            flag = 1;
        }
    }

    printf("\n%s",arrayX );
}