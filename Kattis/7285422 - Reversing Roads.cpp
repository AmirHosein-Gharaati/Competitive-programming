#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g, gt;
int deg_in[60];
int deg_out[60];
vector<bool> visited;
vector<bool> visited2;
int n, m;
int case_number = 1;
typedef pair<int, int> ii;
vector<ii> edges;


void dfs(int u){
    visited[u] = true;

    for(int index : g[u]){
        if(!visited[index])
            dfs(index);
    }
}

void dfs2(int u){
    visited2[u] = true;

    for(int index : gt[u]){
        if(!visited2[index])
            dfs2(index);
    }
}

void check_valid(){
    int i, j;
    bool allSeen;
    for(ii temp : edges){
        i = temp.first;
        j = temp.second;

        remove(g[i].begin(), g[i].end(), j);
        g[j].push_back(i);
        remove(gt[j].begin(), gt[j].end(), i);
        gt[i].push_back(j);

        visited.clear();visited.assign(n+1, false);
        visited2.clear();visited2.assign(n+1, false);

        dfs(0);
        dfs2(0);

        allSeen = true;

        for(int k = 0; k < n ;k++){
            if(visited[k] == false || visited2[k] == false){
                allSeen = false;
                break;
            }
        }

        if(allSeen){
            cout << "Case " << case_number << ": " << i << " " << j << endl;
            
            return;
        }

        g[j].pop_back();
        g[i].push_back(j);
        gt[i].pop_back();
        gt[j].push_back(i);

    }
    

    cout << "Case " << case_number << ": invalid" << endl;
    
}

int main(){


    while(scanf("%d %d", &n, &m) != EOF){
        
        g.clear();g.resize(n+1);
        gt.clear(); gt.resize(n+1);
        memset(deg_in, 0, sizeof(deg_in));
        memset(deg_out, 0, sizeof(deg_out));
        visited.clear();visited.assign(n+1, false);
        visited2.clear();visited2.assign(n+1, false);
        edges.clear();

        int a, b;
        for(int i = 0 ; i < m ; i++){
            cin >> a >> b;
            edges.push_back(ii(a, b));
            g[a].push_back(b);
            deg_in[b]++;
            deg_out[a]++;
            gt[b].push_back(a);
        }

        int in_sum = 0;
        int out_sum = 0;

        for(int i = 0; i < n ;i++){
            in_sum += deg_in[i];
            out_sum += deg_out[i];
        }

        int numberOfEdgesNeedToChange = max(n-in_sum, n-out_sum);
        bool allSeen = true;
        

        if(numberOfEdgesNeedToChange <=1){
            dfs(0);
            dfs2(0);
            
            for(int i = 0; i < n ;i++){
                if(visited[i] == false || visited2[i] == false){
                    allSeen = false;
                    break;
                }
            }

            if(allSeen){
                cout << "Case " << case_number << ": valid" << endl;
                
            }
            else{
                check_valid();
            }

        }
        else
            cout << "Case " << case_number << ": invalid" << endl;
    
        case_number++;
        
        
    }



    return 0;
}