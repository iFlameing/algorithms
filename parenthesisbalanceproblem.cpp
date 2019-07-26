#include<bits/stdc++.h>
using namespace std;

void checkForBalancedParenthesis(char s[]) {
  stack<char> st;
  for(int i=0; s[i]!='\0';i++){
    if(s[i] == '{' || s[i]== '[' || s[i] == '(') {
      st.push(s[i]);
    }
    if(s[i] == '}' && !st.empty()) {
      if('{'== st.top()) {
        st.pop();
      } else
      {
        cout<<"unbalanced {}"<<endl;
        return;
      }
    }
    if(s[i]== ']' && !st.empty()) {
      if('['==st.top()) {
        st.pop();
      } else
      {
        cout<<"unbalanced []"<<endl;
        return;
      }
    }
    if(s[i] == ')' && !st.empty()) {
      if('(' == st.top()) {
        st.pop();
      } else
      {
        cout<<"unbalnced()"<<endl;
        return;
      }
    }
  }
  if(st.empty()) {
    cout<<"balanced"<<endl;
    return;
  } 
  cout<<"unbalanced"<<endl;
  return;
}

int main() {
  char c[51];
  fgets(c, 51, stdin);
  checkForBalancedParenthesis(c);
}