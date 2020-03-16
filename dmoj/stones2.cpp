// https://dmoj.ca/problem/dpk

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;

// shit[i] == is this state a winning position?
bool shit[100100];


int main() {
    int N, K;
    cin >> N >> K;
    int a[N];
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    shit[0] = false;

    for(int i = 1; i <= K; i++) {
        // watch(i)
        bool shitt = false;
        for(int x: a) {
            // watch(x)
            if(i-x >= 0) {
                // cout << "checking " << i-x << endl;
                if(!shit[i-x]) {
                    shitt = true;
                }
            }
        }
        // cout << endl;
        shit[i] = shitt;
    }

    // for(int i = 0; i <= K; i++) {
    //     cout << shit[i] << " ";
    // }
    // cout << endl;

    if(shit[K])
        cout << "First" << endl;
    else
        cout << "Second" << endl;



    


}