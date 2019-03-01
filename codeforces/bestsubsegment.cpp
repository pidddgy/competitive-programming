// https://codeforces.com/contest/1117/problem/0

#include <bits/stdc++.h>
#define ll long long

using namespace std;
int main() {
    ll N;
    cin >> N;

    ll a[N];
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    ll maxavg = *max_element(a, a+N);
    ll biggest = 0;
    ll newBiggest = 0;
    bool looking = true;

    for(int i = 0; i < N; i++) {
        if(a[i] == maxavg) {
            if(looking) {
                newBiggest++;
            }
            else {
                newBiggest = 1;
                looking = true;
            }
        } else {
            looking = false;
            newBiggest = 0;
        }

        biggest = max(newBiggest, biggest);


    }

    cout << biggest << "\n";
}
