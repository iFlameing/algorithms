#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *next;
};

Node* newNode(int x) {
  Node* temp = new Node();
  temp -> data = x;
  temp -> next = NULL;
  return temp;
}

void insert(Node** head,int x) { // we can change this to Node* insert(Node* head)
  Node *temp = new Node();       // and we have to return head; for below explanation
  temp -> data = x;
  temp -> next = *head;
  *head = temp;
}

void print(Node *head) {
  Node *temp = head;
  while(temp!= NULL) {
    cout<<temp -> data;
    temp = temp ->next;
  }
  cout<<endl;
}

int main() {
  Node *head;
  head = NULL;
  insert(&head,3); // we can also do this like head = insert(head, 3);
  print(head);     // for this we have to change the insert function;
  insert(&head,5);
  print(head);
  insert(&head,6);
  print(head);
  return 0;
}