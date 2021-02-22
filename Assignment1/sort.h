#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void BubbleSort(double * A, int n, int iterations);
void SelectionSort(double * A, int n, int iterations);
void QuickSort(double * A, int n, int iterations);
void MergeSort(double * A, int n, int iterations);

void bubbleSort(double * A, int n,long long int * comparisons);
void selectionSort(double * A, int n, long long int * comparisons);
int partition(double * A, int low, int high, long long int * compariosns);
void quickSort(double * A,int low, int high, long long int * comparisons);
void mergeSort(double * A, int l, int r, long long int * comparisons);
void merge(double * A, int l, int m, int r, long long int * comparisons);

double * create(int length);
void _SORT_CHECK_(double * vector,int length);
void dump_file_time(char * filename,int size, double data);
void dump_file_comparisons(char * filename, int size, long long int comparisons);

#endif //SORT_H