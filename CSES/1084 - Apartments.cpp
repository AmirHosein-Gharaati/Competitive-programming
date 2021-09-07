#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> people(n), aparts(m);
    for(int i = 0 ; i < n ; i++)
        cin >> people[i];
    for(int i = 0 ; i < m ; i++)
        cin >> aparts[i];
    
    sort(people.begin(), people.end());
    sort(aparts.begin(), aparts.end());

    int counter = 0;
    int i=0, j=0;

    while(i < n && j < m){

        if(abs(people[i] - aparts[j]) <= k){
            counter++;
            i++;
            j++;
        }

        else if(people[i] < aparts[j])
            i++;

        else
            j++;
        
    }

    cout << counter;

    return 0;
}