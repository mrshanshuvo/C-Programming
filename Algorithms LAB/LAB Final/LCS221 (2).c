#include <limits.h>#include <stdbool.h>#include <stdio.h>#define len1 7
#define len2 6
int max(int a, int b){
	return (a > b)? a : b;
}

int lcs(char X[], char Y[]){

	int m = len1, n = len2;
	int P[m+1][n+1];
	
        for (int j = 0; j<=n; j++){if (j != 0) printf("%c ", Y[j-1]); else printf("     ");}
	 printf("\n");
        for (int i = 0; i<=m; i++){
		if (i != 0) printf(" %c ", X[i-1]); else printf("   ");
		for (int j = 0; j<=n; j++){
			if (i == 0 || j == 0){
				P[i][j] = 0;
			}
			else if (X[i-1] == Y[j-1]){
				P[i][j] = 1 + P[i-1][j-1];
			}
			else {
				P[i][j] = max(P[i-1][j], P[i][j-1]);
			}
			printf("%d ", P[i][j]);
		}
		printf("\n");

	}
		
	return P[m][n];
}int main(){    char X[] = "ABCBDAB";
    char Y[] = "BDCABA";

    printf ("Length of LCS is: %d\n", lcs(X, Y)); 		    return 0;}
