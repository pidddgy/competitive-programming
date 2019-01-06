// https://dmoj.ca/problem/lkp18c2p3    

#include <bits/stdc++.h>
#define pii pair<long double, long double>
#define xc first
#define yc second
#define endl '\n'
#define ld long double

using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    pii cities[N];
    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        cities[i].xc = a;
        cities[i].yc = b;
    }

    for(int i = 0; i < M; i++) {
        pii a, b, c;
        cin >> a.xc >> a.yc;
        cin >> b.xc >> b.yc;
        cin >> c.xc >> c.yc;
        long double triangleArea = abs(a.xc * (b.yc - c.yc) + b.xc * (c.yc - a.yc) + c.xc * (a.yc - b.yc)) / 2;
        //cout << "triangle area is " << triangleArea << endl;


        int total = 0;
        for(int i = 0; i < N; i++) {
            pii C = cities[i];
            int x = C.xc;
            int y = C.yc;

            long double squareArea = abs((a.xc*b.yc + b.xc*c.yc + c.xc*y + x*a.yc) - (b.xc*a.yc + c.xc*b.yc+x*c.yc+a.xc*y)) / 2;
            //cout << "square area is " << squareArea << endl;
            if(squareArea <= triangleArea) total++;
        }

        cout << total << endl;
    }

}