// https://dmoj.ca/problem/vmss7wc16c2p2

#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; cin >> s;

//    cout << s.size() << endl;

    int p[s.size()];

    if(s[0] == 'G')
        p[0] = 1;
    else 
        p[0] = 0;
    for(int i = 1; i < s.size(); i++) {
        p[i] = p[i-1];
        if(s[i] == 'G') p[i]++;
    }

    int N; cin >> N;

    while(N--) {
        int a, b;
        cin >> a >> b;

        if(a) {
            cout << p[b] - p[a-1];
        } else cout << p[b];

        cout << endl;
    }
}
