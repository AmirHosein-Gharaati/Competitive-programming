#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> edge;
typedef pair<int, int> ii;

map<char, int> mp1;
map<int, char> mp2;

#define INF 10000100

vector<char> checks;
vector<vector<ii>> adj;

int n, number = 1;
int end_point;
int distancee[30010];
bool processed[30010];

void insert(char a){
    
    if(mp1.find(a) == mp1.end()){
        mp1[a] = number;
        mp2[number] = a;
        number++;
    }
}

int main(){


    cin >> n;
    adj.resize(2*n+1);
    for(int i = 0 ; i < n ; i++){
        char a, b;
        int c;
        cin >> a >> b >> c;

        if(a >= 'A' && a <= 'Y'){
            a = a - 'A' + 'a';
            checks.push_back(a);
        }

        if(b >= 'A' && b <= 'Y'){
            b = b - 'A' + 'a';
            checks.push_back(b);
        }

        insert(a);
        insert(b);

        if(a == 'Z' || b == 'Z'){
            end_point = mp1['Z'];
        }
        adj[mp1[a]].push_back(make_pair(mp1[b], c));
        adj[mp1[b]].push_back(make_pair(mp1[a], c));
    }

    

    n = number -1;
    memset(distancee, 0, sizeof(distancee));
    memset(processed, false, sizeof(processed));

    for (int i = 1; i <= n; i++) distancee[i] = INF;

    distancee[end_point] = 0;
    queue<pair<int, int>> q;
    q.push({0,end_point});

    while (!q.empty()) {
        int a = q.front().second;
        q.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for (auto u : adj[a]) {
            int b = u.first, w = u.second;
            if (distancee[a]+w < distancee[b]) {
                distancee[b] = distancee[a]+w;
                q.push({-distancee[b],b});
                // cout << a << " " << b << " " << w << endl;
            }
        }
    }



    char minn;
    int diss = INT_MAX;

    for(char c: checks){
        int temp = mp1[c];

        if(distancee[temp] < diss){
            minn = c;
            diss = distancee[temp] ;
        }
    }
    
    minn = minn - 'a' + 'A';
    cout << minn << " " << diss;


    return 0;
}