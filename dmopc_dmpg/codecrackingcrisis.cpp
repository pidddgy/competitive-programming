// https://dmoj.ca/problem/dmpg19s2

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    string a[10];
    for(int i = 0; i < 10; i++) {
        cin >> a[i];
    }

    string s;
    cin >> s;
    int N = s.size();

    int encrypt[N];
    for(int i = 0; i < N; i++) encrypt[i] = s[i]-'0';
    
    for(int i = 1; i < N; i++) {
      //  cout << "looking for " << encrypt[i];
        //cout << " in " << encrypt[i-1] << endl;
        for(int j = 0; j < 10; j++) {
            if(a[encrypt[i-1]][j]-'0' == encrypt[i]) {
                //cout << "found " << encrypt[i] << " in " << encrypt[i-1] << " at index " << j << endl;
                encrypt[i] = j;
                break;
            }
        }
        //cout << endl;
    }

    for(auto x: encrypt) cout <<x;

    cout << endl;
    
}