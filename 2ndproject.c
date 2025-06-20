#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Global head pointer
struct Node* head = NULL;

// Function to insert node at the end
void insertNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        printf(" Node inserted as head.\n");
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    printf("Node inserted at the end.\n");
}

// Function to delete node by value
void deleteNode(int value) {
    if (head == NULL) {
        printf(" List is empty. Cannot delete.\n");
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    // If head needs to be deleted
    if (temp->data == value) {
        head = head->next;
        free(temp);
        printf(" Node with value %d deleted.\n", value);
        return;
    }

    // Search for the node to delete
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // Not found
    if (temp == NULL) {
        printf(" Value %d not found in the list.\n", value);
        return;
    }

    // Delete node
    prev->next = temp->next;
    free(temp);
    printf("Node with value %d deleted.\n", value);
}

// Function to display the list
void traverseList() {
    if (head == NULL) {
        printf("  List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf(" Linked List: ");
    while (temp != NULL) {
        printf("%d → ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value;

    do {
        printf("\n=============================\n");
        printf("SINGLY LINKED LIST - CODTECH\n");
        printf("=============================\n");
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Traverse List\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertNode(value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;
            case 3:
                traverseList();
                break;
            case 4:
                printf("✅ Program ended. Completion Certificate will be issued on your internship END DATE.\n");
                break;
            default:
                printf(" Invalid choice! Enter 1-4.\n");
        }
    } while (choice != 4);

    return 0;
}
