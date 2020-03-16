// https://codeforces.com/contest/1315/problem/D

#include <bits/stdc++.h>
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
int main() {
    srand(time(0));
    int N;
    cin >> N;

    int aa[N+1];
    int tt[N+1];
    unordered_map<int, int> cnt;
    for(int i = 1; i <= N; i++) {
        cin >> aa[i];
        cnt[aa[i]]++;
    }

    for(int i = 1; i <= N; i++) {
        cin >> tt[i];
    }

    int mi = INT_MAX;

    for(int shift = 0; shift < 4; shift++) {

        int a[N+1];
        int t[N+1];
        unordered_map<int, int> cnt;
        for(int i = 1; i <= N; i++) {
            a[i] = aa[i];
            t[i] = tt[i];
            cnt[a[i]]++;
        }
        pii arr[N+1];
        for(int i = 1; i <= N; i++) {
            arr[i] = make_pair(t[i], a[i]);
        }

        sort(arr+1, arr+N+1, greater<pii>());

        for(int i = 1; i <= N-1; i++) {
            if(rand()%2) {
                swap(arr[i], arr[i+1]);
            }
        }

        set<int> unused;
        for(int i = 1; i <= N; i++) {
            watch(a[i])
            if(cnt[a[i]+1] == 0) {
                cerr << "emplacing " << a[i]+1 << endl;
                unused.emplace(a[i]+1);
            }
        }    

        for(int i = 1; i <= N; i++) {
            cerr << arr[i].fi << " ";
        }
        cerr << endl;

        for(int i = 1; i <= N; i++) {
            cerr << arr[i].se << " ";
        }
        cerr << endl;

        int incurred = 0;
        for(int i = 1; i <= N; i++) {
            if(cnt[arr[i].se] >= 2) {
                cerr << "ind at " << i << " is more than 1" << endl;
                set<int>::iterator ptr = unused.lower_bound(arr[i].se+1);

                cerr << "thing is " << *ptr << endl;

                if(cnt[(*ptr)+1] == 0) {
                    unused.emplace((*ptr)+1);
                    cerr << "emplacing " << (*ptr) + 1 << endl;
                }


                cerr << "lower bound was " << arr[i].se+1 << endl;

                incurred += ((*ptr) - arr[i].se) * arr[i].fi;
                watch((*ptr) - arr[i].se)
                watch(arr[i].fi)
                cerr << "incurred " << ((*ptr) - arr[i].se) * arr[i].fi << endl;

                cnt[arr[i].se]--;
                cnt[*ptr]++;

                
                unused.erase(ptr);
                

                if(cnt[arr[i].se] == 0) {
                    unused.emplace(arr[i].se);
                }

                



                cerr << endl;
            }
        }

        mi = min(mi, incurred);
        // cout << incurred << endl;
    }

    for(int shift = 0; shift < 1; shift++) {

        int a[N+1];
        int t[N+1];
        unordered_map<int, int> cnt;
        for(int i = 1; i <= N; i++) {
            a[i] = aa[i];
            t[i] = tt[i];
            cnt[a[i]]++;
        }
        pii arr[N+1];
        for(int i = 1; i <= N; i++) {
            arr[i] = make_pair(t[i], a[i]);
        }

        sort(arr+1, arr+N+1, greater<pii>());

        // for(int i = 1; i <= N-1; i++) {
        //     if(rand()%2) {
        //         swap(arr[i], arr[i+1]);
        //     }
        // }

        set<int> unused;
        for(int i = 1; i <= N; i++) {
            watch(a[i])
            if(cnt[a[i]+1] == 0) {
                cerr << "emplacing " << a[i]+1 << endl;
                unused.emplace(a[i]+1);
            }
        }    

        for(int i = 1; i <= N; i++) {
            cerr << arr[i].fi << " ";
        }
        cerr << endl;

        for(int i = 1; i <= N; i++) {
            cerr << arr[i].se << " ";
        }
        cerr << endl;

        int incurred = 0;
        for(int i = 1; i <= N; i++) {
            if(cnt[arr[i].se] >= 2) {
                cerr << "ind at " << i << " is more than 1" << endl;
                set<int>::iterator ptr = unused.lower_bound(arr[i].se+1);

                cerr << "thing is " << *ptr << endl;

                if(cnt[(*ptr)+1] == 0) {
                    unused.emplace((*ptr)+1);
                    cerr << "emplacing " << (*ptr) + 1 << endl;
                }


                cerr << "lower bound was " << arr[i].se+1 << endl;

                incurred += ((*ptr) - arr[i].se) * arr[i].fi;
                watch((*ptr) - arr[i].se)
                watch(arr[i].fi)
                cerr << "incurred " << ((*ptr) - arr[i].se) * arr[i].fi << endl;

                cnt[arr[i].se]--;
                cnt[*ptr]++;

                
                unused.erase(ptr);
                

                if(cnt[arr[i].se] == 0) {
                    unused.emplace(arr[i].se);
                }

                



                cerr << endl;
            }
        }

        mi = min(mi, incurred);
        // cout << incurred << endl;
    }

    
        for(int shift = 0; shift < 1; shift++) {

        int a[N+1];
        int t[N+1];
        unordered_map<int, int> cnt;
        for(int i = 1; i <= N; i++) {
            a[i] = aa[i];
            t[i] = tt[i];
            cnt[a[i]]++;
        }
        pii arr[N+1];
        for(int i = 1; i <= N; i++) {
            arr[i] = make_pair(t[i], a[i]);
        }

        sort(arr+1, arr+N+1);

        // for(int i = 1; i <= N-1; i++) {
        //     if(rand()%2) {
        //         swap(arr[i], arr[i+1]);
        //     }
        // }

        set<int> unused;
        for(int i = 1; i <= N; i++) {
            watch(a[i])
            if(cnt[a[i]+1] == 0) {
                cerr << "emplacing " << a[i]+1 << endl;
                unused.emplace(a[i]+1);
            }
        }    

        for(int i = 1; i <= N; i++) {
            cerr << arr[i].fi << " ";
        }
        cerr << endl;

        for(int i = 1; i <= N; i++) {
            cerr << arr[i].se << " ";
        }
        cerr << endl;

        int incurred = 0;
        for(int i = 1; i <= N; i++) {
            if(cnt[arr[i].se] >= 2) {
                cerr << "ind at " << i << " is more than 1" << endl;
                set<int>::iterator ptr = unused.lower_bound(arr[i].se+1);

                cerr << "thing is " << *ptr << endl;

                if(cnt[(*ptr)+1] == 0) {
                    unused.emplace((*ptr)+1);
                    cerr << "emplacing " << (*ptr) + 1 << endl;
                }


                cerr << "lower bound was " << arr[i].se+1 << endl;

                incurred += ((*ptr) - arr[i].se) * arr[i].fi;
                watch((*ptr) - arr[i].se)
                watch(arr[i].fi)
                cerr << "incurred " << ((*ptr) - arr[i].se) * arr[i].fi << endl;

                cnt[arr[i].se]--;
                cnt[*ptr]++;

                
                unused.erase(ptr);
                

                if(cnt[arr[i].se] == 0) {
                    unused.emplace(arr[i].se);
                }

                



                cerr << endl;
            }
        }

        mi = min(mi, incurred);
        // cout << incurred << endl;
    }

            for(int shift = 0; shift < 1; shift++) {

        int a[N+1];
        int t[N+1];
        unordered_map<int, int> cnt;
        for(int i = 1; i <= N; i++) {
            a[i] = aa[i];
            t[i] = tt[i];
            cnt[a[i]]++;
        }
        pii arr[N+1];
        for(int i = 1; i <= N; i++) {
            arr[i] = make_pair(t[i], a[i]);
        }

        sort(arr+1, arr+N+1);

        for(int i = 1; i <= N-1; i++) {
            if(rand()%2) {
                swap(arr[i], arr[i+1]);
            }
        }

        set<int> unused;
        for(int i = 1; i <= N; i++) {
            watch(a[i])
            if(cnt[a[i]+1] == 0) {
                cerr << "emplacing " << a[i]+1 << endl;
                unused.emplace(a[i]+1);
            }
        }    

        for(int i = 1; i <= N; i++) {
            cerr << arr[i].fi << " ";
        }
        cerr << endl;

        for(int i = 1; i <= N; i++) {
            cerr << arr[i].se << " ";
        }
        cerr << endl;

        int incurred = 0;
        for(int i = 1; i <= N; i++) {
            if(cnt[arr[i].se] >= 2) {
                cerr << "ind at " << i << " is more than 1" << endl;
                set<int>::iterator ptr = unused.lower_bound(arr[i].se+1);

                cerr << "thing is " << *ptr << endl;

                if(cnt[(*ptr)+1] == 0) {
                    unused.emplace((*ptr)+1);
                    cerr << "emplacing " << (*ptr) + 1 << endl;
                }


                cerr << "lower bound was " << arr[i].se+1 << endl;

                incurred += ((*ptr) - arr[i].se) * arr[i].fi;
                watch((*ptr) - arr[i].se)
                watch(arr[i].fi)
                cerr << "incurred " << ((*ptr) - arr[i].se) * arr[i].fi << endl;

                cnt[arr[i].se]--;
                cnt[*ptr]++;

                
                unused.erase(ptr);
                

                if(cnt[arr[i].se] == 0) {
                    unused.emplace(arr[i].se);
                }

                



                cerr << endl;
            }
        }

        mi = min(mi, incurred);
        // cout << incurred << endl;
    }


    cout << mi << endl;


}

/*
3
1 1 1
2 2 2

-> 6

3
1 1 2
1 2 3

-> 3

5 
1 1 1 1 2
1 2 3 4 5
*/

