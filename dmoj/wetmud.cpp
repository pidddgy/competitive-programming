// https://dmoj.ca/problem/bts17p4

#include <bits/stdc++.h>
// #define watch(x) cout << (#x) << " is " << (x) << endl;
#define MAXINT 2147483647
#define MAXN 100005
#define endl '\n'
using namespace std;

int T[MAXN];
int block[318];
int blockInd[318];
int blksz;

int query(int l, int r) {
    int mi = MAXINT;
    int ind = MAXINT;

    while(l < r && l%blksz != 0 && l != 0) {
        if(T[l] < mi) ind = l; 
        mi = min(T[l], mi);
        l++;
    }
    
    while(l+blksz < r) {
        if(block[l/blksz] < mi) ind = blockInd[l/blksz];
        mi = min(block[l/blksz], mi);
        l += blksz;
    }

    while(l <= r) {
        if(T[l] < mi) ind = l;
        mi = min(T[l], mi);
        l++;
    }

    return ind;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    fill(block, block+318, MAXINT);
    fill(blockInd, blockInd+318, MAXINT);
    
    int N, M, J;
    cin >> N >> M >> J;
    
    N++;
    for(int i = 0; i < N; i++) T[i]=MAXINT;
    T[N-1] = 0;

    for(int i = 0; i < M; i++) {
        int p, t;
        cin >> p >> t;

        T[p-1] = t;
    }

    blksz = sqrt(N);
    int blkind = -1;
    for(int i = 0; i < N; i++) {
        if(i%blksz==0) {
            blkind++;
        }
        
        if(T[i] < block[blkind]) blockInd[blkind] = i;
        block[blkind] = min(T[i], block[blkind]);
    }

    int cur = query(0, J-1);
    if(cur == MAXINT) {
        cout << -1 << endl;
        return 0;
    }
    int elapsed = T[cur];

    while(cur != N-1) {
        cur = query(cur+1, min(cur+J, N-1));
        if(cur == MAXINT) {
            cout << -1 << endl;
            return 0;
        }

        if(cur==N-1) break;
        elapsed = max(elapsed, T[cur]);
    }

    cout << elapsed << endl;
}