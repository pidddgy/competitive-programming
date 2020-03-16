// https://codeforces.com/contest/1272/problem/A

#include <bits/stdc++.h>
using namespace std;
int main() {
    #define int long long
    int Q;
    cin >> Q;

    vector<int> shit = {-1, 0, 1};
    while(Q--) {
        int a, b, c;
        cin >> a >> b >> c;

        int shitt = abs(a-b) + abs(a-c) + abs(b-c);


        // minus, stay, forward
        for(int x: shit) {
            for(int y: shit) {
                for(int z: shit) {

                    int A = a+x;
                    int B = b+y;
                    int C = c+z;

                    int dist = abs(A-B) + abs(A-C) + abs(B-C);
                    shitt = min(shitt, dist);
                }
            }
        }

        cout << shitt << endl;
    }
}