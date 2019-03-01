// https://dmoj.ca/problem/globexcup18j3

#include <bits/stdc++.h>
using namespace std;
bool prime(int x) {
    for(int i = 2; i < x; i++) {
        if(x%i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    int ret = 0;

    for(int i = 0; i < N; i++) {
        bool good = true;

        int x;
        cin >> x;
        if(x == 1) continue;

        // if its not prime, its not good
        if(!prime(x)) {
            good = false;
        }

        // check if sum is prime
        string strx = to_string(x);
        int sum = 0;
        for(int i = 0; i < strx.size(); i++) {
            sum += strx[i]-'0';
        }

        if(!prime(sum)) {
            good = false;
        }

        if(good) {
            ret++;
        }
    }

   cout << ret << endl;
}
