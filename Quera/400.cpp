#include <bits/stdc++.h>

using namespace std;

set<pair<int,int>> frontier;
vector<vector<int>> maxval;
int n,m;
vector<vector<int>> table;
bool calMax(int r,int c){
    int cur = table[r][c];
    int next = (cur+1)%4;
    if(frontier.find(make_pair(r,c))!=frontier.end()){
        return false;
    }
    frontier.insert(make_pair(r,c));
    int mx = 0;
    if(r-1>=0 && table[r-1][c]==next){
        if(maxval[r-1][c]==-1){
            if(!calMax(r-1,c)){
                return false;
            }
        }
        mx = max(mx,maxval[r-1][c]);
    }
    if(c-1>=0 && table[r][c-1]==next){
        if(maxval[r][c-1]==-1){
            if(!calMax(r,c-1)){
                return false;
            }
        }
        mx = max(mx,maxval[r][c-1]);
    }
    if(r+1<n && table[r+1][c]==next){
        if(maxval[r+1][c] == -1){
            if(!calMax(r+1,c)){
                return false;
            }
        }
        mx = max(mx,maxval[r+1][c]);
    }
    if(c+1<m && table[r][c+1]==next){
        if(maxval[r][c+1] == -1){
            if(!calMax(r,c+1)){
                return false;
            }
        }
        mx = max(mx,maxval[r][c+1]);
    }
    maxval[r][c] = (cur==3?mx+1:mx);
    frontier.erase(make_pair(r,c));
    return true;
}
int main(){
    scanf("%d %d",&n,&m);
    frontier.clear();
    maxval.resize(n);
    table.resize(n);
    char dum[700];
    for(int i  = 0;i<n;i++){
        maxval[i].assign(m,-1);
        table[i].resize(m);
        scanf("%s",dum);
        for(int j = 0;j<m;j++){

            switch (dum[j]){
            case 'E':
                table[i][j] = 0;
                break;
            case 'Y':
                table[i][j] = 1;
                break;
            case 'D':
                table[i][j] = 2;
                break;
            case 'I':
                table[i][j] = 3;
                break;
                            
            default:
                break;
            }
        }
    }
    bool loop = false;
    int mx = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(table[i][j]==0){
                if(maxval[i][j] == -1){
                    loop = !calMax(i,j);
                }
                if(loop)
                    break;
                mx = max(maxval[i][j],mx);
            }
        }
        if(loop)
            break;

    }
    if(loop){
        printf("Poor Uncle!\n");
    }else if(mx==0){
        printf("Poor Mobin!\n");
    }else{
        printf("%d\n",mx);
    }


    return 0;
}