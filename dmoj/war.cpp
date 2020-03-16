// https://dmoj.ca/problem/mccc1s1

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;

    int a[N+1];
    int b[N+1];
    
    for(int i = 1; i <= N; i++) cin >> a[i];
    for(int i = 1; i <= N; i++) cin >> b[i];

    bool battle = false;
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        if(a[i] == b[i] and !battle) {
            battle = true;
            ans++;
        } else if(a[i] != b[i]) {
            battle = false;
        }
    }

    cout << ans << endl;
}