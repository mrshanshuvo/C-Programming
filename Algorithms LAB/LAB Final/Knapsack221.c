#include <stdio.h>

int W = 5;
int n = 4;

int max(int a, int b){
	return (a>b)? a : b;
}

int knapSack(int wt[], int val[]){

	int P[n+1][W+1];
	for (int i = 0; i<=n; i++){
		for (int w = 0; w<=W; w++){
			if (i == 0 || w == 0){
				P[i][w] = 0;
			}
			else if (wt[i - 1] <= w){
				P[i][w] = max(val[i - 1] + P[i-1][w-wt[i-1]], P[i-1][w]);
			}
			else {P[i][w] = P[i-1][w];}
		}
	}
	
	return P[n][W];
}int main (){

	int val[n];
	int wt[n];
	
	printf("Please enter the values for each item: ");
	for (int i = 0; i<n; i++){
   		scanf("%d", &val[i]);
	} 
	printf("Please enter the weight for each item: ");
	for (int i = 0; i<n; i++){
   		scanf("%d", &wt[i]);
	}  

	printf("Maximum Profit = %d", knapSack(wt, val));


 return 0;

}