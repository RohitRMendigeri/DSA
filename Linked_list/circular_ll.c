#include <stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node *next;
    int data;
}node;


node* insertAtBegining(node *head , int val){
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = val;
    node *ptr = head;
    while(ptr->next != head){
        ptr = ptr->next;
    }
    ptr->next = newnode;
    newnode->next = head;
    head = newnode;
    return head;
}

node* insertAtEnd(node *head , int val){
    node* newnode = (node *)malloc(sizeof(node));
    newnode->data = val;
    node* ptr = head;
    do{
        ptr = ptr->next;
    }while(ptr->next != head);
    newnode->next = head;
    ptr->next = newnode;
    return head;
}

void display(node *head){
    node* ptr = head;
    do{
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }while(ptr!=head);
}

int main() {
    node *head = NULL;
    head = (node *)malloc(sizeof(node));
    head->data = 1;
    head->next = head;
    head = insertAtBegining(head,2);
    head = insertAtBegining(head,3);
    head = insertAtEnd(head , 5);
    head = insertAtEnd(head , 6);
    head = insertAtBegining(head,99);
    display(head);
    return 0;
}