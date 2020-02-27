#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
    struct TrieNode* children[26];
    bool endOfWord;
};

struct TrieNode* createNode(){
    struct TrieNode* newNode = new TrieNode;

    for(int i=0;i<26;++i){
        newNode -> children[i]=NULL;
    }

    newNode -> endOfWord = false;

    return newNode;
}

void insert(struct TrieNode* root, string word){
    struct TrieNode* temp = root;

    for(int i=0; i<word.size();++i){
        int index = word[i] - 'a';
        if(temp->children[index] == NULL) {
            temp -> children[index] = createNode();
        }
        temp = temp -> children[index];
    }
    temp->endOfWord = true;
}

bool search(struct TrieNode* root, string word) {

    struct TrieNode* temp = root;
    for(int i=0;i<word.size();++i){
        int index = word[i] - 'a';
        if(temp-> children[index] == NULL) {
            return false;
        }
        temp = temp -> children[index];
    }

    return (temp!=NULL and temp -> endOfWord == true);
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, ans;
    string word;
    struct TrieNode* root = createNode();
    cin>>n;
    for(int i=0;i<n;++i) {
        cin>>word;
        insert(root, word);
    }
    cin>>word;
    bool yes = search(root, word);
    cout<<yes<<"\n";
}