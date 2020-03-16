// https://codeforces.com/contest/1272/problem/E

#include <bits/stdc++.h>
using namespace std;


// int disjeven[200500];
// int disjodd[200500];

// int findpeven(int n) {
//     if(disjeven[n] == n) return n;
//     else return disjeven[n] = findpeven(disjeven[n]);
// }

// int findpodd(int n) {
//     if(disjodd[n] == n) return n;
//     else return disjodd[n] = findpeven(disjodd[n]);
// }

// int mergeeven(int a, int b) {
//     int c = findpeven(a);
//     int d = findpeven(b);

//     disjeven[c] = d;
// }

// int mergeodd(int a, int b) {
//     int c = findpodd(a);
//     int d = findpodd(b);

//     disjodd[c] = d;
// }

int main() {
    int N;
    cin >> N;

    int b[N+1];

    vector<int> G[N+1];
    vector<string> shit[N+1];

    for(int i = 1; i <= N; i++) {
        int a;
        cin >> a;

        b[i] = a;

        if(a % 2 == 0) {
            shit[i].emplace_back("even");
        } else {
            shit[i].emplace_back("odd");
        }

        if(1 <= i-a) {
            G[i].emplace_back(i-a);
        }

        if(i+a <= N) {
            G[i].emplace_back(i+a);
        }
    }    

    bool vis[N+1];
    for(int i = 1; i <= N; i++) vis[i] = false;

    for(int i = 1; i <= N; i++) {
        string toPropogate = "";
        if(b[i] % 2 == 0) {
            toPropogate = "even";
        } else {
            toPropogate = "odd";
        }
        if(!vis[i]) {
            queue<int> Q;
            Q.push(i);

            while(!Q.empty()) {
                int S = Q.front(); Q.pop();

                for(int adj: G[S]) {
                    if(!vis[adj] and find(shit[adj].begin(), shit[adj].end(), toPropogate) == shit[adj].end()) {
                        shit[adj].emplace_back(toPropogate);
                        
                    }
                }
            }

        }
    }

}