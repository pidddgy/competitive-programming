// https://mcpt.ca/problem/ahc19p3

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    #define int long long

    int N;
    cin >> N;

    int a[N+1];
    int la = -1;
    int sum = 0;
    int absum = 0;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
        if(a[i] < 0) la = i;
        sum += a[i];
        absum += abs(a[i]);
    }


    if(la == -1) {
        cout << sum << endl;
        return 0;
    }
    

    cout << absum << endl;

    string mode;
    int last;
    if(a[1] < 0) {
        mode = "neg";
        last = 1;
    }
    else if(a[1] > 0) {
        last = 1;
        mode = "pos";
    }
    else {
        for(int i = 1; i <= N; i++) {
            if(a[i] < 0) {
                mode = "neg";
                last = i;
                break;
            } else if(a[i] > 0) {
                mode = "pos";
                last = i;
                break;
            }
        }
    }

    
    for(int i = 2; i <= N; i++) {
        if(mode == "neg") {
            if(a[i] > 0) {
                cout << last << " ";
                mode = "pos";
            }
        } else if(mode == "pos") {
            if(a[i] < 0) {
                cout << last << " ";
                mode = "neg";
            }
        }
        if(a[i] != 0) last = i;
    }

    if(mode == "neg") cout << N;
    
    cout << endl;

    






}