// https://codeforces.com/contest/864/problem/D

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    int N;
    cin >> N;
    int a[N+1];
    set<int> unused;
    unordered_map<int, int> cnt;
    unordered_map<int, bool> skipped;
    for(int i = 1; i <= N; i++) {
        unused.emplace(i); 
    }

    for(int i = 1; i <= N; i++) {
        cin >> a[i];
        unused.erase(a[i]);
        cnt[a[i]]++;
    }

    int chng = 0;
    for(int i = 1; i <= N; i++) {
        if(cnt[a[i]] == 1) {
            continue;
        }
        if(cnt[a[i]] > 1) {
            if(*unused.begin() < a[i]) {
                cnt[a[i]]--;
                a[i] = *unused.begin();
                cnt[*unused.begin()]++;
                unused.erase(a[i]);
                chng++;
            } else if(skipped[a[i]]) {
                cnt[a[i]]--;
                a[i] = *unused.begin();
                cnt[*unused.begin()]++;
                unused.erase(a[i]);
                chng++;
            } else {
                skipped[a[i]] = true;
            }
        }
    }

    cout << chng << endl;
    for(int i = 1; i <= N; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}