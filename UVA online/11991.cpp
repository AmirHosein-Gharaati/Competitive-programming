#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;


int main() {

    int n, m;

    while(true) {

        int res = scanf("%d %d", &n, &m);
        if(res != 2)
            break;

        graph.clear();
        graph = vector<vector<int>>(1000010, vector<int>());

        int num;
        for(int i = 0; i < n; i++) {
            cin >> num;
            graph[num].push_back(i+1);
        }

        int occur, number;
        for(int i = 0; i < m; i++) {
            cin >> occur >> number;

            if(graph[number].size() < occur) {
                cout << 0 << endl;
            } else {
                cout << graph[number][occur-1] << endl;
            }
        }

    }

    return 0;
}