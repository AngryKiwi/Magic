#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binToDec();
char* decToBin();
char* decToBase();
int baseToDeci();
char evaluateChar(int);
int evaluateNum(char);
void reverse(char*);

int main(){
   printf("bintodec 11001 =  %d\n", binToDec("11001"));
   printf("dectobin 25 =  %s\n", decToBin(25));
   printf("dectobase 2, 25 =  %s\n", decToBase(2,25));


   //printing base to deci
   printf("basetodec 8, 157 =  %d\n", baseToDeci(8 ,"157"));
   printf("16, F =  %d\n", baseToDeci(16, "F"));
   printf("2 11001 =  %d\n", baseToDeci(2, "11001"));

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

char* decToBin(int dec){
  int d;
  int count = 0;
  char *ptr;
  ptr = (char*)malloc(32+1);
  for ( int i = sizeof(dec); i>= 0; i--){
    d = dec >> i;
    if (d & 1){
      *(ptr + count) = 1 + '0';
    }
    else{
      *(ptr + count) = 0 + '0';
    }
    count++;
  }
  *(ptr + count) = '\0';
  return ptr;
}



// flip the numbers
void reverse(char* str){
  for(int i = 0; i < strlen(str)/2;i++){
    char temp = str[i];
    str[i] = str[strlen(str) - i - 1];
    str[strlen(str) - i - 1] = temp;
  }
}

char* decToBase(int base, int dec){
  int i = 0;
  char *result;
  result = (char *) malloc(sizeof(char) * (100+1)); // create array of char to send back
  while(dec > 0){ // iterate through
    result[i] = evaluateChar(dec % base);// put remainder into result
    dec /= base; // divide decimal by base for the next iteration
    //printf("%d", result[i]);
    i++; //increment the array
  }
  //printf("%s \n", result);
  result[i] = '\0'; //stops the array for strings to be read
  reverse(result); // needed someway of reversing the number as it came backwards
  return result;
}

// this function takes the base and converts it into decimal 
int baseToDeci(int base, char* value){
  int power = 1;
  int num = 0;

  for(int i = strlen(value) - 1; i >= 0; i--){ // iterates through character strings
    if(evaluateNum(value[i]) >= base){ // if the value is greater than the base then it is invalid
      printf("Invalid");
      return -1;
    }
    num += evaluateNum(value[i]) * power; // the number is adding onto the converted number and times by power
    power = power * base;// power times the base gives the base power
  }
  return num; // return the decimal
}



// these functions handle the letter cases and casts
char evaluateChar(int num){
  if(num >= 0 && num <= 9) return (char)(num + '0');
  else return (char)(num - 10 + 'A');

}

int evaluateNum(char c){
  if(c >= '0' && c <= '9') return (int)c - '0';
  else return (int)c - 'A' + 10;
}
