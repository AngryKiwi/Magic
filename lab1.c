#include <stdio.h>

void readScores();
void displayScores();
void calcHistogram();
void displayHistogram();
void sortHistogram();

struct freq{
  int scoreNum;
  int scoreFrequency;
};


int main(){
  int scores[100] = {0}; // array of elements
  int count = 0; // count to count how many elements are in the array
  
  // passing by references
  readScores(scores, &count);
  displayScores(scores, &count);

  struct freq hist[count];
  //initiazing the struct hist array
  for(int i = 0; i < count; i++){
    hist[i].scoreNum = scores[i]; // copy the array
    hist[i].scoreFrequency = 0;
  }
  
  calcHistogram(hist, &count);
  displayHistogram(hist, &count);
  sortHistogram(hist, &count);
  displayHistogram(hist, &count);
}

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
  for(int i = 0; i < *pCount; i++){ // iterate through the array
    printf("score %d: %d\n", i, pScores[i]); // displays the array
  }
  printf("\n");
}

// displayHistogram takes the information from calcHistogram and displays the histogram
void displayHistogram(struct freq *hist, int *pCount){
  printf("Displaying the Histogram\n");
  for(int i = 0; i < *pCount; i++){
    printf("value %d: freq %d\n", hist[i].scoreNum, hist[i].scoreFrequency);
      }
  printf("\n");
}

// calcHistogram calculates the given values into a histogram
void calcHistogram(struct freq *hist, int *pCount){
  // calculate the histogram by iterating through the array and comparing
  for(int i = 0; i < *pCount; i++){
    for(int j = i-1; j < *pCount; j++){
      if(hist[i].scoreNum == hist[j].scoreNum){ // compares the array to see if the elements are the same
	hist[i].scoreFrequency++; // counts the frequency of how many times each element was counted
      }
    }
    // printf("%d %d \n", hist[i].scoreNum, hist[i].scoreFrequency);
  }
  
  // update array to not have duplicates
  for(int i = 0; i <*pCount; i++){
    for(int j = i+1; j < *pCount; j++){
      if(hist[j].scoreNum == hist[i].scoreNum){ // compare if the elements are the same within the array
	for(int k = j; k < *pCount; k++){
	  hist[k] = hist[k+1]; // update array
	}
	(*pCount)--; // bring down the count of how many are in the array
	j--;
      }
    }
  }
}


void sortHistogram(struct freq *hist, int *pCount){
  int minIndex;

  for(int i = *pCount -1; i > 0; i--){
    minIndex = 0;
    for (int j = 1; j <= i; j++){
      if((hist[j].scoreFrequency < hist[minIndex].scoreFrequency) ||
	((hist[j].scoreFrequency == hist[minIndex].scoreFrequency)&&
	 (hist[j].scoreNum < hist[minIndex].scoreNum))) {
	minIndex = j;
      }
    }
    struct freq tmp = hist[i];
    hist[i] = hist[minIndex];
    hist[minIndex] = tmp;
  }
  /*
  for(int i = 0; i < *pCount; i++){
    printf("%d %d\n", hist[i].scoreNum, hist[i].scoreFrequency);
    } */
}
