#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node* left;
  struct Node* right;
};

Node* newNode(int data) {
  Node* temp = new Node();
  temp -> data = data;
  temp -> left = NULL;
  temp -> right = NULL;
  return temp;
}

Node* insert(int data, Node* root) {
  Node *temp = root;
  if(temp == NULL) {
    return newNode(data);
  }
  if(temp->data > data) {
    temp -> left = insert(data, temp->left);
  }
  else
  {
    temp->right = insert(data, temp -> right);
  }
  return root;
}

void print(Node* root) {
  Node* temp = root;
  if(root == NULL) {
    return;
  }
  cout<<"this is temp data"<<temp->data<<endl;
  print(temp -> left);
  print(temp-> right);
}

Node* search(int data, Node* root) {
  if(root == NULL) {
    cout<<"data not found"<<endl;
    return 0;
  }
  if(root ->data == data) {
    cout<<"data -found"<<endl;
    return root;
  }
  else if(root -> data > data) {
    search(data, root -> left);
  }
  else if( root -> data < data) {
    search(data, root -> right);
    
  }
};
Node* inorderSuccessor(Node* root) {
  Node* temp = root;
  while(temp && temp -> left!=NULL) {
    temp = temp -> left;
  }
  return temp;
}

Node* Delete(Node* root, int data) {
  if(root == NULL) return root;
  if(data < root -> data) {
    root -> left = Delete(root -> left, data);
  }
  else if(data > root -> data) {
    root -> right = Delete(root -> right, data);
  }

  else
  {
    if(root -> left == NULL) {
      Node* temp = root -> right;
      delete(root);
      return temp;
    }
    else if(root -> right == NULL) {
      Node* temp = root -> left;
      delete(temp);
      return temp;
    }
      Node* succesor = inorderSuccessor(root -> right);
      root -> data = succesor -> data;
      root -> right = Delete(root->right, succesor -> data);
  }
  return root;
}
int isBstUtil(Node* root,int min, int max) {
  if(root == NULL) {
    return 1;
  };
  if(root -> data < min || root -> data > max) {
    return 0;
  }
  return isBstUtil(root->left, min, (root -> data)-1) && isBstUtil(root -> right, (root -> data)+1, max);
}

int isBst(Node* root) {
  return isBstUtil(root,INT_MIN, INT_MAX);
}


int main() {
  Node* root = NULL;
  root = insert(3, root);
  root = insert(2,root);
  root = insert(5, root);
  root = insert(1,root);
  root = insert(4, root);
  print(root);
  root = Delete(root, 3);
  root = Delete(root, 10);
  cout<<"this is data after the deletion"<<endl;
  print(root);
  int temp = isBst(root);
  temp ? cout<<"the given tree is a binary tree" : cout<<"not a binary tree";
  return 0;
}