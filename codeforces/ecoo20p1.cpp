// https://ecoo.mcpt.ca/problem/ecoo20p1

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'

vector<string> notes = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    while(N--) {
        vector<string> chord;
        for(int i = 0; i < 4; i++) {
            string x;
            cin >> x;

            chord.emplace_back(x);
        }

        vector<int> diffs;
        for(int i = 0; i < 3; i++) {
            string beg = chord[i];
            string look = chord[i+1];

            int d = 0;
            int ind = 0;
            for(int j = 0; j < notes.size(); j++) {
                if(notes[j] == beg) {
                    ind = j;
                    break;
                }
            }

            // watch(i)
            for(;;) {
                // cerr << "accessing notes at ind " << ind << endl;
                if(notes[ind] == look) {
                    break;
                }
                ind++;
                d++;

                // watch(ind)

                if(ind == notes.size()) ind = 0;

                // watch(ind)
            }

            diffs.emplace_back(d);
        }

        assert(diffs.size() == 3);

        // for(int x: diffs){
        //     cerr << x << " ";
        // }
        // cerr << endl;

        if((diffs[0] == 4) and (diffs[1] == 3) and (diffs[2] == 3)) {
            cout << "root" << endl;
        } else if((diffs[0] == 3) and (diffs[1] == 3) and (diffs[2] == 2)) {
            cout << "first" << endl;
        } else if((diffs[0] == 3) and (diffs[1] == 2) and (diffs[2] == 4)) {
            cout << "second" << endl;
        } else if((diffs[0] == 2) and (diffs[1] == 4) and (diffs[2] == 3)) {
            cout << "third" << endl;
        } else {
            cout << "invalid" << endl;
        }
    }
}