// In a group of 10 people, if everyone shakes hands with everyone else
// exactly once, how many handshakes took place?



#include<stdio.h>

int handshake(int n);
int main(){
    int n = handshake(5);
    printf("%d", n);
    return 0;
}

int handshake(int n){
    if (n==1)
        return 0;
    else
        return handshake(n-1) + n-1 ;
    return 0;
}