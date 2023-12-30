#include <stdio.h>char c[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'S'};
int e[8] = {2, 2, 2, 2, 2, 2, 3, 3};
int list[8][3] = {{3,7}, {4,7}, {5,7}, {0,6}, {1,6}, {2,6}, {3,4,5}, {0,1,2}};int checked[20];
int stk[20];
int top = 0;
void push(int n){
  checked[n] = 1;
  printf("%c  ", c[n]);	
  stk[top++] = n; 
}int pop(){
  //printf("%c ", c[que[first]]);
  top--;
  return stk[top];

}int notChecked(int n){
	if (checked[n] == 1){
		return 0;
	}
	return 1;
}int main(){   int i, n, f = 0;
   printf("\nOutput\n");
	
   push(7);

   while(top!=0){
	n = stk[top-1];
	for (i = 0; i <e[n]; i++){
		f = 0;
		if (notChecked(list[n][i]) == 1){
			push(list[n][i]);
			f = 1; 
			break;
		}
	}
	if (f == 0){
		pop();
	}
   }   
   return 0;}