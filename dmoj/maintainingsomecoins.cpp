// https://dmoj.ca/problem/cpc19c1p6

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;

void printArr(vector<int> a) {
    for(int i = 1; i < a.size(); i++) cout << a[i] << " ";
    cout << endl;
}

int lastQuery = -1;

void enc(int &a) {
    if(lastQuery == -1) return;

    a ^= lastQuery;
}

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> a(N+1);
    for(int i = 1; i <= N; i++) cin >> a[i];
  //  printArr(a);

    for(int q = 1; q <= Q; q++) {
        char t;
        cin >> t;

        if(t == 'I') {
            int i, x;
            cin >> i >> x;

            enc(i);
            enc(x);

            a.insert(a.begin()+i+1, x);
         //   printArr(a);
        } else if (t == 'D') {
            int j;
            cin >> j;
            
            enc(j);


            a.erase(a.begin()+j);
           // printArr(a);
        } else if(t == 'C') {
            int l, r, x;
            cin >> l >> r >> x;

            enc(l);
            enc(r);
            enc(x);

            int res = 0;
            for(int i = l; i <= r; i++) {
                if(a[i] == x) res++;
            }
            lastQuery = res;
            cout << res<< endl;
        }
    }
}