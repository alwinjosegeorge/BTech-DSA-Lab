#include <stdio.h>
#include <stdlib.h>

int *deque;
int front = -1;
int rear = -1;
int MAX_SIZE;

int isFull() {
    return (front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1);
}

int isEmpty() {
    return front == -1;
}

void addFront(int data) {
    if (isFull()) {
        printf("Deque is full! Cannot add at front.\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX_SIZE - 1;
    } else {
        front--;
    }
    deque[front] = data;
}

void addRear(int data) {
    if (isFull()) {
        printf("Deque is full! Cannot add at rear.\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (rear == MAX_SIZE - 1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = data;
}

void removeFront() {
    if (isEmpty()) {
        printf("Deque is empty! Cannot remove from front.\n");
        return;
    }
    printf("Removed %d from the front.\n", deque[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
}

void removeRear() {
    if (isEmpty()) {
        printf("Deque is empty! Cannot remove from rear.\n");
        return;
    }
    printf("Removed %d from the rear.\n", deque[rear]);
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX_SIZE - 1;
    } else {
        rear--;
    }
}

void display() {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Deque elements: ");
    int i = front;
    while (i != rear) {
        printf("%d ", deque[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", deque[rear]);
}

int main() {
    int val, choice;
    printf("Enter the size of the deque: ");
    scanf("%d", &MAX_SIZE);

    deque = (int *)malloc(MAX_SIZE * sizeof(int));
    if (deque == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    while (1) {
        printf("\n--- DEQUE Operations ---\n");
        printf("1. Add front\n2. Add rear\n3. Remove front\n4. Remove rear\n5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to add at front: ");
                scanf("%d", &val);
                addFront(val);
                display();
                break;
            case 2:
                printf("Enter value to add at rear: ");
                scanf("%d", &val);
                addRear(val);
                display();
                break;
            case 3:
                removeFront();
                display();
                break;
            case 4:
                removeRear();
                display();
                break;
            case 5:
                free(deque);
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
