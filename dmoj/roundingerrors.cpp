// https://dmoj.ca/problem/globexcup18j1

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    int up = 0;
    int down = 0;
    for(int i = 0; i < N; i++) {
        double a;
        cin >> a;

        int fl = floor(a);
        int ce = ceil(a);
        if(round(a) == fl) down++;
        else up++;
    }
    cout << up << endl << down << endl;
}
