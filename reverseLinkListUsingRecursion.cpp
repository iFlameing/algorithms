#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node* next;
};
struct Node* head = NULL;

Node* newNode(int x) {
  Node *temp = new Node();
  temp -> data = x;
  temp -> next = NULL;
  return temp;
}

void insert(int x) {
  Node *temp = newNode(x);
  temp->next = head;
  head = temp;
}

void print() {
  Node* temp = head;
  while(temp!=NULL){
    cout<<temp->data;
    temp = temp -> next;
  }
  cout<<endl;
}
void reverse(Node* head1) {
  Node* temp = head1;
  if(temp->next==NULL){
    head = temp;
    return;
  }
  reverse(temp->next);
  temp->next->next = temp;
  temp->next = NULL;
}

int main() {
  insert(3);
  insert(4);
  insert(5);
  print();
  reverse(head);
  print();
  return 0;
}