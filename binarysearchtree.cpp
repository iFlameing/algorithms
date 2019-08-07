#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node* left;
  struct Node* right; 
};
Node* root = NULL;
Node* newNode(int data) {
  Node* temp = new Node();
  temp -> data = data;
  temp -> left = NULL;
  temp -> right = NULL;
  return temp; 
}

void insert(int data) {
  if(root == NULL) {
    Node* temp = newNode(data);
    root = temp;
  } else {
    Node* temp = root;
    Node* y;
    while(temp !=NULL) {
      y= temp;
      if(temp-> data < data) {
        temp = temp -> right;
      } else {
        temp = temp -> left;
      }
    }
    if(y->data < data){
      y -> right = newNode(data);
    } else {  
      y -> left = newNode(data);
    }
  }
}

void search(int data) {
  Node* temp = root;
  while(temp!=NULL) {
    if(temp-> data == data) {
      cout<<"data is found";
      return;
    }
    else if(temp -> data < data) {
      temp = temp -> right;
    }
    else
    {
      temp = temp -> left;
    }
  }
  cout<<"Not found the data Please! insert";
  return;
}

void print(Node* root1) {
  if(root1 == NULL) {
    return;
  }
  cout<<root1->data<<endl;
  print(root1->left);
  print(root1->right);
}

int main() {
  insert(3);
  insert(5);
  insert(2);
  print(root);
  search(5);
}