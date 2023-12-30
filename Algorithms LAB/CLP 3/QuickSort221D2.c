#include <stdio.h>int A[10];

void swap(int i, int j){
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

int Partition(int left, int right){
	
	int x = A[right];
	int i = left - 1;
	for (int j = left; j<right; j++){
		if (A[j] <= x){
			i++;
			swap(i, j);
		}
	} 
	swap(i+1, right);
	return (i+1);
}void QuickSort(int left, int right){

	if (left < right){
		int q = Partition(left, right);
		QuickSort(left, q-1);
		QuickSort(q+1, right);
	} 
}int main(){   int i;
   for(i = 0; i<9; i++){
       scanf("%d", &A[i]);
   }
   
   QuickSort(0,8);

   printf("\nOutput\n");
   for (i = 0; i<9; i++){
          printf("%d ",A[i]);
       printf("\n");
   }      return 0;}