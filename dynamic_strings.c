/*Bismillah*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[])
{
  puts("\nEnter at most 10 characters");
  puts("Enter \"end\" to  exit\n");

  char (*array)[10] = malloc(sizeof(char[10])); //allocating memory for the array of strings of 10 bt

  if (array == NULL) {
    perror("Error allocating memory");
    exit(1);
  }

  char the_word[10];
  int number = 0;
  char (*temp_array)[10]; // a temp pointer variable to check when reallocating 

  while (1) {

    fputs(">> ", stdout);   
    scanf("%s", the_word); //storing the word entered by the user in a temp array

    if (strcmp(the_word, "end") == 0) { // checking if user is done with entering words
      break;
    }

    strcpy(array[number], the_word); // copy the word to our array
    ++number;

    temp_array = realloc(array, sizeof(char[10])*(number +1)); //number + 1, because we are staring from 0. and 
                                                                           //there already was space for 1 string. we need for 2

    if (temp_array == NULL) {
      perror("Error allocating memory");
      exit(1);
    } 

    array = temp_array;
  }

  puts("");
  printf("You entered: %d words\n", number);

  for (int i = 0; i < number ; i++) {
    printf("<< %s\n", array[i]);
  }
  puts("");

 return 0;
}
