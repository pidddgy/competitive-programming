// https://dmoj.ca/problem/rgss4

#include <bits/stdc++.h>
#pragma GCC optimize "Ofast"

using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    int arr[N];
    int T[N];

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        T[i] = arr[i];
    }

    for(int i = 1; i < N; i++)
        for(int j = 0; j < i; j++)
            if(arr[j] < arr[i])
                T[i] = max(T[i], T[j] + arr[i]);

    int max = 0;
    for(auto thing: T) {
        if(thing > max)
            max = thing;
    }

    cout << max << "\n";
}  
