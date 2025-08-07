#include <stdio.h>
#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

void insertFront(int item) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Deque Overflow\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }
    deque[front] = item;
}

void insertRear(int item) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Deque Overflow\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = item;
}

void deleteFront() {
    if (front == -1) {
        printf("Deque Underflow\n");
        return;
    }
    printf("Deleted from front: %d\n", deque[front]);
    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}

void deleteRear() {
    if (front == -1) {
        printf("Deque Underflow\n");
        return;
    }
    printf("Deleted from rear: %d\n", deque[rear]);
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
}

void display() {
    int i;
    if (front == -1) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque: ");
    if (front <= rear) {
        for (i = front; i <= rear; i++)
            printf("%d ", deque[i]);
    } else {
        for (i = front; i < MAX; i++)
            printf("%d ", deque[i]);
        for (i = 0; i <= rear; i++)
            printf("%d ", deque[i]);
    }
    printf("\n");
}

int main() {
    insertRear(10);
    insertRear(20);
    insertFront(5);
    display();
    deleteFront();
    display();
    deleteRear();
    display();
    return 0;
}
