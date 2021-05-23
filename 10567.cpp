#include <bits/stdc++.h>

using namespace std;

int main(){
    char c;
	int i = 0;
	vector<int> chars[257];

	while(cin.read(&c, 1) and c != '\n')
		chars[c].push_back(i++);

    int tt;
    cin >> tt;
    while(tt--){
        string query;
        cin >> query;

        int first = 0;
        int last = -1;
        bool matched = true;
        int length = query.length();

        for(int i = 0 ; i < length ; i++){
            auto it = upper_bound(chars[query[i]].begin(), chars[query[i]].end(), last);

            if(it == chars[query[i]].end()){
                matched = false;
                break;
            }

            last = *it;
            if(i == 0)
                first = last;
            
        }

        if(matched)
            cout << "Matched" << " " << first << " "<< last << endl;
        else
            cout << "Not matched" << endl;
    }


    return 0;
}