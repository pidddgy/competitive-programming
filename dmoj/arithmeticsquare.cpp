// https://dmoj.ca/problem/ccc19s3

#include <bits/stdc++.h>
#define UNKNOWN -2000000 
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define is ==
#define isnot !=
using namespace std;

int a[6][6];
void watchsq() {
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 3; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
}
void fillSq() {
    if(a[1][1] is UNKNOWN) {
        if(a[1][2] isnot UNKNOWN and a[1][3] isnot UNKNOWN) {
            a[1][1] = a[1][2] - (a[1][3] - a[1][2]);
        }
        else if(a[2][1] isnot UNKNOWN and a[3][1] isnot UNKNOWN) {
            a[1][1] = a[2][1] - (a[3][1] - a[2][1]);            
        }
    }

    
    if(a[1][2] is UNKNOWN) {
        if(a[1][1] isnot UNKNOWN and a[1][3] isnot UNKNOWN and 
        abs(a[1][3] - a[1][1]) % 2 == 0) {
            a[1][2] = a[1][1] + ((a[1][3] - a[1][1])/2);
        }

        else if(a[2][2] isnot UNKNOWN and a[3][2] isnot UNKNOWN) {
            a[1][2] = a[2][2] + ((a[2][2] - a[3][2]));
        }
    }

    if(a[1][3] is UNKNOWN) {
        if(a[1][2] isnot UNKNOWN and a[1][1] isnot UNKNOWN) {
            a[1][3] = a[1][2] + (a[1][2] - a[1][1]);
        }
        else if(a[2][3] isnot UNKNOWN and a[3][3] isnot UNKNOWN) {
            a[1][3] = a[2][3] - (a[3][3] - a[2][3]);            
        }
    }

    if(a[2][1] is UNKNOWN) {
        if(a[2][2] isnot UNKNOWN and a[2][3] isnot UNKNOWN) {
            a[2][1] = a[2][2] - (a[2][3] - a[2][2]);
        }
        else if(a[1][1] isnot UNKNOWN and a[3][1] isnot UNKNOWN and 
        abs(a[3][1] - a[1][1]) % 2 == 0) {
            a[2][1] = a[1][1] + ((a[3][1] - a[1][1])/2);
        }
    }

    if(a[2][2] is UNKNOWN) {
        if(a[2][1] isnot UNKNOWN and a[2][3] isnot UNKNOWN and
        abs(a[2][3] - a[2][1]) % 2 == 0) {
            a[2][2] = a[2][1] + ((a[2][3] - a[2][1]) / 2);
        }

        else if(a[1][2] isnot UNKNOWN and a[3][2] isnot UNKNOWN and 
        abs(a[3][2] - a[1][2]) % 2 == 0) {
            a[2][2] = a[1][2] + ((a[3][2] - a[1][2]) / 2);
        }
    }

    if(a[2][3] is UNKNOWN) {
        if(a[2][1] isnot UNKNOWN and a[2][2] isnot UNKNOWN) {
            a[2][3] = a[2][2] + (a[2][2] - a[2][1]);
        }

        else if(a[1][3] isnot UNKNOWN and a[3][3] isnot UNKNOWN and
        abs(a[3][3] - a[1][3]) % 2 == 0) {
            a[2][3] = a[1][3] + ((a[3][3]-a[1][3])/2);
        }
    }

    if(a[3][1] is UNKNOWN) {
        if(a[3][2] isnot UNKNOWN and a[3][3] isnot UNKNOWN) {
            a[3][1] = a[3][2] - (a[3][3]-a[3][2]);
        }

        else if(a[1][1] isnot UNKNOWN and a[2][1] isnot UNKNOWN) {
            a[3][1] = a[2][1] + (a[2][1]-a[1][1]);
        }
    }

    if(a[3][2] is UNKNOWN) {
        if(a[2][2] isnot UNKNOWN and a[1][2] isnot UNKNOWN) {
            a[3][2] = a[2][2] + (a[2][2]-a[1][2]);
        }

        else if(a[3][1] isnot UNKNOWN and a[3][3] isnot UNKNOWN and
        abs(a[3][3] - a[3][1]) % 2 == 0) {
            a[3][2] = a[3][1] + ((a[3][3] - a[3][1]) / 2); 
        }
    }

    if(a[3][3] is UNKNOWN) {
        if(a[1][3] isnot UNKNOWN and a[2][3] isnot UNKNOWN) {
            a[3][3] = a[2][3] + (a[2][3]-a[1][3]);
        }

        else if(a[3][1] isnot UNKNOWN and a[3][2] isnot UNKNOWN) {
            a[3][3] = a[3][2] + (a[3][2] - a[3][1]);
        }
    }



    
    
}


int main() {
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++)
            a[i][j] = UNKNOWN;
    }
    int xcnt = 0;
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 3; j++) {
            string s; cin >> s;
            if(s == "X") {
                a[i][j] = UNKNOWN;
                xcnt++;
            }
            else a[i][j] = stoi(s);
        }
    }

    if(xcnt == 9) a[2][2] = 0;
    for(int i = 1; i <= 100; i++)
    fillSq();

    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 3; j++) {
            watchsq();
            if(a[i][j] is UNKNOWN) {
                if(a[i-1][j] isnot UNKNOWN) {
                    a[i][j] = a[i-1][j];
                    for(int k = 1; k <= 50; k++) {
                        fillSq();
                    }
                    continue;
                }

                if(a[i+1][j] isnot UNKNOWN) {
                    a[i][j] = a[i+1][j];
                    for(int k = 1; k <= 50; k++) {
                        fillSq();
                    }
                    continue;
                }

                if(a[i][j-1] isnot UNKNOWN) {
                    a[i][j] = a[i][j-1];
                    for(int k = 1; k <= 50; k++) {
                        fillSq();
                    }
                    continue;
                }

                if(a[i][j+1] isnot UNKNOWN) {
                    a[i][j] = a[i][j+1];
                    for(int k = 1; k <= 50; k++) {
                        fillSq();
                    }
                    continue;
                }
            }
        }
    }


    

    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 3; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }


}