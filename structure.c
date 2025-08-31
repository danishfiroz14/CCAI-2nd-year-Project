#include<stdio.h>

struct student{
    int roll;
    char name [20];
};
void display(struct student *p);

void main(){
    struct student s1 = {10, "Danish"};
    display(&s1);
}

void display(struct student *p){
    printf("%d\n", (*p).roll);
    printf("%s", p->name);
}