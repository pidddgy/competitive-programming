// https://codeforces.com/contest/493/problem/B

#include <bits/stdc++.h>
using namespace std;
int main() {
    #define int long long
    int N;
    cin >> N;

    vector<int> a;
    vector<int> b;
    int asum = 0;
    int bsum = 0;

    int last;

    for(int i = 1; i <= N; i++) {
        int _;
        cin >> _;
        
        if(_ < 0) {
            b.emplace_back(abs(_));
            bsum += abs(_);
        } else {
            a.emplace_back(_);
            asum += _;
        }

        last = _;
    }

    if(asum > bsum) {
        cout << "first" << endl;
    } else if(bsum > asum) {
        cout << "second" << endl;
    } else {
        if(lexicographical_compare(a.begin(), a.end(), b.begin(), b.end())) {
            cout << "second" << endl;
        } else if (lexicographical_compare(b.begin(), b.end(), a.begin(), a.end())) {
            cout << "first" << endl;
        } else {
            if(last < 0) {
                cout << "second" << endl;
            } else {
                cout << "first" << endl;
            }
        }
    }
}