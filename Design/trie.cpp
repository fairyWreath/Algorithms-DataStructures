#include <vector>
#include <string>

using namespace std;

#define SIZE 26

int toint(char c) {
    return static_cast<int>(c - 'a');
}

class TrieNode {  
public:    
    TrieNode() : isWord(false), children() {};
    TrieNode* children[SIZE];
    bool isWord;
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* current = root;
        for(auto& c : word) {
            if(current->children[toint(c)] == nullptr) {
                current->children[toint(c)] = new TrieNode();
            }
            current = current->children[toint(c)];
        }
        current->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* current = root;
        for(auto& c : word) {
            if(current->children[toint(c)] == nullptr) {
                return false;
            }
            current = current->children[toint(c)];
        }
        return current->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* current = root;
        for(auto& c : prefix) {
            if(current->children[toint(c)] == nullptr) {
                return false;
            }
            current = current->children[toint(c)];
        }
        return true;
    }
    
    
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */