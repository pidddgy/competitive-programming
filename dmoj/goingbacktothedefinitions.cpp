// https://dmoj.ca/problem/pwindsor18p7

#include <bits/stdc++.h>
using namespace std;

bool comp(string a, string b) {
    if(a+b > b+a) {
        return true;
    } else {
        return false;
    }
}


int main() {
    int N;
    cin >> N;

    string a[N];
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    sort(a, a+N, comp);

    for(auto x: a) cout << x;

    cout << endl;

}
