#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node* next;
};

Node* head;

Node* newNode(int x) {
  Node* temp = new Node();
  temp -> data = x;
  temp -> next = NULL;
  return temp;
}

void insert(int x) {
  Node* temp = newNode(x);
  temp ->next = head;
  head = temp;
}

void print(Node *head) {
  Node* temp = head;
  if(temp==NULL) {
    return;
  }
  print(temp->next);
  cout<<temp->data<<" ";
}

int main() {
  head = NULL;
  insert(3);
  print(head);
  insert(5);
  print(head);
  insert(6);
  print(head);
  return 0;
}