#include <stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}node;

node *insertAtBeginning(node *head, int data){
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = head;
    return newnode;
}

node* insertAtPosition(node *head , int data , int index){
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    node *temp = head;
    int i = 0;
    while(i != index -1){
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    return head;

}

node* deleteAtFirst(node* head){
    node *temp = head; 
    head =  head->next;
     free(temp);
    return head;
}

node* insertAtEnd(node *head,int data){
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = NULL;
    return head;

}

node* deleteAtPosition(node* head,int index){
    node* p = head;
    node* q = head->next;
    for(int i = 0 ; i < index - 1 ; i++){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

node* deleteAtEnd(node* head){
    node* p = head;
    node* q = head->next;
    while(q->next != NULL){
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

node* deleteNodeValue(node* head , int val){
    if(head->data == val){
      printf("hi");
      return deleteAtFirst(head);
    }
    node* p = head;
    node* q = head->next;
    while(q->data != val && q->next != NULL){
        p = p->next;
        q = q->next;
    }
    if(q->data == val){
        p->next = q->next;
        free(q);
    }
    return head;

}

void display(node* head){
    node* temp = head;
    while(temp != NULL){
        printf(" element is : %d\n",temp->data);
        temp = temp->next;
    }
}

int main() {
     node *head = NULL;
     head = insertAtBeginning(head,5);
     head = insertAtBeginning(head,4);
     head = insertAtBeginning(head,2);
     head = insertAtBeginning(head,1);
     head = insertAtPosition(head,3,2);
     head = insertAtEnd(head, 6);
     head = insertAtEnd(head, 6);
    // head = deleteAtFirst(head);
    // head = deleteAtPosition(head,4);
    // head = deleteAtEnd(head);
     head = insertAtBeginning(head,4);
    head = insertAtEnd(head, 99);
    head = deleteNodeValue(head,4);


     display(head);
    return 0;
}

