#include<bits/stdc++.h>
using namespace std;

int priority(char c) {
  if(c =='+' || c=='-') {
    return 1;
  }
  if(c=='*' || c=='/') {
    return 2;
  }
  return 0;
}

void infixtopostfix(char str[]) {
  stack<char> st;
  for(int i=0; str[i]!='\0'; i++) {
    if(str[i] == '(' || str[i] == '[' || str[i] == '{') {
      st.push(str[i]);
    }
    else if(str[i] == ')') {
      while(st.top()!='(') {
        cout<<st.top();
        st.pop();
      }
      st.pop();
    }
    else if(str[i] == '}') {
      while(st.top()!='{') {
        cout<<st.top();
        st.pop();
      }
      st.pop();
    }
    else if(str[i] == ']') {
      while(st.top()!='[') {
        cout<<st.top();
        st.pop();
      }
      st.pop();
    }
    else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
      if(!st.empty()) {
        while(!st.empty() && priority(str[i])<= priority(st.top())) {
          cout<<st.top();
          st.pop();
        }
        st.push(str[i]);
      } else {
        st.push(str[i]);
      }
    }
    else
    {
      cout<<str[i];
    }
  }
  while(!st.empty()) {
    cout<<st.top();
    st.pop();
  }
}


int main() {
  char str[51];
  fgets(str,51,stdin);
  infixtopostfix(str);
  return 0;
}