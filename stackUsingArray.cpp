#include<bits/stdc++.h>
using namespace std;

int Stack[999];
int top = -1;

void Push(int x) {
  if(top == 999) {
    cout<<"overfolw";
  }
  Stack[++top] = x;
}

void Pop() {
  if(top==-1){
    cout<<"stack is empty";
  }
  top--;
}

int isEmpty() {
  return top == -1 ? 0 : 1;
}

int Top() {
  return Stack[top];
}

int main() {
  Push(3);
  Push(4);
  Push(5);
  int empty = isEmpty();
  int top = Top();
  cout<<top<<empty;
  Pop();
  top = Top();
  cout<<top;
  return 0;
}