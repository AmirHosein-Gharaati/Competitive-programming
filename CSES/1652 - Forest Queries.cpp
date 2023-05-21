#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;


int main() {

    int n, q;

    cin >> n >> q;

    vvi table = vvi(n+1, vi(n+1, 0));

    string str;

    for(int i = 1; i <= n; i++) {
        cin >> str;

        for(int j = 1 ; j <=n; j++) {
            table[i][j] = table[i-1][j] + table[i][j-1] - table[i-1][j-1] + (str[j-1] == '*');
        }
    }

    while(q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        cout << table[r2][c2] - table[r2][c1 - 1] - table[r1 - 1][c2] + table[r1 - 1][c1 - 1] << endl;
    }


    return 0;
}