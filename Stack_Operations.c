

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct stack {
    int data;
    struct stack* next;
} *top = NULL, *newNode;

struct stack1 {
    char data1;
    struct stack1* next1;
} *top1 = NULL, *newNode1;

struct stack3 {
    char stk[MAX];
    int top;
} s;

void printStack() {
    printf("------------------------------------------\n");
    printf("           Displaying The Stack\n");
    printf("------------------------------------------\n");

    struct stack* temp = top;
    if (temp == NULL) {
        printf("\nStack is empty");
    }
    while (temp != NULL) {
        printf("\n the stack is : %d ", temp->data);
        temp = temp->next;
    }
    printf("\n\n");
}

void push(int x) {
    newNode = (struct stack*)malloc(sizeof(struct stack));
    newNode->data = x;
    if (top == NULL) {
        newNode->next = NULL;
        top = newNode;
    } else {
        newNode->next = top;
        top = newNode;
    }
}

int pop() {
    struct stack* temp;
    int popped_element;
    if (top == NULL) {
        printf("\nStack is Empty\n");
        return -1;
    }
    if (top != NULL) {
        temp = top;
        top = top->next;
        popped_element = temp->data;
        free(temp);
        return popped_element;
    }
}

void push1() {
    newNode1 = (struct stack1*)malloc(sizeof(struct stack1));
    newNode1->data1 = '(';
    if (top1 == NULL) {
        newNode1->next1 = NULL;
        top1 = newNode1;
    } else {
        newNode1->next1 = top1;
        top1 = newNode1;
    }
}

int pop1() {
    struct stack1* temp1;
    if (top1 != NULL) {
        temp1 = top1;
        top1 = top1->next1;
        free(temp1);
    }
}

void push2(char item) {
    if (s.top == (MAX - 1))
        printf("Stack is Full\n");
    else {
        s.top = s.top + 1;
        s.stk[s.top] = item;
    }
}

void pop2() {
    if (s.top == -1) {
        printf("Stack is Empty\n");
    } else {
        s.top = s.top - 1;
    }
}

void stringValidity() {
    char exp[MAX];
    int i = 0;
    s.top = -1;
    printf("\nINPUT THE EXPRESSION: ");
    scanf("%s", exp);
    getchar(); // Consume the newline character
    for (i = 0; i < strlen(exp); i++) {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
            push2(exp[i]);
            continue;
        } else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
            if (exp[i] == ')') {
                if (s.stk[s.top] == '(') {
                    pop2();
                } else {
                    printf("\nParentheses are invalid\n");
                    exit(0);
                }
            }
            if (exp[i] == ']') {
                if (s.stk[s.top] == '[') {
                    pop2();
                } else {
                    printf("\nParentheses are invalid\n");
                    exit(0);
                }
            }
            if (exp[i] == '}') {
                if (s.stk[s.top] == '{') {
                    pop2();
                } else {
                    printf("\nParentheses are invalid\n");
                    exit(0);
                }
            }
        }
    }
    if (s.top == -1) {
        printf("\nParentheses are valid\n");
    } else
        printf("\nParentheses are invalid\n");
}
void reverseData() {
    int x, y = 0;
    printf("\nEnter the decimal number: ");
    scanf("%d", &x);

    while (x > 0) {
        push(x % 2);
        y++;
        x = x / 2;
    }

    printf("\nBinary representation: ");
    while (y > 0) {
        int binaryDigit = pop();
        printf("%d", binaryDigit);
        y--;
    }
    printf("\n");
}

int main() {
    int choice, data, n, popped_element;

    while (1) {
        printf("====================================================\n");
        printf("          Welcome to Stack Operation \n");
        printf("====================================================\n");
        printf(" 1. Push\n");
        printf(" 2. Pop\n");
        printf(" 3. Print Stack\n");
        printf(" 4. Checking Input String Validity\n");
        printf(" 5. Reverse Data\n");
        printf(" 6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an Integer in Stack: ");
                scanf("%d", &n);
                push(n);
                                 printf(" \t\n\n*** operation performed ***\n\n\t\t Stack has been updated !!!\t\n");

                break;
            case 2:
                popped_element = pop();
                if (popped_element != -1) {
                    printf("\n\nPopped element: %d\n", popped_element);
                }
                                 printf(" \t\n\n*** operation performed ***\n\n\t\t Stack has been updated !!!\t\n");

                break;
            case 3:
                printStack();
                                 printf(" \t\n\n*** operation performed ***\n\n\t\t Stack has been printed !!!\t\n");

                break;
            case 4:
                stringValidity();
                                 printf(" \t\n\n*** operation performed ***\n\n\t\t Stack  validity has been checked !!!\t\n");

                break;
            case 5:
                reverseData();
                                 printf(" \t\n\n*** operation performed ***\n\n\t\t reversed data  has been printed !!!\t\n");

                break;
            case 6:
               printf(" \t\n\n*** operation performed ***\n\n\t\t thank you !!!\t\n");
            printf(" PRESS 0 TO EXIT THE PROGRAME");
                exit(0);

            default:
                printf("Invalid Choice\n");
                printf("Try Again");
        }

        printf("\n");
    }

    return 0;
}
