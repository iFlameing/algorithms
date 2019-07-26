#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node* next;
};

Node* head = NULL;

Node* newNode(int x) {
  Node* temp = new Node();
  temp -> data = x;
  temp -> next = NULL;
  return temp;
}

void Push(int x) {
  Node* temp = newNode(x);
  temp -> next = head;
  head = temp;
}

int isEmpty() {
  return head == NULL ? 0 : 1;
}

int Top() {
  return head->data;
}

void POP() {
  Node *temp = head;
  head = temp -> next;
  free(temp);
}

void print() {
  Node *temp = head;
  while(temp!=NULL) {
    cout<<temp -> data;
    temp = temp -> next;
  }
  cout<<endl;
}

int main() {

  Push(3);
  Push(4);
  Push(5);
  print();
  int top = Top();
  int empty = isEmpty();
  cout<<top<<empty<<endl;
  POP();
  print();
  return 0;
}