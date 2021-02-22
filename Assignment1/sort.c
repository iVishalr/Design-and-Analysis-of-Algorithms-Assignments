#include "sort.h"

void BubbleSort(double * A, int n, int iterations){
  clock_t start,end;
  double total_time = 0.0;
  double avg_time = 0.0;
  long long int comparisons = 0;
  long long int avg_comparisons = 0;
  
  for(int i=0;i<iterations;i++){
    start = clock();
    bubbleSort(A,n,&comparisons);
    end = clock();
    _SORT_CHECK_(A,n);
    for(int i=0; i<n;i++){
		  A[i] = rand();
	  }
    total_time += (double)(end-start)/CLOCKS_PER_SEC;
    avg_comparisons += comparisons;
    comparisons = 0;
  }
  avg_time = total_time/iterations;
  avg_comparisons /= iterations;
  printf("Bubble Sort\n-----------\n");
  printf("Size : %d\n",n);
  printf("Number of Comparisons Performed : %lld\n",avg_comparisons);
  printf("Total Time taken : %lf seconds\n",total_time);
  printf("Average time taken for single iteration : %lf seconds\n\n",avg_time);
  dump_file_time("./data/BubbleSort_size_vs_time.txt",n,avg_time);
  dump_file_comparisons("./data/BubbleSort_size_vs_comparisons.txt",n,avg_comparisons);
}

void bubbleSort(double * A, int n, long long int * comparisons){
  double temp=0.0;
  int i, j;
  for(i = 0; i < n - 1; i++){
    for(j = 0; j < n - i - 1; j++){
      if(A[j] > A[j + 1]){
        temp = A[j + 1];
        A[j + 1] = A[j];
        A[j] = temp;
      }
      *comparisons += 1;
    }
  }
}

void SelectionSort(double * A, int n, int iterations){
  clock_t start,end;
  double total_time = 0.0;
  double avg_time = 0.0;
  long long int comparisons = 0;
  long long int avg_comparisons = 0;
  for(int i=0;i<iterations;i++){
    start = clock();
    selectionSort(A,n,&comparisons);
    end = clock();
    _SORT_CHECK_(A,n);
    for(int i=0; i<n;i++){
		  A[i] = rand();
	  }
    total_time += (double)(end-start)/CLOCKS_PER_SEC;
    avg_comparisons += comparisons;
    comparisons = 0;
  }
  avg_time = total_time/iterations;
  avg_comparisons /= iterations;
  printf("Selection Sort\n--------------\n");
  printf("Size : %d\n",n);
  printf("Number of Comparisons Performed : %lld\n",avg_comparisons);
  printf("Total Time taken : %lf seconds\n",total_time);
  printf("Average time taken for single iteration : %lf seconds\n\n",avg_time);
  dump_file_time("./data/SelectionSort_size_vs_time.txt",n,avg_time);
  dump_file_comparisons("./data/SelectionSort_size_vs_comparisons.txt",n,avg_comparisons);
}

void selectionSort(double * A, int n, long long int * comparisons){
  for (int i = 0; i < n-1; i++){
    int min = i;
    for (int j = i + 1; j < n; j++){
      if (A[j] < A[min])
        min = j;
      *comparisons += 1;
    }
    double temp=A[min];
    A[min]=A[i];
    A[i]=temp;
  }
}


void QuickSort(double * A, int n, int iterations){
  clock_t start,end;
  double total_time = 0.0;
  double avg_time = 0.0;
  long long int comparisons = 0;
  long long int avg_comparisons = 0;
  for(int i=0;i<iterations;i++){
    start = clock();
    quickSort(A,0,n-1,&comparisons);
    end = clock();
    _SORT_CHECK_(A,n);
    for(int i=0; i<n;i++){
		  A[i] = rand();
	  }
    total_time += (double)(end-start)/CLOCKS_PER_SEC;
    avg_comparisons += comparisons;
    comparisons = 0;
  }
  avg_time = total_time/iterations;
  avg_comparisons /= iterations;
  printf("Quick Sort\n-----------\n");
  printf("Size : %d\n",n);
  printf("Number of Comparisons Performed : %lld\n",avg_comparisons);
  printf("Total Time taken : %lf seconds\n",total_time);
  printf("Average time taken for single iteration : %lf seconds\n\n",avg_time);
  dump_file_time("./data/QuickSort_size_vs_time.txt",n,avg_time);
  dump_file_comparisons("./data/QuickSort_size_vs_comparisons.txt",n,avg_comparisons);
}

void quickSort(double * A,int low, int high, long long int * comparisons){ 
  int j;
  if (low < high){
    j = partition(A, low, high, comparisons);
    quickSort(A, low ,j-1, comparisons);
    quickSort(A, j+1, high, comparisons);
  }
}

int partition(double * A, int low, int high, long long int * comparisons){
    double pivot = A[low];
    int i = low + 1;
    int j = high; 
    double temp;
    while(i <= j){    
      while(i <= high && A[i] <= pivot){ 
        i++;
        *comparisons += 1;
      }
      while(j > low && A[j] >= pivot){
          j--;
          *comparisons += 1;
      }
      if(i < j){
          temp = A[i];
          A[i] = A[j];
          A[j] = temp;
      }
    }
    if(j != low)
    {
      A[low] = A[j];
      A[j] = pivot;
    }
    return j;
}

void MergeSort(double * A, int n, int iterations){
  clock_t start,end;
  double total_time = 0.0;
  double avg_time = 0.0;
  long long int comparisons = 0;
  long long int avg_comparisons = 0;
  for(int i=0;i<iterations;i++){
    start = clock();
    mergeSort(A,0,n,&comparisons);
    end = clock();
    _SORT_CHECK_(A,n);
    for(int i=0; i<n;i++){
		  A[i] = rand();
	  }
    total_time += (double)(end-start)/CLOCKS_PER_SEC;
    avg_comparisons += comparisons;
    comparisons = 0;
  }
  avg_time = total_time/iterations;
  avg_comparisons /= iterations;
  printf("Merge Sort\n----------\nSize : %d\n",n);
  printf("Number of Comparisons Performed : %lld\n",avg_comparisons);
  printf("Total Time taken : %lf seconds\n",total_time);
  printf("Average time taken for single iteration : %lf seconds\n\n",avg_time);
  dump_file_time("./data/MergeSort_size_vs_time.txt",n,avg_time);
  dump_file_comparisons("./data/MergeSort_size_vs_comparisons.txt",n,avg_comparisons);
}

void merge(double * A, int l, int m, int r, long long int * comparisons){
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  double L[n1], R[n2];

  for (i = 0; i < n1; i++)
      L[i] = A[l + i];
  for (j = 0; j < n2; j++)
      R[j] = A[m + 1 + j];

  i = 0; j = 0; k = l;

  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    }
    else {
      A[k] = R[j];
      j++;
    }
    *comparisons += 1;
    k++;
  }
  while (i < n1) {
    A[k++] = L[i];
    i++;
  }
  while (j < n2) {
    A[k++] = R[j];
    j++;
  }
}

void mergeSort(double * A, int l, int r, long long int * comparisons){
  if (l < r){
    int m = l + (r - l) / 2;
    mergeSort(A, l, m, comparisons);
    mergeSort(A, m + 1, r, comparisons);
    merge(A, l, m, r, comparisons);
  }
}

double * create(int length){
  double * array = (double*)malloc(sizeof(double)*length);
	srand(0);
	for(int i=0; i<length;i++){
		array[i] = rand();
	}
  return array;
}

void _SORT_CHECK_(double * A,int length){
  int flag = 1;
  int index = 0;
  for(int i = 1; i<length; i++){
    if(A[i]<A[i-1]){ 
      index = i;
      flag = 0;
      break;
    }
  }
  if(flag==0){
    printf("\033[1;31mSorting Failed! : [INDEX = %d] \033[0m",index);
    printf("\033[1;32m%lf\033[1;96m < \033[1;31m%lf\n\033[0m",A[index-1],A[index]);
    exit(EXIT_FAILURE);
  }
}

void dump_file_time(char * filename, int size, double data){
  FILE * fp = NULL;
  // if( access(filename,F_OK)==0) {
  //   if(remove(filename)==0){}
  // }
  fp = fopen(filename,"a+");
  if(fp==NULL){
    printf("\033[1;31mFile Error : \033[93m Could not open the specified file!\033[0m\n");
    exit(EXIT_FAILURE);
  }
  fprintf(fp,"%d ",size);
  fprintf(fp,"%lf\n",data);
  fclose(fp);
  fp = NULL;
}

void dump_file_comparisons(char * filename, int size, long long int comparisons){
  FILE * fp = NULL;
  // if( access(filename,F_OK)==0) {
  //   if(remove(filename)==0){}
  // }
  fp = fopen(filename,"a+");
  if(fp==NULL){
    printf("\033[1;31mFile Error : \033[93m Could not open the specified file!\033[0m\n");
    exit(EXIT_FAILURE);
  }
  fprintf(fp,"%d ",size);
  fprintf(fp,"%lld\n",comparisons);
  fclose(fp);
  fp = NULL;
}