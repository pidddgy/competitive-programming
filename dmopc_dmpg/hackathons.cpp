// https://dmoj.ca/problem/dmpg17b5

#include <bits/stdc++.h>
#pragma GCC optimize "Ofast"
#define endl '\n'
using namespace std;
const int maxT = 1000100;
int arr[maxT];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;

    int maxTime = 0;
    for(int i = 0; i < N; i++) {
        int t, w;
        cin >> t >> w;
        if(w > arr[t])
            arr[t] = w;
        if(t > maxTime)
            maxTime = t;
    }

    int curr = 0;
    for(int i = 0; i <= maxTime; i++) {
        if(arr[i] > curr)
            curr = arr[i];
        arr[i] = curr;
    }
    
    int Q; cin >> Q;
    for(int i = 0; i < Q; i++) {
        int t; cin >> t;
        if(t > maxTime) 
            cout << arr[maxTime] << endl;
        else
            cout << arr[t] << endl;
    }
}

