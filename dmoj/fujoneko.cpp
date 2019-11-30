#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
bool R[1005];
bool C[1005];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int rows, cols;
    cin >> rows >> cols;

    for(int i = 1; i <= rows; i++) {
        for(int j = 1; j <= cols; j++) {
            char a; cin >> a;
            if(a=='X') {
                R[i] = true;
                C[j] = true;
            }
        }
    }
        

    int Q;
    cin >> Q;
    for(int i = 1; i <= Q; i++) {
        int a, b;
        cin >> a >> b;

        if(R[b] || C[a]) {
            cout << "Y" << endl;
        } else {
            cout << "N" << endl;
        }
    }
}