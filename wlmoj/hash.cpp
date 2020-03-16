#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;


    unordered_map<string, int> cnt;
    for(int i = 0; i < N; i++) {
        string cute;
        cin >> cute;

        if(cute.size()%2==1) {
            cute += "y";
            cute[0] -= 'a';
            cute[1] -= 'a';
        }
    }
}