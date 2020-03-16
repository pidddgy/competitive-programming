// https://dmoj.ca/problem/ccc05s5

#include <bits/stdc++.h>
using namespace std;

int main() {
    #define int long long
    int N;
    cin >> N;
    
    set<int> S = {};

    long double tot = 0;
    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;


        S.emplace(a);

        int b = distance(upper_bound(S.begin(), S.end(), a), S.end())+1;

        cout << b << endl;
        tot += b;
    }

    cout << fixed << setprecision(2) << tot / N << endl;
}