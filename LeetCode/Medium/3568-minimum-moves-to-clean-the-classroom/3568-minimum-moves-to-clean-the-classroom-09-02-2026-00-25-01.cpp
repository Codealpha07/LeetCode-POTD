class Solution {
public:
    int m, n;
    int maxEnergy;
    int litterCount;

    vector<vector<int>> dir = {
        {-1, 0},
        {0, -1},
        {1, 0},
        {0, 1}
    };

    int minMoves(vector<string>& classroom, int energy) {
        m = classroom.size();
        n = classroom[0].size();
        maxEnergy = energy;

        pair<int, int> start;
        vector<vector<int>> litterId(m, vector<int>(n, -1));

        // Give every litter cell an ID
        litterCount = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S')
                    start = {i, j};

                if (classroom[i][j] == 'L') {
                    litterId[i][j] = litterCount++;
                }
            }
        }

        // All litter collected initially
        if (litterCount == 0)
            return 0;

        int fullMask = (1 << litterCount) - 1;

        /*
            State:

            (row, col, energy, mask)

            mask tells us which litter has been collected.
        */

        // visited[row][col][energy][mask]
        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << litterCount, false)
                )
            )
        );

        // row, col, energy, mask
        queue<array<int, 4>> q;

        q.push({
            start.first,
            start.second,
            energy,
            0
        });

        visited[start.first][start.second][energy][0] = true;

        int moves = 0;

        while (!q.empty()) {

            int sz = q.size();

            // Every state in this level has the same number of moves
            while (sz--) {

                auto [i, j, currEnergy, mask] = q.front();
                q.pop();

                // We have collected everything
                if (mask == fullMask)
                    return moves;

                // Can't move anymore
                if (currEnergy == 0)
                    continue;

                for (auto& d : dir) {

                    int ni = i + d[0];
                    int nj = j + d[1];

                    // Outside grid
                    if (ni < 0 || ni >= m ||
                        nj < 0 || nj >= n)
                        continue;

                    // Wall
                    if (classroom[ni][nj] == 'X')
                        continue;

                    // One movement consumes one energy
                    int newEnergy = currEnergy - 1;
                    int newMask = mask;

                    // Collect litter
                    if (classroom[ni][nj] == 'L') {
                        int id = litterId[ni][nj];
                        newMask |= (1 << id);
                    }

                    // Reset energy
                    if (classroom[ni][nj] == 'R') {
                        newEnergy = maxEnergy;
                    }

                    // Already visited this exact state
                    if (visited[ni][nj][newEnergy][newMask])
                        continue;

                    visited[ni][nj][newEnergy][newMask] = true;

                    q.push({
                        ni,
                        nj,
                        newEnergy,
                        newMask
                    });
                }
            }

            moves++;
        }

        return -1;
    }
};