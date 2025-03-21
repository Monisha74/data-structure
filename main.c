
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void convertToCircular(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty, can't convert to circular list.\n");
        return;
    }

    struct Node* temp = head;
    
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = head;
}

void displayCircularList(struct Node* head, int maxIterations) {
    if (head == NULL) {
        printf("The list is empty!\n");
        return;
    }

    struct Node* temp = head;
    int count = 0;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
        count++;
    } while (temp != head && count < maxIterations); 

    if (count >= maxIterations) {
        printf("...\n");
    } else {
        printf("(circular)\n");
    }
}

int main() {
    struct Node* head = NULL;
    int n, value;

    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        append(&head, value);
    }

    convertToCircular(head);

    printf("Circular Linked List: \n");
    displayCircularList(head, n);  

    return 0;
}
