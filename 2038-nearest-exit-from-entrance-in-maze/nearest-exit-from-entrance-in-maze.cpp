class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<pair<int, int>, int>> q;
        q.push({{entrance[0], entrance[1]}, 0});

        int rsize = maze.size();
        int csize = maze[0].size();

        vector<pair<int, int>> direction{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // mark entrance visited
        maze[entrance[0]][entrance[1]] = '+';

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int moves = q.front().second;
            q.pop();

            for (auto [rd, cd] : direction) {
                int newrow = r + rd;
                int newcol = c + cd;

                if (newrow < 0 || newcol < 0 || newrow >= rsize ||
                    newcol >= csize || maze[newrow][newcol] == '+')
                    continue;

                // exit check
                if (newrow == 0 || newcol == 0 || newrow == rsize - 1 ||
                    newcol == csize - 1)
                    return moves + 1;

                // ✅ mark BEFORE pushing
                maze[newrow][newcol] = '+';
                q.push({{newrow, newcol}, moves + 1});
            }
        }

        return -1;
    }
};