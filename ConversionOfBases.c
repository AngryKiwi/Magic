
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binToDec();
char* decToBin();
char* decToBase();

int main(){
   printf("%d\n", binToDec("11001"));
   // printf("%s", decToBin(25));
   printf("%s\n", decToBase(2,25));
}

int binToDec(char* bin){
  int dec = 0;
  int i = 0;
  while(i < strlen(bin)){
    if(*(bin + i) == '1') dec = dec * 2 + 1;
    else if(*(bin + i) == '0') dec = dec * 2;
    ++i;
  }
  return dec;
}

//char* decToBin(int dec){
//char* bin = '0';
//
//return bin;
//}

char* decToBase(int base, int dec){
  int i = 0;
  char result[100];
  while(dec > 0){
    result[i++] = dec % base;
    dec /= base;
    printf("%d", result[i]);
  }
 
 result[i] = '\0';
  printf("%s\n",result);
  return result;
}
