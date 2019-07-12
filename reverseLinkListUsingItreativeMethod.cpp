#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *next;
};

Node* head = NULL;

Node* newNode(int x) {
  Node* temp = new Node();
  temp -> data = x;
  temp -> next = NULL;
  return temp;
}

void insert(int x) {
  Node* temp = newNode(x);
  temp -> next = head;
  head = temp;
}

void reverse(){
  Node* temp = head;
  Node* prev = NULL;
  Node* next;
  while(temp->next!=NULL){
    next = temp->next;
    temp->next = prev;
    prev = temp;
    temp = next;
  }
  head = temp;
  temp->next = prev;
}

void print() {
  Node* temp = head;
  while(temp!=NULL) {
    cout<<temp-> data;
    temp = temp->next;
  }
  cout<<endl;
}

int main(){
  insert(3);
  insert(5);
  insert(6);
  print();
  reverse();
  print();
}