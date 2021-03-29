//
// Created by Kenway on 1/30/2021.
//
//#include <vector>
//
//class Solution {
//public:
//    int swimInWater(std::vector<std::vector<int>> &grid) {
//        int n = grid.size(), left = 0, right = n * n - 1;
//        std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));
//        while (left < right) {
//            int mid = (left + right) / 2;
//            if (valid(0, 0, n, n, grid, visited, mid)) {
//                right = mid;
//            } else {
//                left = mid + 1;
//            }
//        }
//        return left;
//    }
//
//    bool valid(int x, int y, int height, int width, std::vector<std::vector<int>> &grid,
//               std::vector<std::vector<bool>> visited, int time) {
//        if (x >= 0 && x < height && y >= 0 && y < width && !visited[x][y] && grid[x][y] <= time) {
//            if (x == height - 1 && y == width - 1) return true;
//            visited[x][y] = true;
//            bool res = valid(x + 1, y, height, width, grid, visited, time) ||
//                       valid(x, y + 1, height, width, grid, visited, time) ||
//                       valid(x - 1, y, height, width, grid, visited, time) ||
//                       valid(x, y - 1, height, width, grid, visited, time);
//            visited[x][y] = false;
//            return res;
//        }
//        return false;
//    }
//};
#include <queue>

class Solution {
public:
    int swimInWater(std::vector<std::vector<int>> &grid) {
        int n = grid.size(), left = 0, right = n * n - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (valid(grid, mid, n))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }

    bool valid(std::vector<std::vector<int>> &grid, int time, int n) {
        std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));

        std::queue<std::pair<int, int >> q;
        q.emplace(std::make_pair(0, 0));

        while (!q.empty()) {
            std::pair<int, int> pair = q.front();
            q.pop();
            int x = pair.first, y = pair.second;
            if (x >= 0 && x < n && y >= 0 && y < n && !visited[x][y] && grid[x][y] <= time) {
                if (x == n -1 && y == n -1) return true;
                visited[x][y] = true;
                q.emplace(std::make_pair(x - 1, y));
                q.emplace(std::make_pair(x, y - 1));
                q.emplace(std::make_pair(x + 1, y));
                q.emplace(std::make_pair(x, y + 1));
            }
        }
        return false;
    }
};