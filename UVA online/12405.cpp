#include <bits/stdc++.h>

using namespace std;


int main() {

    int tt;
    cin >> tt;

    char arr[110];

    for(int t = 1 ; t <= tt; t++) {
        int n;
        cin >> n;

        scanf("%s", arr);

        int counter = 0;

        if(n <= 2) {
            if(arr[0] == '.' || arr[1] == '.') {
                counter = 1;
            } else {
                counter = 0;
            }

            cout << "Case " << t << ": " << counter << endl;
            continue;
        }


        for(int i = 0 ;i < n; ) {
            if(arr[i] == '.') {
                counter++;
                i += 3;
            } else {
                i++;
            }
        }
        cout << "Case " << t << ": " << counter << endl;

    }

    return 0;
}


