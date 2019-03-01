// http://codeforces.com/contest/1130/problem/B

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define endl '\n'

using namespace std;
int main() {
    #define int long long
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> A[N+1];
    for(int i = 1; i <= 2*N; i++) {
        int a;
        cin >> a;
        A[a].push_back(i);
    }

    int s = 1;
    int d = 1;
    int t = 0;

    for(int i = 1; i <= N; i++) {
        // s == 1, d == 2
        int a = abs(A[i][0] - s) + abs(A[i][1] - d);

        // s == 2, d == 1;
        int b = abs(A[i][0] - d) + abs(A[i][1] - s);


        if(a < b) {
            t += a;
            s = A[i][0];
            d = A[i][1];
        } else {
            t +=b;
            s = A[i][1];
            d = A[i][0];
        }
    }

    cout << t << endl;
}