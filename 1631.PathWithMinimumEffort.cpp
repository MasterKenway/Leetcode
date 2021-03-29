//
// Created by Kenway on 1/29/2021.
//
#include <vector>
#include <math.h>

class Solution {
public:
    int minimumEffortPath(std::vector<std::vector<int>> &heights) {
        int height = heights.size(), width = heights[0].size(), left = 0, right = 999999;

        while (left < right) {
            int mid = (left + right) / 2;
            if (valid(heights, mid, height, width))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }

    bool valid(std::vector<std::vector<int>> &grid, int time, int height, int width) {
        std::vector<std::vector<bool>> visited(height, std::vector<bool>(width, false));

        std::queue<std::pair<int, int >> q;
        q.emplace(std::make_pair(0, 0));
        visited[0][0] = true;

        while (!q.empty()) {
            std::pair<int, int> pair = q.front();
            q.pop();
            int x = pair.first, y = pair.second;

            if (x - 1 >= 0 && x - 1 < height && y >= 0 && y < width && !visited[x - 1][y] && std::abs(grid[x - 1][y] - grid[x][y]) <= time) {
                visited[x -1][y] = true;
                q.emplace(std::make_pair(x - 1, y));
            }

            if (x >= 0 && x < height &&  y - 1 >= 0 &&  y - 1 < width && !visited[x][y - 1] && std::abs(grid[x][y - 1] - grid[x][y]) <= time) {
                visited[x][ y - 1] = true;
                q.emplace(std::make_pair(x, y - 1));

            }

            if (x + 1 >= 0 && x + 1 < height && y >= 0 && y < width && !visited[x + 1][y] && std::abs(grid[x + 1 ][y] - grid[x][y]) <= time) {
                visited[x + 1][y] = true;
                q.emplace(std::make_pair(x + 1, y));

            }

            if (x >= 0 && x < height &&  y + 1 >= 0 &&  y + 1 < width && !visited[x][y + 1] && std::abs(grid[x ][y + 1] - grid[x][y]) <= time) {
                visited[x][y + 1] = true;
                q.emplace(std::make_pair(x, y + 1));

            }
        }
        return  visited[height - 1][width - 1];
    }
};