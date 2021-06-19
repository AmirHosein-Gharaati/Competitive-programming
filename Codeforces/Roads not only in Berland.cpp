#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;

vector<int> parent, size;

void make_set(int s){
    parent.clear();
    parent.resize(s+1);

    size.clear();
    size.resize(s+1);

    for(int i = 0 ; i <= s ; i++){
        parent[i] = i;
        size[i] = 1;
    }
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}


void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    make_set(n);

    vector<ii> close;
    
    for(int i = 0 ; i < n-1 ; i++){
        int a, b;
        cin >> a >> b;

        if(find_set(a) != find_set(b))
            union_sets(a, b);
        
        else
            close.push_back({a, b});
    }

    set<int> s;

    for(int i = 1 ; i <= n ; i++)
        s.insert(find_set(i));

    
    auto it = s.begin();
    vector<ii> open;

    while(it != s.end()){
        int first = *it;
        it++;

        if(it == s.end()) break;

        int second = *it;

        open.push_back({first, second});
    }

    cout << close.size() << endl;

    for(int i = 0 ; i < close.size() ; i++){
        cout << close[i].first << " " << close[i].second << " " << open[i].first << " " << open[i].second << endl;
    }
    
    return 0;
}