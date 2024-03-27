#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of the list
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

// Function to print the list in rows of 5
void printList(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        printf("%4d ", head->data);
        head = head->next;
        count++;
        if (count % 5 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

// Function to perform bubble sort on the linked list
struct Node* bubbleSort(struct Node* head) {
    int swapped, i;
    struct Node *ptr1, *lptr = NULL;

    // If the list is empty or has only one element, it is already sorted
    if (head == NULL || head->next == NULL)
        return head;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                // Swap the data of two nodes
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);

    return head;
}

int main() {
    srand(time(NULL));  // Seed for random number generation

    struct Node* head = NULL;

    // Generate and insert 100 random integers into the linked list
    for (int i = 0; i < 100; ++i) {
        int randomNumber = rand() % 1000;
        head = insertAtBeginning(head, randomNumber);
    }

    printf("Original List:\n");
    printList(head);

    // Sort the list using bubble sort
    head = bubbleSort(head);

    printf("\nSorted List:\n");
    printList(head);

    return 0;
}