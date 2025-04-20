#include <stdio.h>
#include <stdlib.h>

struct Node {
 int data;
 struct Node* next;
};

struct Node* head = NULL;

void insertAtEnd(int value) {
 struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
 newNode->data = value;
 newNode->next = NULL;
 if (head == NULL) {
 head = newNode;
 } else {
 struct Node* temp = head;
 while (temp->next != NULL) {
 temp = temp->next;
 }
 temp->next = newNode;
 }
 printf("Inserted: %d\n", value);
}

void deleteNode(int value) {
 struct Node* temp = head;
 struct Node* prev = NULL;
 if (head == NULL) {
 printf("List is empty!\n");
 return;
 }

 if (head->data == value) {
 head = head->next;
 free(temp);
 printf("Deleted: %d\n", value);
 return;
 }

 while (temp != NULL && temp->data != value) {
 prev = temp;
 temp = temp->next;
 }

 if (temp == NULL) {
 printf("Value not found!\n");
 return;
 }

 prev->next = temp->next;
 free(temp);
 printf("Deleted: %d\n", value);
}


void display() {
 struct Node* temp = head;
 if (head == NULL) {
 printf("List is empty!\n");
 return;
 }

 printf("Linked List: ");
 while (temp != NULL) {
 printf("%d -> ", temp->data);
 temp = temp->next;
 }
 printf("NULL\n");
}

int main() {
 int choice, value;
 while (1) {
 printf("\nMenu:\n");
 printf("1. Insert at End\n");
 printf("2. Delete a Node\n");
 printf("4. Display List\n");
 printf("5. Exit\n");
 printf("Enter choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("Enter value to insert: ");
 scanf("%d", &value);
 insertAtEnd(value);
 break;
 case 2:
 printf("Enter value to delete: ");
 scanf("%d", &value);
 deleteNode(value);
 break;

 case 4:
 display();
 break;
 case 5:
 printf("Exiting...\n");
 return 0;
 default:
 printf("Invalid choice! Try again.\n");
 }
 }
}
