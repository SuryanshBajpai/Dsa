#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

// Structure definition
struct {
    int list[MAX];
    int length;
} l;

// Function prototypes
int menu(void);
void create(void);
void insert(int, int);
void delet(int);
void find(int);
void display(void);
bool islistfull(void);
bool islistempty(void);

// Menu function
int menu() {
    int ch;
    printf("\n1. Create\n2. Insert\n3. Delete\n4. Count\n5. Find\n6. Display\n7. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &ch);
    return ch;
}

// Create list
void create(void) {
    int element;
    char choice;
    l.length = 0; // Reset the list
    do {
        if (islistfull()) {
            printf("List is full. Cannot add more elements.\n");
            break;
        }
        printf("Enter element: ");
        scanf("%d", &element);
        l.list[l.length] = element;
        l.length++;
        printf("Do you want to add another element? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
}

// Display list
void display(void) {
    if (islistempty()) {
        printf("List is empty.\n");
        return;
    }
    printf("List elements:\n");
    for (int i = 0; i < l.length; i++) {
        printf("Element %d: %d\n", i + 1, l.list[i]);
    }
}

// Insert into list
void insert(int element, int pos) {
    if (pos < 1 || pos > l.length + 1) {
        printf("Invalid position. Position should be between 1 and %d.\n", l.length + 1);
        return;
    }
    if (islistfull()) {
        printf("List is full. Cannot insert element.\n");
        return;
    }
    for (int i = l.length; i >= pos - 1; i--) {
        l.list[i + 1] = l.list[i];
    }
    l.list[pos - 1] = element;
    l.length++;
    printf("Element inserted successfully.\n");
}

// Delete from list
void delet(int pos) {
    if (pos < 1 || pos > l.length) {
        printf("Invalid position. Position should be between 1 and %d.\n", l.length);
        return;
    }
    for (int i = pos - 1; i < l.length - 1; i++) {
        l.list[i] = l.list[i + 1];
    }
    l.length--;
    printf("Element deleted successfully.\n");
}

// Find an element
void find(int element) {
    for (int i = 0; i < l.length; i++) {
        if (l.list[i] == element) {
            printf("Element %d found at position %d.\n", element, i + 1);
            return;
        }
    }
    printf("Element not found.\n");
}

// Check if list is full
bool islistfull(void) {
    return l.length == MAX;
}

// Check if list is empty
bool islistempty(void) {
    return l.length == 0;
}

// Main function
int main() {
    int ch, element, pos;
    l.length = 0; // Initialize list

    while (1) {
        ch = menu();
        switch (ch) {
        case 1:
            create();
            break;
        case 2:
            if (!islistfull()) {
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position to insert (1 to %d): ", l.length + 1);
                scanf("%d", &pos);
                insert(element, pos);
            } else {
                printf("List is full. Cannot insert element.\n");
            }
            break;
        case 3:
            if (!islistempty()) {
                printf("Enter position to delete (1 to %d): ", l.length);
                scanf("%d", &pos);
                delet(pos);
            } else {
                printf("List is empty. Cannot delete element.\n");
            }
            break;
        case 4:
            printf("Number of elements in the list: %d\n", l.length);
            break;
        case 5:
            printf("Enter element to find: ");
            scanf("%d", &element);
            find(element);
            break;
        case 6:
            display();
            break;
        case 7:
            printf("Exiting program. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
