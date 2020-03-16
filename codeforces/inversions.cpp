// https://codeforces.com/problemsets/acmsguru/problem/99999/180

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl;
int N;
vector<int> a;
int inv = 0;
vector<int> merge(vector<int> l, vector<int> r) {
    while(!l.empty())


}
vector<int> f(vector<int> arr) {
    if(arr.size()==1) {
        return {arr[0]};
    }

    vector<int> larr;
    for(int i = 0; i <= arr.size()/2; i++)  {
        larr.emplace_back(a[i]);
    }

    vector<int> rarr;
    for(int i = (arr.size()/2)+1; i < arr.size(); i++) {
        rarr.emplace_back(a[i]);
    }

    // for(auto x: larr) {
    //     cout << x << endl;
    // }

    // cout << endl;
    // for(auto x: rarr) {
    //     cout << x << endl;
    // }

    larr = f(larr);
    rarr = f(rarr);

    vector<int> n;
    for(auto x: larr) n.emplace_back(x);
    for(auto x: rarr) n.emplace_back(x);

    return f(n);
}


int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        int b;
        cin >> b;
        a.emplace_back(b);
    }

    f(a);
}