#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid;
    vector<vector<bool>> visited;
    set<pair<int, int>> sols;

    for (int p = 0; p < n; ++p)
    {
        vector<char> tV;
        vector<bool> tB;
        char temp;
        for (int l = 0; l < m; ++l)
        {
            cin >> temp;
            tV.push_back(temp);
            tB.push_back(false);
        }
        grid.push_back(tV);
        visited.push_back(tB);
    }

    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < m - 1; j++)
        {
            if (!visited[i][j] && grid[i][j] != '#' && grid[i][j] != '.')
            {
                int tX = i, tY = j;
                char mom = 'A';
                while (!visited[tX][tY] && grid[tX][tY] != '.')
                {
                    char cur = grid[tX][tY];
                    if (cur != '#')
                        visited[tX][tY] = true;
                    if (cur == 'U')
                    {
                        tX--;
                        mom = cur;
                    }
                    else if (cur == 'D')
                    {
                        tX++;
                        mom = cur;
                    }
                    else if (cur == 'L')
                    {
                        tY--;
                        mom = cur;
                    }
                    else if (cur == 'R')
                    {
                        tY++;
                        mom = cur;
                    }
                    else if (cur == '#')
                    {
                        if (mom == 'U')
                        {
                            tX--;
                        }
                        else if (mom == 'D')
                        {
                            tX++;
                        }
                        else if (mom == 'L')
                        {
                            tY--;
                        }
                        else if (mom == 'R')
                        {
                            tY++;
                        }
                    }
                }
                if (grid[tX][tY] == '.')
                    sols.insert({tX, tY});
            }
        }
    }

    cout << sols.size() << "\n";
    return 0;
}