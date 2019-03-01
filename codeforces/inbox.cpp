// http://codeforces.com/problemset/problem/465/B

#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> A;
    for(int i = 0; i < N; i++) {
        int b;
        cin >> b;
        if(b == 1) A.emplace_back(i);
    }

    int ret = 0;
    int cur;

    for(int i = 0; i < A.size(); i++) {
        if(ret == 0) {
            ret++;
            cur = A[i];
            continue;
        }

        if(A[i] - cur >= 2) {
            cur = A[i];
            ret += 2;
        }

        else {
            cur = A[i];
            ret += 1;
        }
    }

    cout << ret << endl;


    
}