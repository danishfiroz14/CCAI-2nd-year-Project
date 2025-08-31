#include<stdio.h>
int main(){
    int a[10] = {10, 20, 30, 40 , 50};
    int a2[10];
    int size = 5;
    for (int i = size-1; i<=0; i--){
        a2[i] = a[i];
    }
    for (int i = 0; i<size; i++){
        printf("%d\n", a2[i]);
    }

    return 0;
}