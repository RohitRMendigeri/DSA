#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
  int data;
  Node *next;
  Node(int value){
    this->data = value;
    next = NULL;
  }
};



Node *InsertAtEnd(Node* head){
   Node* temp;
    int arr[] = {2,4,6,8,10};
    for(int i = 0 ; i < 5 ; i++){
      if(head == NULL){
        head = new Node(arr[i]);
        temp = head;
      }
      else{
        
        temp->next= new Node(arr[i]);
         temp = temp->next;
      }
    }

     temp = head;
    while(temp){
      cout << temp->data << " ";
      temp = temp->next;
    }
     return head;
}

Node *InsertAtBegining(Node *head){
     Node* temp = NULL; 
     int arr[] = {2,4,6,8,10};
     for(int i = 0 ; i < 5 ; i++){
      if(head == NULL){
        head = new Node(arr[i]);
        temp = head;
      }else{
        temp = new Node(arr[i]);
        temp->next = head;
        head = temp;
      }
     }

     temp = head;
    while(temp){
      cout << temp->data << " ";
      temp = temp->next;
    }
     return head;
}



Node* InsertAtPos(Node* head){
  int x = 3;
  x--;
  Node* temp = head;

  while(x--){
      temp = temp->next;
  }

  Node* temp2 = new Node(30);
  temp2->next = temp->next;
  temp->next = temp2;

  return head;

}


Node* CreateList(int arr[],int index, int size){
    if(index == size){
      return NULL;
    }
    Node* temp = new Node(arr[index]);
    temp->next = CreateList(arr,index+1,size);
    return temp;
}

Node* CreateListFromBgn(int arr[],int index, int size,Node* prv){
  if(index == size){
    return prv;
  }
  Node* temp = new Node(arr[index]);
  temp->next = prv;
  return CreateListFromBgn(arr,index+1,size,temp);
}


int main(){
    Node* head = NULL;
    // Node* temp = new Node(30);
    // cout << temp->data << endl;
    //  head = InsertAtEnd(head); 
    
    //  head = InsertAtBegining(head); 
    //  cout << endl;
    //  head = InsertAtPos(head);

     int arr[] = {2,4,6,8,10};
 //    head = CreateList(arr,0,5); // recursion insert at end 
     head = CreateListFromBgn(arr,0,5,head); // insert at begining 
     Node *temp = head;
    while(temp){
      cout << temp->data << " ";
      temp = temp->next;
    }
    
  }