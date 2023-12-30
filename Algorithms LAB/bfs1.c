#include<stdio.h>
#include<string.h>
char vertex[5] = {'1','2','3','4','5'};
int edge[5] = {3,1,1,1,1};
int list[8][3] = {{1,2,3},{2},{1},{3},{2}};
int checked[20], queue[20], first=0, last=0;
void enqueue(int n){
    checked[n] = 1;
    queue[last++] = n;
}
int dequeue(){
    printf("%c ",vertex[queue[first]]);
    first++;
    return queue[first-1];
}
int notChecked(int n){
    if(checked[n] ==1)
        return 0;
    return 1;
}
int main(){
    enqueue(0);
    while (first < last){
        int n = dequeue();
        for(int i=0; i<edge[n]; i++){
            if(notChecked(list[n][i]) == 1)
                enqueue(list[n][i]);
        }
    }
    enqueue(4);
    while (first < last){
        int n = dequeue();
        for(int i=0; i<edge[n]; i++){
            if(notChecked(list[n][i]) == 1)
                enqueue(list[n][i]);
        }
    }
}