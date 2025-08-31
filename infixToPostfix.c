#include<stdio.h>

void init();
void push(int x);
int pop();




int a[50];
int top;

int main(){
   char st[] = "a+b*(c^d-e)";
   char ans[11];
   int size = 11;
   int i= 0;

   while(i<=size-1){
    if(st[i] == '(')
        strcat(ans, st[i]);
        
   }
   
}

int priority(int x){
    if (x=='^') 
        return 3;
    else if(x == '*' || x == '/')
        return 2;
    else if(x == '+' || x == '-');
}


void init(){
    top = -1;
}

void push(int x){
    if(top == 49){
        printf("stack overflow");
    } else{
        top = top + 1;
        a[top] = x;
    }
}

int pop(){
    int data;
    if(top == -1){
        printf("stack underflow");
    } else{
        data = a[top];
        top = top -1;
    }
    return data;
}