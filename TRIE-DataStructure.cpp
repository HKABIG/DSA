/*
Boiler plate for IMPLEMENTING TRIE DATA STRUCTURE
*/
#include <iostream>
using namespace std;

class TrieNode{
    public: 
    char data;
    TrieNode* children[26];
    bool isTerminal;
    TrieNode(char ch){
        data = ch;
        for(int i=0;i<26;i++){
            children[i] = NULL;   
        }
        isTerminal = false;
    }
};

class Trie{
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode('\0');
    }
    void insertUtil(string word,TrieNode* root){
        if(word.length()==0){
            root->isTerminal = true;
            return ;
        }
        TrieNode* child;
        int index = word[0]-'A';
        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertUtil(word.substr(1),child);
    }
    void insertWord(string word){
        insertUtil(word,root);
    }
    bool searchUtil(string word,TrieNode* root){
        if(word.length()==0){
            return root->isTerminal;
        }
        TrieNode* child;
        int index = word[0]-'A';
        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        else{
            return false;
        }
        return searchUtil(word.substr(1),child);
    }
    bool searchWord(string word){
        return searchUtil(word,root);
    }
};

int main(){
    Trie * t = new Trie();
    t->insertWord("ABCD");
    cout<<t->searchWord("ABCF")<<endl;
}