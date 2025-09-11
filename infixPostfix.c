#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

// Stack for characters (operators)
char stack[MAX];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

int precedence(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}

// Function to convert Infix to Postfix
void infixToPostfix(char infix[], char postfix[]) {
    char x;
    int i = 0, k = 0;

    while (infix[i] != '\0') {
        if (isalnum(infix[i])) {
            postfix[k++] = infix[i];  // If operand, add to output
        }
        else if (infix[i] == '(') {
            push(infix[i]);
        }
        else if (infix[i] == ')') {
            while ((x = pop()) != '(') {
                postfix[k++] = x;
            }
        }
        else { // operator
            while (precedence(stack[top]) >= precedence(infix[i])) {
                postfix[k++] = pop();
            }
            push(infix[i]);
        }
        i++;
    }
    while (top != -1) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
}

// Stack for integers (evaluation)
int evalStack[MAX];
int evalTop = -1;

void evalPush(int x) {
    evalStack[++evalTop] = x;
}

int evalPop() {
    return evalStack[evalTop--];
}

// Function to evaluate Postfix expression
int evaluatePostfix(char postfix[]) {
    int i = 0;
    int a, b;
    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            evalPush(postfix[i] - '0');  // Convert char to int
        }
        else {
            b = evalPop();
            a = evalPop();
            switch (postfix[i]) {
                case '+': evalPush(a + b); break;
                case '-': evalPush(a - b); break;
                case '*': evalPush(a * b); break;
                case '/': evalPush(a / b); break;
            }
        }
        i++;
    }
    return evalPop();
}

// Main function
int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix Expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Evaluated Result: %d\n", result);

    return 0;
}
