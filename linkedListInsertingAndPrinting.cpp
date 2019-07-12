#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
};

struct Node *head;

Node* newNode(int x) {
  Node* temp = new Node();
  temp -> data = x; // another syntax will be (*temp).data = x;
  temp -> next = NULL; // another syntax will be (*temp).next = NULL;
  return temp;
}

void insert(int x) {
  Node *temp = newNode(x);
  temp -> next = head;
  head = temp;
}

void print() {
  Node *temp = head;
  while(temp!=NULL) {
    cout<<temp->data;
    temp = temp -> next;
  }
  cout<<endl;
}

int main() {
  head = NULL;
  insert(3);
  print();
  insert(5);
  print();
  insert(6);
  print();
  return 0;
}