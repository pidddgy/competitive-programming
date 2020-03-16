// https://dmoj.ca/problem/fhc15c1p2

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;

struct Trie{
    unordered_map<char, Trie> children;
};
Trie root = Trie();

void insert(string str) {
    Trie& cur = root;
    for(char chr: str) {

        if(cur.children.find(chr) == cur.children.end()) {
            cur.children.insert({chr, Trie()});
        }

        cur = cur.children[chr];
    }
}

int search(string str) {
    Trie& cur = root;
    str = "."+str;

    for(int i = 1; i < str.size(); i++) {
        if(cur.children.find(str[i]) == cur.children.end()) {
            return i;
        }
        cur = cur.children[str[i]];

    }

    return str.size()-1;
}

int main() {
    int T;
    cin >> T;

    for(int i = 1; i <= T; i++) {
        int N;
        cin >> N;
        int res = 0;
        while(N--) {
            string s;
            cin >> s;

            res += search(s);
            insert(s);

            cout << "hello" << endl;
            for(pair<char, Trie> x: root.children) {
                cout << x.first << " ";
            }


        } 

        

        cout << "Case #"<<i<<": " << res << endl;
    }
}