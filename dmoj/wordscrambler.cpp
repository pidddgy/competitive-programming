#include <bits/stdc++.h>
using namespace std;
int main() {
    for(int t = 0; t < 5; t++) {
        string thingy;
        getline(cin, thingy);
        do {
            cout << thingy << "\n";
        } while (
            next_permutation(thingy.begin(), thingy.end())
        );
    }
}
