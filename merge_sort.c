#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void MergeArray(int arr[], int left, int mid, int right){
    
    int i, j, k;
    int array_left = mid - left + 1;
    int array_right = right - mid;

    // Crio dois arrays temporários para armazenar os arrays divididos
    int L[array_left], R[array_right];

    // Faço uma cópia dos Arrays, dividindo eles entre RIGHT e LEFT
    for (i = 0; i < array_left; i++)
        L[i] = arr[left + i];
    for (j = 0; j < array_right; j++)
        R[j] = arr[mid + 1 + j];

    // Junto novamente os Arrays que foram separados
    i = 0;
    j = 0;
    k = left;
    while (i < array_left && j < array_right) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < array_left) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < array_right) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// 
void MergeSort(int arr[], int left, int right){
    
    if (left < right) {
        int mid = left + (right - left) / 2;

        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);

        MergeArray(arr, left, mid, right);
    }
}

void TimeStamp(int arr[], int len){
  clock_t start, end;
  double clock_time;

  start = clock();
  MergeSort(arr, 0, len - 1);
  end = clock();

  clock_time = ((double)(end - start))/CLOCKS_PER_SEC;
  printf("Ordenação com Array de %d elementos: %f secs\n", len, clock_time);

}

int main(){

  int array_small[10];
  int array_mid[100];
  int array_high[1000];
  
  // População dos Arrays para medição.
  srand(time(NULL));
  for(int i = 0 ; i < 10 ; i++){
    array_small[i] = rand() % 10;
  }

  srand(time(NULL));
  for(int i = 0 ; i < 100 ; i++){
    array_small[i] = rand() % 10;
  }

  srand(time(NULL));
  for(int i = 0 ; i < 1000 ; i++){
    array_small[i] = rand() % 10;
  }

  TimeStamp(array_small, 10);
  TimeStamp(array_mid, 100);
  TimeStamp(array_high, 1000);
    
  return 0;
}