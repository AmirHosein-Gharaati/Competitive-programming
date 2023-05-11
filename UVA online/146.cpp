#include <bits/stdc++.h>

using namespace std;

int main() {

    string str;
    while(true) {
        cin >> str;
        if(str == "#") {
            break;
        }

        int res = next_permutation(str.begin(), str.end());

        if(res == 0) {
            cout << "No Successor" << endl;
        } else {
            cout <<  str << endl;
        }
    }

    return 0;
}
