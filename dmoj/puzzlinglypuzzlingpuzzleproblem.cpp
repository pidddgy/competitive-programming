// https://dmoj.ca/problem/cpc19c1p5

#include <bits/stdc++.h>
using namespace std;

// good enough i guess?
int h(vector<vector<int>> a) {
    int hash = 0;
    for(auto x: a) {
        for(auto y: x) {
            hash += y;
            hash *= 420;
        }
    }
    return hash;
}


int main() {
    int N, M, K, Q;
    cin >> N >> M >> K >> Q;


    vector<vector<vector<int>>> a(K+1, vector<vector<int>>(N+1, vector<int>(M+1)));



    for(int i = 1; i <= K; i++) {
        for(int j = 1; j <= N; j++) {
            for(int k = 1; k <= M; k++) {
                cin >> a[i][j][k];
            }
        }
    }

    for(int i = 1; i <= Q; i++) {
        vector<vector<int>> g(N+1, vector<int>(M+1));
        for(int j = 1; j <= N; j++) {
            for(int k = 1; k <= M; k++) {
                cin >> g[j][k];
            }
        }

    
        for(int i =1; i <= K; i++) {
            queue<int> Q;
            unordered_map<int, int> dist;

            
        }

        
    }





}