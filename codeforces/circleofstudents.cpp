// http://codeforces.com/contest/1203/problem/A

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl;
int main() {
    int Q; cin >> Q;
    while(Q--) {
        int N;
        cin >> N;
        int a[N];
        int ind = -1;
        int indd = -1;
        for(int i = 0; i  < N; i++)  {
            cin >> a[i];
            if(a[i] == 1)  {
                ind =  i;
                indd = i;
            }
        }

        ind++;
        if(ind == N) ind = 0;
        bool good = true;
        while(a[ind] != 1) {
            if(ind == 0) {
                if(a[ind] < a[N-1]) {
                    good = false;
                }
            } else if(a[ind] < a[ind-1]) {
                good = false;  
            }

            ind++;
            if(ind == N) {
                ind = 0;
            }
        }

        if(good) {
            // cout << "first" << endl;
            cout << "YES" << endl;
            continue;
        }
        
        ind = indd-1;
        if(ind == -1) ind = N-1;
        good = true;



        while(a[ind] != 1) {

            if(ind == N-1) {
                if(a[ind] < a[0]) {
                    good = false;
                }
            } else {
                if(a[ind] < a[ind+1]) {
                    good = false;
                }
            }
            
            ind--;
            if(ind == -1) {
                ind = N-1;
            }
        }

        if(good) cout << "YES" << endl;
        else cout << "NO" << endl;

        
    }
}