//serve code

#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include <unistd.h>
#include <arpa/inet>

int count_vowel(char * str) {
   int count = 0;

   for(i=0; str[i]!=\'0'; i++) {
   char ch = tolower(sts[i]);
   if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
   count ++;
  }
   return count; 

}
