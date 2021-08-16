#include <bits/stdc++.h>

using namespace std;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    map<string, int> books;
    vector< pair<string, string>> shelf;

    while(getline(cin, line) && line[0] != 'E'){
        string author, title;

        stringstream ss(line);

        ss.ignore(1, '"');
        getline(ss, title, '"');

        ss.ignore(1, ' ');
        ss.ignore(2, ' ');

        getline(ss, author, '"');
        shelf.push_back(make_pair(author, title));
    }

    int shelf_size = shelf.size();
    sort(shelf.begin(), shelf.end());

    for(int i = 0 ; i < shelf_size ; i++){
        books[shelf[i].second] = i;
    }


    vector<bool> borrowed(shelf_size);
    vector<bool> returned(shelf_size);

    while(getline(cin, line) && line[0] != 'E'){
        string title;

        int prev = -1;

        stringstream ss(line);
        if (line[0] != 'S')
		{
			ss.ignore(8, '\"');
			getline(ss, title, '\"');
		}

        switch(line[0]){
            case 'B':
                borrowed[books[title]] = true;
                returned[books[title]] = false;
            break;

            case 'R':
                returned[books[title]] = true;
            break;

            default:

                for(int i = 0 ;i < shelf_size ; i++){

                    if(returned[i]){
                        if(prev == -1){
                            cout << "Put \"" << shelf[i].second << "\" first" << endl;
                        }
                        else{
                            cout << "Put \"" << shelf[i].second << "\" after \"" << shelf[prev].second << "\"" << endl;
                        }

                        returned[i] = false;
                        borrowed[i] = false;

                        prev = i;
                    }
                    else if(!borrowed[i])
                        prev = i;
                }
                cout << "END" << endl;
        }
    }

    return 0;
}