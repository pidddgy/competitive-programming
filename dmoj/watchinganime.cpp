// https://dmoj.ca/problem/gcc16p1

#include <bits/stdc++.h>
#define maxn 1000000005
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define endl '\n'
using namespace std;

int main() {    
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, A, C;
    cin >> N >> A >> C;


    unordered_map<int, int> incrS;

    while(A--) {
        int a, b;
        cin >> a >> b;

        incrS[a]++;
        incrS[b+1]--;
    }
    unordered_map<int, int> incrC;
    while(C--) {
        int c, d;
        cin >> c >> d;

        incrC[c]++;
        incrC[d+1]--;
    }


    int ans = 0;
    int stream = 0;
    int commit = 0;
    for(int i = 1; i <= N; i++) {

        stream += incrS[i];
        commit += incrC[i];


        if(!commit and stream) {
            ans++;
        }
    }

    cout << ans << endl;

}

