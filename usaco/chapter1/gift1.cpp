/*
ID: marcus.7
PROG: gift1
LANG: C++                 
*/

#include <bits/stdc++.h>
using namespace std;
int main() {
    ifstream cin("gift1.in");
    ofstream cout("gift1.out");
    
    int NP; cin >> NP;
    unordered_map<string, int> AQT;
    vector<string> people;
    for(int i = 0; i < NP; i++) {
        string s; cin >> s;
        people.push_back(s);
        AQT[s] = 0;
    }

    for(int i = 0; i < NP; i++) {
        string G; cin >> G;
        int M; cin >> M; 
        int R; cin >> R;
        if(M == 0) {
            for(int i = 0; i < R; i++) {
                string rec; cin >> rec;
            }
            continue;
        }

        AQT[G] -= M;
        for(int i = 0; i < R; i++) {
            string rec; cin >> rec;
            AQT[rec] += (int)M/R;
        }

        AQT[G] += (M - ((int)M/R)*R);

    }

    for(auto person: people) {
        cout << person << " " << AQT[person] << endl;
    }

}