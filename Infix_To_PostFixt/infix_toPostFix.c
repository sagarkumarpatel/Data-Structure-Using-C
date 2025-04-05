#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack
{
    int top;
    int size;
    char *arr;
};

struct stack *createStack(int size)
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = size;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));
    return s;
}
int isFull(struct stack *s)
{
    return s->top == s->size - 1;
}
int isEmpty(struct stack *s)
{
    return s->top == -1;
}

void push(struct stack *s, char ch)
{
    if (isFull(s))
    {
        printf("Stack overFlow! Can't push\n");
        return;
    }
    s->top++;
    s->arr[s->top] = ch;
}

char pop(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is Emoty! Nothing to pop\n");
        return '\0';
    }
    return s->arr[s->top--];
}
char top(struct stack *s)
{
    if (isEmpty(s))
    {
        return '\0';
    }
    return s->arr[s->top];
}
int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int precedence(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '^')
    {
        return 3;
    }
    else
    {
        return 0;
    }
}
char *infixToPostFix(char *infix)
{
    struct stack *s = createStack(strlen(infix));
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0;
    int j = 0;
    while (infix[i] != '\0')
    {
        char current = infix[i];
        if (!isOperator(current) && current != '(' && current != ')')
        {
            postfix[j++] = current;
            i++;
        }
        else if (current == '(')
        {
            push(s, current);
            i++;
        }
        else if (current == ')')
        {
            while (!isEmpty(s) && top(s) != '(')
            {
                postfix[j++] = pop(s);
            }
            if (!isEmpty(s))
            {
                pop(s);
            }
            i++;
        }
        else
        {
            while (!isEmpty(s) && precedence(current) <= precedence(top(s)) && top(s) != '(')
            {
                postfix[j++] = pop(s);
            }
            push(s, current);
            i++;
        }
    }
    while (!isEmpty(s))
    {
        postfix[j++] = pop(s);
    }
    postfix[j] = '\0';
    return postfix;
}
int main()
{
    char *infix = "(A+B)*C";
    printf("The postfix expression is: %s", infixToPostFix(infix));
    return 0;
}