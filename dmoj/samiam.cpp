// link

#include <bits/stdc++.h>
using namespace std;

struct trie {
    unordered_map<char, trie*> children;
    int index;
};

trie* newNode {
    struct trie *shit = new trie();


}
void ins(struct trie *root, string s) {
    trie *cur = root;
    for(char chr: s) {
        if(cur->children.find(chr) != cur->children.end()) {

        }
    }
}
int main() {
    
}