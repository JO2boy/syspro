#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

void printStack() {
    struct node *current = top;
    printf("Print stack\n");
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int input;

    while (1) {
        if (scanf("%d", &input) != 1) {
            printStack();
            break;
        }

        if (input <= 0) {
            printStack();
            break;
        } else {
            push(input);
        }
    }

    while (top != NULL) {
        struct node *temp = top;
        top = top->next;
        free(temp);
    }

    return 0;
}

