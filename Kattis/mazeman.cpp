#include <bits/stdc++.h>

using namespace std;

using namespace std;
typedef vector<vector<char>> vvc;

vvc maze;

int flood(pair<int, int> &start, pair<int, int> entrance)
{
    int consumed = 0;
    int row = entrance.first;
    int col = entrance.second;

    if (maze[row][col] != '.' && maze[row][col] != ' ' && start != entrance)
    {
        return 0;
    }

    if (maze[row][col] == '.')
    {
        consumed++;
    }
    maze[row][col] = '>';

    // up
    if (row != 0)
    {
        consumed += flood(start, make_pair(row - 1, col));
    }

    // down
    if (row != maze.size() - 1)
    {
        consumed += flood(start, make_pair(row + 1, col));
    }

    // left
    if (col != 0)
    {
        consumed += flood(start, make_pair(row, col - 1));
    }

    // right
    if (col != maze[0].size() - 1)
    {
        consumed += flood(start, make_pair(row, col + 1));
    }

    return consumed;
}

int main()
{

    int n, m;
    cin >> n >> m;
    string t;
    getline(cin, t);

    int entrance_used = 0;
    int dots_remaining = 0;

    vector<pair<int, int>> entrances;

    for (int i = 0; i < n; i++)
    {
        string row;
        getline(cin, row);

        vector<char> rowList;
        for (int j = 0; j < row.size(); j++)
        {
            char c = row[j];

            if (c == '.')
            {
                dots_remaining++;
            }
            else if (c != ' ' && c != 'X')
            {
                entrances.push_back(make_pair(i, j));
            }

            rowList.push_back(c);
        }
        maze.push_back(rowList);
    }

    for (pair<int, int> entrance : entrances)
    {
        int consumed = flood(entrance, entrance);

        if (consumed != 0)
        {
            dots_remaining -= consumed;
            entrance_used++;
        }
    }

    cout << entrance_used << " " << dots_remaining;

    return 0;
}