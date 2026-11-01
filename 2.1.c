
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

int top = -1;
char infix[MAX];
char stack[MAX];
int prec(char c);
void push(char c);

int main(){

    printf("enter infix expression ... : ");
    scanf("%99s", infix);

    for(int i=0; infix[i]!='\0'; i++)
    {
        char c = infix[i];
        if(isalnum((unsigned char)c))
        {
            printf("%c", c);
        }

        else if(c == '(')
        {
            stack[++top] = c;
        }

        else if(c == ')')
        {
            while(top != -1 && stack[top] != '(')
            {
                printf("%c", stack[top--]);
            }
            if(top == -1){
                printf("\n Invalid expression!!!");
                return 1;}
            top--;
        }
        else if( c=='+' || c=='-' || c=='*' || c=='/' || c=='^')
            push(c);

        else{
            printf("\n Invalid symbol!!!");
            return 1;
        }
    }

    while( top != -1 )
    {
        if( stack[top] == '(')
        {
            printf("\nInvalid expression!!!!");
            return 1;
        }

        printf("%c", stack[top--]);
    }

    printf("\n");

    return 0;
}


int prec(char c){

    if(c == '^')
        return 3;

    else if(c=='*' || c=='/')
        return 2;

    else if(c=='+' || c=='-')
        return 1;

    return 0;
}


void push(char c)
{    while(top != -1 && stack[top] != '(' &&
          (prec(stack[top]) > prec(c) ||
          (prec(stack[top]) == prec(c) && c != '^')))
    {
        printf("%c", stack[top--]);
    }

    stack[++top] = c;
}
