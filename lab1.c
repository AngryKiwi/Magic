#include <stdio.h>

void readScores(scores, &count)
void displayScores(scores, &count);
void calcHistogram(scores, &count);

int main(){
  int scores[100] = {0}; // array of elements
  int count = 0; // count to count how many elements are in the array
    
  // passing by reference, parameters to readScores
  readScores(scores, &count);
  displayScores(scores, &count);
  calcHistogram(scores, &count);
  
}

struct freq{
  int scoreNum;
  int scoreFrequency; 
};

// readScores takes the file that has the scores and puts the elements in the array
//     while keeping track of the count of the elements
void readScores(int *pScores, int *pCount){
   while(scanf("%d", pScores) != EOF){  //putting elements in the array until file is done
      pScores++; // incrementing the address to put next element in the array
     (*pCount)++; // incrementing count
   }
 }

// displayScores takes the information from readScores and displays the scores
void displayScores(int *pScores, int *pCount){
  printf("Displaying the file results\n");
  for(int i =0; i < *pCount; i++){ // iterate through the array
    printf("score %d: %d\n", i, pScores[i]); // displays the array
  }
  printf("\n");
}

// calcHistogram calculates the given values into a histogram
void calcHistogram(int *pScores, int *pCount){
  struct freq hist[100]; // uses structs to hold the score and how often that scores appear
 
  for(int i = 0; i < *pCount; i++){
    hist[i].scoreNum = pScores[i]; // copy the array into the new array
    hist[i].scoreFrequency = 0; // initiliaze score frequencys to 0 
    for(int j = 0; j < *pCount; j++){
       if(hist[j].scoreNum == pScores[i]){ // compares the array to see if the elements are the same
	 hist[i].scoreFrequency++; // counts the frequency of how many times each element was counted
	 printf("%d %d\n", hist[j].scoreNum, hist[i].scoreFrequency);
       }
   }
    // printf("%d %d\n",hist[i].scoreNum, hist[i].scoreFrequency);
  }
}
