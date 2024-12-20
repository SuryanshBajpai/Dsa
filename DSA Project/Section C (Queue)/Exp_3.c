#include <stdio.h>
#define SIZE 5
typedef struct CircularQueue {
    int items[SIZE];
    int front, rear;
} CircularQueue;
void initializeQueue(CircularQueue* q) {
    q->front = -1;
    q->rear = -1;
}
int isFull(CircularQueue* q) {
    return ((q->rear + 1) % SIZE == q->front);
}
int isEmpty(CircularQueue* q) {
    return (q->front == -1);
}
void enqueue(CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue %d.\n", value);
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % SIZE;
    q->items[q->rear] = value;
    printf("Enqueued %d\n", value);
}
int dequeue(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int value = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1; // Queue becomes empty
    } else {
        q->front = (q->front + 1) % SIZE;
    }
    printf("Dequeued %d\n", value);
    return value;
}
// Function to display the queue
void displayQueue(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Circular Queue: ");
    int i = q->front;
    do {
        printf("%d ", q->items[i]);
        i = (i + 1) % SIZE;
    } while (i != (q->rear + 1) % SIZE);
    printf("\n");
}
int main() {
    CircularQueue q;
    initializeQueue(&q);
    // Test the Circular Queue
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    displayQueue(&q);
    dequeue(&q);
    dequeue(&q);
    displayQueue(&q);
    enqueue(&q, 60);
    enqueue(&q, 70);
    displayQueue(&q);
    enqueue(&q, 80); // This should show "Queue is full"
    return 0;
}
