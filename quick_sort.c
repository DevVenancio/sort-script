#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void QuickSort(int arr[], int begin, int end) {
  // Encerro minha recursão a partir do momento em que minha posição inicial se torna MAIOR ou IGUAL à última posição.
  if(begin < end){
    // Defino um elemento central para ser trabalhado.
    int pivot = Partition(arr, begin, end);

    // Realizo minha recursão
    QuickSort(arr, begin, pivot - 1);
    QuickSort(arr, pivot + 1, end);

  }

}

int Partition(int arr[], int begin, int end) {

  // Seleciono o último elemento para ser o "pivô"
  int number = arr[end];

  // Defino minha posição inicial sendo sempre o número anterior ao primeiro do array.
  int i = begin - 1;

  for(int j = begin ; j <= end - 1 ; j++){
    // Caso o número encontrado na posição J seja menor ao meu "pivô"...
    if(arr[j] < number){
      // Efetuo a troca de posições
      i++;
      int aux = arr[i];
      arr[i] = arr[j];
      arr[j] = aux;
    }
  }

  int aux = arr[end];
  arr[end] = arr[i + 1];
  arr[i + 1] = aux;

  return i + 1;

}

int main(int argc, char const *argv[])
{
  clock_t start, end;
  double cpu_time_used;

  int small_array[10];
  int mid_array[100];
  int large_array[1000];

  // População dos Arrays
  srand(time(NULL));
  for (int i = 0; i < 10; i++){
    small_array[i] = rand() % 10;
  }

  srand(time(NULL));
  for (int i = 0; i < 100; i++){
    small_array[i] = rand() % 100;
  }

  srand(time(NULL));
  for (int i = 0; i < 1000; i++){
    small_array[i] = rand() % 1000;
  }
  
  // Começo o monitoramento
  start = clock();
  QuickSort(small_array, 0, 10 - 1);
  end = clock();
  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Array de 10 posições: %f secs\n", cpu_time_used);

  start = clock();
  QuickSort(mid_array, 0, 100 - 1);
  end = clock();
  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Array de 100 posições: %f secs\n", cpu_time_used);

  start = clock();
  QuickSort(large_array, 0, 1000 - 1);
  end = clock();
  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Array de 1000 posições: %f secs\n", cpu_time_used);

  return 0;

}
