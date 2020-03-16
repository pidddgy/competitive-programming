// https://codeforces.com/contest/1321/problem/C

#include <bits/stdc++.h>
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;

char prev(char chr) {
    if(chr == 'a') {
        return '?';
    } else {
        return chr-1;
    }
}

// wee woo pls work lmao
int ops = 0;
unordered_map<string, bool> vis;
int mi = -INT_MAX;
int N;
void dfs(string x) {
    ops++;

    if(ops > 1e5) {
        cout << mi << endl;
        exit(0);
    }
    cerr << "x is " << x << endl;
    int thing = (N-x.size());
    cerr << "thing is " << thing << endl;
    watch(N)
    watch(x.size())
    mi = max(mi, thing);
    if(x.size() >= 2) {
        if(prev(x[0]) == x[1]) {
            string cpy = x;
            cpy.erase(cpy.begin());
            if(!vis[cpy]) {
                cerr << "removing 0th" << endl;
                cerr << "pushing " << cpy << endl;

                dfs(cpy);
                vis[cpy] = true;
            }
        }

        if(prev(x[x.size()-1]) == x[x.size()-2]) {
            string cpy = x;
            cpy.erase(cpy.begin()+cpy.size()-1);
            if(!vis[cpy]) {
                cerr << "removing last" << endl;
                cerr << "pushing " << cpy << endl;
                dfs(cpy);
                vis[cpy] = true;
            }
        }
    }    

    for(int i = 1; i < x.size()-1; i++) {
        string cpy = x;
        char p = prev(cpy[i]);
        if(cpy[i-1] == p or cpy[i+1] == p) {
            cpy.erase(cpy.begin()+i);

            if(!vis[cpy]) {
                cerr << "removing " << i << "th" << endl;
                cerr << "pushing " << cpy << endl;
                dfs(cpy);
                vis[cpy] = true;
            }
        }
    }
    cerr << endl;
}
int main() {
    // string thing = "abcdef";
    // thing.erase(thing.begin()+3);

    // cout << thing << endl;
    string s;

    cin >> N >> s;


    vis[s] = true;
    dfs(s);

    cout << mi << endl;
}