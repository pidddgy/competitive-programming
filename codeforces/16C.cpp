// https://codeforces.com/contest/710/problem/C

#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>

#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    queue<int> even;
    queue<int> odd;
    for(int i = 1; i <= n*n; i++) {
        if(i % 2 == 0) {
            even.push(i);
        } else {
            odd.push(i);
        }
    }

    for(int i = 1; i <= n/2; i++) {
        int outer = (n-((2*i)-1))/2;
        for(int j = 1; j <= outer; j++) {
            cout << even.front() << " ";
            even.pop();
        }

        for(int j = 1; j <= (2*i-1); j++) {
            cout << odd.front() << " ";
            odd.pop();
        }

        for(int j = 1; j <= outer; j++) {
            cout << even.front() << " ";
            even.pop();
        }
        cout << endl;
    }

    for(int j = 1; j <= n; j++) {
        cout << odd.front() << " ";
        odd.pop();
    }
    cout << endl;

    for(int i = n/2; i >= 1; i--) {
        int outer = (n-((2*i)-1))/2;
        for(int j = 1; j <= outer; j++) {
            cout << even.front() << " ";
            even.pop();
        }

        for(int j = 1; j <= (2*i-1); j++) {
            cout << odd.front() << " ";
            odd.pop();
        }

        for(int j = 1; j <= outer; j++) {
            cout << even.front() << " ";
            even.pop();
        }
        cout << endl;
    }
}
