// https://dmoj.ca/problem/dmopc20c1p4

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

const int MOD = (int)1e9+7;

struct Matrix {
    vector<vector<int>> vals;
    int rows, cols;
    Matrix(vector<vector<int>> valss) {
        this->vals = valss;
        this->rows = vals.size();
        this->cols = vals[0].size();
    }
    
    Matrix operator*(const Matrix &other) const{
        int n = this->rows;
        int m = other.cols;

        assert(this->cols == other.rows);
        vector<vector<int>> res(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                for(int k = 0; k < this->cols; k++) {
                    res[i][j] += this->vals[i][k] * other.vals[k][j];
                    res[i][j] %= MOD;
                }
            }
        }        

        return res;
    }

    void printVals() {
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                cerr << this->vals[i][j] << " ";
            }
            cerr << endl;
        }
    }
};

Matrix identityMatrix(int n) {
    vector<vector<int>> vals(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        vals[i][i] = 1;
    }

    return Matrix(vals);
}

Matrix mpow(Matrix a, int exp) {
    if(exp == 0) return identityMatrix(max(a.rows, a.cols));

    Matrix t = mpow(a, exp / 2);
    if(exp & 1) return t * t * a;
    return t * t;
}
int mod(int number) {
    return (number+MOD)%MOD;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, t, c;
    cin >> n >> k >> t >> c;

    vector<vector<int>> init;
    
    init.push_back(vector<int>(t+1, 0));
    init[0][0] = c;

    vector<vector<int>> cute;
    vector<int> row;
    for(int i = 0; i <= t; i++) {
        row.push_back(0);
    }
    for(int i = 0; i <= t; i++) {
        cute.push_back(row);
    }

    // for(auto x: init) {
    //     for(int y: x) {
    //         cout << y << " ";
    //     }
    //     cout << endl;
    // }

    cute[0][0] = 1;
    cute[0][t] = k;
    for(int i = 1; i <= t; i++) {
        cute[i][i-1] = 1;
    }

    Matrix hugs(cute);
    hugs.printVals();

    Matrix st(init);
    st.printVals();

    watch(hugs.cols);
    watch(st.rows)
    Matrix ree = st*hugs;

    ree.printVals();

    int transforms = n-1;

    Matrix b = mpow(hugs, transforms);

    Matrix end = st*b;

    int ans = mod(end.vals[0][0]*2);

    for(int i = 1; i <= t; i++) {
        ans += mod(end.vals[0][i]);
        ans = mod(ans);
    }

    cout << ans << endl;
}

/*

int state[100];

state[i] = number of crabs that need i more months to go

pre

state[T] = pre[0]
state[i] = pre[i+1]

matrix????

T = 3

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
