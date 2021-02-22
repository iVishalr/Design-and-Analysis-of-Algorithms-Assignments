#include "sort.h"

int main(){

	for(int i = 1e5; i<=1e6; i+=5e4){
		double * array = create(i);
		if(i<=1.5e5) BubbleSort(array,i,10);
		else if(i>=2e5 && i<=3e5) BubbleSort(array,i,3);
		else if(i>3e5) BubbleSort(array,i,1);
		free(array);
		array = NULL;

		array = create(i);
		
		if(i<=2e5) SelectionSort(array,i,10);
		else if(i>2e5 && i<=4e5) SelectionSort(array,i,5);
		else if(i>4e5) SelectionSort(array,i,2);
		free(array);
		array = NULL;

		array = create(i);
		
		MergeSort(array,i,1000);
		free(array);
		array = NULL;

		array = create(i);
		QuickSort(array,i,1000);
		free(array);
		array = NULL;
	}
	return 0;
}
