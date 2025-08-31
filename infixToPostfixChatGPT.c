//9th July : 7:07 PM
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

//stack structure for characters
typedef struct{
    char items[MAX];
    int top;
} Stack;

//Initialize the stack
void initStack(Stack *s){
    s->top = -1;
}

//check if stack is empty
int isEmpty(Stack *s){
    return s->top == -1;
}

//check if stack is full
int isFull(Stack *s){
    return s->top == MAX - 1;
}

//push an element onto the stack
void push(Stack *s, char c){
    if(isFull(s)){
        printf("Stack overflow! Cannot push %c\n", c);
        exit(EXIT_FAILURE); //
    }
    s->items[++(s->top)] = c; //
}

//Pop an element from the stack
char pop(Stack *s){
    if(isEmpty(s)){
        printf("Stack underflow!\n");
        exit(EXIT_FAILURE);
    }
    return s->items[(s->top)--]; //
}

//Peek at top element of stack without popping
char peek(Stack *s){
    if(isEmpty(s)){
        return '\0'; //
    }
    return s->items[s->top];
}

//Return precedence of Operators
int precedence(char op){
    switch(op){
        case '+':
        case '-':return 1;
        case '*':
        case '/':return 2;
        case '^':return 3;
    }
    return 0;
}

//Check if character is an operator
int isOperator(char c){
    return (c== '+' || c == '-' || c=='*' || c=='/' || c== '^');
}

int isOperand(char c) {
    return (c >= '0' && c <= '9') ||  // digit
           (c >= 'A' && c <= 'Z') ||  // uppercase
           (c >= 'a' && c <= 'z');    // lowercase
}

//Convert infix expression to postfix
void infixToPostfix(const char *infix, char *postfix){
    Stack s;
    initStack(&s);
    int k = 0;
    for(int i = 0; infix[i]!='\0'; i++){
        char c = infix[i];
        
        //if whitespace , skip
        if(c == ' ' || c=='\t') continue; //notice

        //if operand, add to postfix
        if(isOperand(c)){
            postfix[k++] = c;
        }

        //If '(' , push to Stack
        else if (c == '('){
            push(&s, c);
        }

        //If ')', pop until '('
        else if (c == ')'){
            while ( !isEmpty(&s) && peek(&s)){
                postfix[k++] = pop(&s);
            }
            if(!isEmpty(&s) && peek(&s) =='('){
                pop(&s); //Remove '('
            } else{
                printf("Mismatched parenthesis\n");
                exit(EXIT_FAILURE);
            }
        }
        //if operator
       else if (isOperator(c)) {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(c) && peek(&s) != '(') {
                postfix[k++] = pop(&s);
            }
            push(&s, c);
        }else {
            printf("Invalid character encountered: %c\n", c);
            exit(EXIT_FAILURE);
        }
        // Pop any remaining operators
        while (!isEmpty(&s)) {
            if (peek(&s) == '(') {
                printf("Mismatched parentheses\n");
                exit(EXIT_FAILURE);
            }
            postfix[k++] = pop(&s);
        }

    postfix[k] = '\0';
    }
}

int main(){
    char infix[MAX];
    char postfix[MAX];

    printf("Enter infix expression: ");
    if(!fgets(infix, sizeof(infix), stdin)){
        printf("Error reading input. \n");
        return EXIT_FAILURE;
    }


    infixToPostfix(infix, postfix);
    printf("Postfix Expression : %s\n", postfix);

    return EXIT_SUCCESS;
}