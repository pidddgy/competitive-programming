// https://dmoj.ca/problem/coci07c1p1

#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;

    if((ax == bx || ax == cx) && (ay == by || ay == cy)) {
        cout << bx-ax+cx << " " << by-ay+cy << endl;
    }

    else if((bx == ax || bx == cx) && (by == ay || by == cy)) {
        cout << cx-bx+ax << " " << cy-by+ay << endl;
    }

    else if((cx == bx || cx == ax) && (cy == by || cy == ay)) {
        cout << bx-cx+ax << " " << by-cy+ay << endl;
    }
}
