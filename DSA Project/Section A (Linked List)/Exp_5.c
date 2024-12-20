#include <stdio.h>
#include <stdlib.h>

// Node structure for the circular doubly linked list
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = newNode;
    newNode->next = newNode;
    return newNode;
}

// Function to insert a node at the end of the list
void insertEnd(Node** head, int data) {
    Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* tail = (*head)->prev;

    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = *head;
    (*head)->prev = newNode;
}

// Function to delete a node from the list
void deleteNode(Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* current = *head;
    Node* prevNode = NULL;

    do {
        if (current->data == key) {
            if (current->next == current) { // Only one node in the list
                free(current);
                *head = NULL;
                return;
            }

            if (current == *head) {
                *head = current->next;
            }
            prevNode = current->prev;
            prevNode->next = current->next;
            current->next->prev = prevNode;
            free(current);
            return;
        }
        current = current->next;
    } while (current != *head);
    printf("Node with value %d not found.\n", key);
}
void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    printf("Circular Doubly Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
int main() {
    Node* head = NULL;
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);
    displayList(head);
    printf("Deleting node with value 20.\n");
    deleteNode(&head, 20);
    displayList(head);
    // Delete another node
    printf("Deleting node with value 10.\n");
    deleteNode(&head, 10);
    displayList(head);
    while (head != NULL) {
        deleteNode(&head, head->data);
    }
    return 0;
}
