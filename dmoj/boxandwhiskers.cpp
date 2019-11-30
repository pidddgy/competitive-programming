// https://dmoj.ca/problem/dmopc19c2p1

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    #define int long long
    #define ld long double
    int N;
    cin >> N;

    int a[N+1];
    
    int ma = -2147483647;
    int mi = 2147483647;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];

        ma = max(ma, a[i]);
        mi = min(mi, a[i]);
    }

    sort(a+1, a+N+1);

    cout << fixed << setprecision(5);

    cout << mi << " " << ma << " ";

    vector<int> b;
    for(int i = 1; i <= N/2; i++) {
        b.emplace_back(a[i]);
    }
    sort(b.begin(), b.end());


    if(b.size() % 2 == 0) {
        cout << ((ld)b[(b.size()/2) - 1] + (ld)b[(b.size()/2)]) / 2.0 << " ";
    } else {
        cout << b[(b.size()/2)] << " ";
    }

    b = vector<int>();
    for(int i = 1; i <= N; i++) {
        b.emplace_back(a[i]);
    }
    sort(b.begin(), b.end());


    if(b.size() % 2 == 0) {
        cout << ((ld)b[(b.size()/2) - 1] + (ld)b[(b.size()/2)]) / 2.0 << " ";
    } else {
        cout << b[(b.size()/2)] << " ";
    }

    b = vector<int>();
    for(int i = N; i >= N-(N/2)+1; i--) {
        b.emplace_back(a[i]);
    }
    sort(b.begin(), b.end());


    if(b.size() % 2 == 0) {
        cout << ((ld)b[(b.size()/2) - 1] + (ld)b[(b.size()/2)]) / 2.0;
    } else {
        cout << b[(b.size()/2)];
    }

    cout << endl;





}