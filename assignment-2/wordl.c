#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char * const GREEN = "\x1b[32m";
const char * const YELLOW = "\x1b[33m";
const char * const WHITE = "\x1b[0m";

void setColour(const char *colour) {
  printf("%s", colour);
}

int countStringLength(char *word){
  int n = 0;
  int flag = 1;
  while(flag == 1){
    if(word[n] == '\0'){
      flag = 0;
    }
    else{
      n += 1;
    }
  }
  return n;
}

char *slice(char*array, int start, int end){
  char *newArr = malloc(sizeof(char)*(end-start));
  for(int i=start;i<end;i++){
    newArr[i-start] = array[i];
  }

  return newArr;

}

int wordInString(char letter, char *word){
  int n = 0;
  while(word[n] != '\0'){
    if(word[n] == letter){
      return n;
    }
    n += 1;
  }
  return -1;
}

int arrayEqual(char *array1, char*array2, int length){
  for(int i=0; i<length; i++){
    if(array1[i] != array2[i]){
      return 0;
    }
  }
  return 1;
}

int main(int num, char *array[]){
  setColour(WHITE);
  if(num != 2){
    printf("Invalid number of command line arguments");
    return 0;
  }
  char *word = array[1];
  int lengthWord = countStringLength(word);





int tries = 0;
int flag = 0;

while((tries<6) && (flag == 0)){

  char *inWordArray = malloc(lengthWord*sizeof(char));
  for(int i = 0; i<lengthWord;i++){
    inWordArray[i] = word[i];
  }

  char guess[sizeof(char)*12];
  printf("Enter Guess: ");
  scanf("%s", guess);
  int lengthGuess = countStringLength(guess);

  if(lengthGuess != lengthWord){
    printf("Invalid guess, guess length must match word length");
    return 0;
  }
  
  int equal = arrayEqual(inWordArray,guess, lengthGuess);
  if(equal == 1){
    flag = 1;
  }

  int *colorCoding = malloc(lengthGuess*sizeof(int));   //1 = green; 2 = Yellow, 0=White
  for(int i = 0; i<lengthGuess; i++){
    colorCoding[i] = 0;
  }

  for(int i = 0; i<lengthWord; i++){
    if(inWordArray[i]==guess[i]){
      colorCoding[i] = 1;
      inWordArray[i] = '|';
    } 
  }
  
  for(int i = 0; i<lengthGuess; i++){
    int index = wordInString(guess[i],inWordArray);
    if(colorCoding[i] != 1){
      if(index != -1){
        inWordArray[index] = '|';
        colorCoding[i] = 2;
      }
    }
  }

 for(int i = 0; i<lengthGuess; i++){
    if(colorCoding[i]==1){
      setColour(GREEN);
      printf("%c",guess[i]);
      setColour(WHITE);
    }
    if(colorCoding[i]==2){
      setColour(YELLOW);
      printf("%c",guess[i]);
      setColour(WHITE);
    }
    if(colorCoding[i]==0){
      setColour(WHITE);
      printf("%c",guess[i]);
      setColour(WHITE);
    }    
 } 


  tries += 1;
  printf("\n");
  free(inWordArray);
  free(colorCoding);
}
  
if(flag == 1){
  printf("Finished in %d guesses",tries);
}
else{
  printf("Failed to guess the word: %s",word);
}

return 1;

}
