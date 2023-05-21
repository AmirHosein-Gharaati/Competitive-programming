#include <bits/stdc++.h>

using namespace std;

set<pair<int, int>> cc;
vector<vector<bool>> visited;

struct Node
{
    pair<int, int> dir;
    int depth;

    Node(pair<int, int> _dir, int _depth)
    {
        dir = _dir;
        depth = _depth;
    }
};

void dfs(pair<int, int> node, vector<vector<int>> &grid)
{
    pair<int, int> directions[] = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}};

    int n = grid.size();

    for (auto dir : directions)
    {
        int next_x = dir.first + node.first;
        int next_y = dir.second + node.second;

        if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n && !visited[next_x][next_y] && grid[next_x][next_y] == 1)
        {
            visited[next_x][next_y] = true;
            pair<int, int> next = make_pair(next_x, next_y);
            cc.insert(next);
            dfs(next, grid);
        }
    }
}

int bfs(vector<vector<int>> &grid)
{

    pair<int, int> directions[] = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}};

    queue<Node> q;

    for (pair<int, int> p : cc)
    {
        q.push(Node(p, 0));
    }

    while (!q.empty())
    {
        Node node = q.front();
        q.pop();

        if (grid[node.dir.first][node.dir.second] == 1)
        {
            if (cc.find(make_pair(node.dir.first, node.dir.second)) == cc.end())
            {
                return node.depth - 1;
            }
        }

        int n = grid.size();

        for (auto dir : directions)
        {
            int next_x = dir.first + node.dir.first;
            int next_y = dir.second + node.dir.second;

            if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n && !visited[next_x][next_y])
            {
                visited[next_x][next_y] = true;
                Node node2 = Node(make_pair(next_x, next_y), node.depth + 1);
                q.push(node2);
            }
        }
    }

    return 0;
}

int shortestBridge(vector<vector<int>> &grid)
{
    visited = vector<vector<bool>>(grid.size(), vector<bool>(grid.size(), false));
    cc = set<pair<int, int>>();

    bool flag = false;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid.size(); j++)
        {
            if (grid[i][j] == 1)
            {
                flag = true;
                cc.insert(make_pair(i, j));
                dfs(make_pair(i, j), grid);
                break;
            }
        }
        if (flag)
            break;
    }

    return bfs(grid);
}

int main()
{

    return 0;
}