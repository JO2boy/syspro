#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void addq(struct node **head, struct node **tail, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (*tail == NULL) {
        *head = newNode;
        *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

void printQueue(struct node *head) {
    struct node *current = head;
    printf("Print queue\n");
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeQueue(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        struct node *temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct node *head = NULL;
    struct node *tail = NULL;
    char input[100];

    while (1) {
        scanf("%s", input);
        char *endptr;
        int number = strtol(input, &endptr, 10);

        if (*endptr != '\0') {
            printQueue(head);
            freeQueue(head);
            break;
        }

        if (number > 0) {
            addq(&head, &tail, number);
        }
    }

    return 0;
}

