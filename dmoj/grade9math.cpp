// https://dmoj.ca/problem/dmopc19c6p1

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ld long double
// #define cerr if(false) cerr
#include <unistd.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    ld x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ld a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;

    ld slopeA = (y2-y1)/(x2-x1);
    ld slopeB = (b2-b1)/(a2-a1);

    ld yintA = y1 - (slopeA*x1);
    ld yintB = b1 - (slopeB*a1);

    watch(slopeA)
    watch(slopeB)

    if(slopeA == slopeB) {
        ld s = abs(x1-a1) / abs(y1-b1);

        watch(yintA)
        watch(yintB)
        if(isnan(yintA) and isnan(yintB)) {
            cout << "concident" << endl;

        } else {
            // might not work?
            cout << "parallel" << endl;
        }
    } else {
        cout << fixed << setprecision(6);
        if(isinf(slopeA) or isnan(slopeA)) {
            if(x1 == x2) {
                cout << x1 << " " << (x1*slopeB) + yintB << endl;
                return 0;
            }

            ld l = -100000000000000;
            ld r = 100000000000000;
            ld eps = 1e-13;

            // int cnt = 0;
            while(r-l > eps) {
                // cnt++;
                // if(cnt == 6) break;
                ld m1 = l + ((r-l)/3);
                ld m2 = r - ((r-l)/3);

                watch(m1)
                watch(m2)
                cerr << endl;

                ld resm1 = abs( ((m1*slopeB)+ yintB) - (y2));
                ld resm2 = abs( ((m2*slopeB)+ yintB) - (y2));

                if(resm1 < resm2) {
                    r = m2;
                } else {
                    l = m1;
                } 
            }
            watch(l)
            watch(r)

            cout << l << " " << ((l*slopeB)+ yintB) << endl;
            // cout << a1 << " " << a1*(slopeA) + yintA << endl;
        } else if(isinf(slopeB) or isnan(slopeB)) {
            if(a1 == a2) {
                cout << a1 << " " << (a1*slopeA) + yintA << endl;
                return 0;
            }

            ld l = -100000000000000;
            ld r = 100000000000000;
            ld eps = 1e-13;

            while(r-l > eps) {
                ld m1 = l + ((r-l)/3);
                ld m2 = r - ((r-l)/3);

                watch(m1)
                watch(m2)
                cerr << endl;

                ld resm1 = abs( ((m1*slopeA)+ yintA) - (b2));
                ld resm2 = abs( ((m2*slopeA)+ yintA) - (b2));

                if(resm1 < resm2) {
                    r = m2;
                } else {
                    l = m1;
                }
            }
            watch(l)
            watch(r)

            cout << l << " " << ((l*slopeA)+ yintA) << endl;
            // cout << a1 << " " << a1*(slopeA) + yintA << endl;
        } else {
            ld l = -100000000000000;
            ld r = 1000000000000000;
            ld eps = 1e-13;

            // int cnt = 0;
            while(r-l > eps) {
                // cnt++;
                // if(cnt == 10) break;
                ld m1 = l + ((r-l)/3);
                ld m2 = r - ((r-l)/3);

                watch(m1)
                watch(m2)
                cerr << endl;

                ld resm1 = abs( ((m1*slopeA)+ yintA) - ((m1*slopeB) + yintB));
                ld resm2 = abs( ((m2*slopeA)+ yintA) - ((m2*slopeB) + yintB));

                if(resm1 < resm2) {
                    r = m2;
                } else {
                    l = m1;
                }
            }
            watch(l)
            watch(r)

            cout << l << " " << ((l*slopeA)+ yintA) << endl;
        }        
    }
        watch(yintA)
    watch(yintB)
    watch(slopeA)
    watch(slopeB)
    
}

/*
0 0 2 1
0 -1 1 3

0 0 1 250
0 -250 0 -250

1 1 2 2
2 2 3 3
*/