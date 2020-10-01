// https://codeforces.com/problemset/problem/222/E

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define cerr if(false) cerr
#define int long long

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


map<char, int> mp;
int ind = 0;
int n, m, k;

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    for(char x: string("abcdefghijklmnopqrstuvwxyz")) {
        mp[x] = ind++;
    }

    for(char x: string("ABCDEFGHIJKLMNOPQRSTUVWXYZ")) {
        mp[x] = ind++;
    }

    cin >> n >> m >> k;

    vector<vector<int>> dpVals(1, vector<int>(m, 1));
    vector<vector<int>> okVals(m, vector<int>(m, 1));

    for(int i = 0; i < k; i++) {
        string s;
        cin >> s;

        char l = s[0], r = s[1];

        okVals[mp[l]][mp[r]] = 0;
    }

    Matrix dp(dpVals);
    Matrix ok(okVals);

    ok = mpow(ok, n-1);
    dp = dp*ok;

    int sum = 0;
    for(int x: dp.vals[0]) {
        sum += x;
        sum %= MOD;
    }

    cout << sum << endl;
}
