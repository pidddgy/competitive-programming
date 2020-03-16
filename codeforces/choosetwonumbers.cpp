// http://codeforces.com/contest/1206/problem/0

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
bool inA[500];
bool inB[500];
int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        inA[a[i]] = true;
    }

    int m;
    cin >> m;
    int b[m];
    for(int i = 0; i < m; i++) {
        cin >> b[i];
        inB[b[i]] = true;
    }


    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int cute = a[i] + b[j]; 

            if(inA[cute]) continue;
            if(inB[cute]) continue;

            cout << a[i] << " " << b[j] << endl;
            return 0;

        }
    }
}