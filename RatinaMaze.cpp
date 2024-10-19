#include <iostream>
#include <vector>

using namespace std;

// Function to check if a cell is valid
bool isSafe(int x, int y, int N, vector<vector<int>>& maze, vector<vector<int>>& path) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1 && path[x][y] == 0);
}

// Recursive function 
void solveMazeUtil(int x, int y, int N, vector<vector<int>>& maze, vector<vector<int>>& path, vector<vector<int>>& allPaths) {
    // Base case
    if (x == N-1 && y == N-1) {
        path[x][y] = 1;
        vector<int> currentPath;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (path[i][j] == 1) {
                    currentPath.push_back(i * N + j + 1);
                }
            }
        }
        allPaths.push_back(currentPath);
        path[x][y] = 0;  // Backtrack
        return;
    }
    
    // Mark the cell
    path[x][y] = 1;

    // Move in all possible directions: Down, Up, Right, Left
    if (isSafe(x + 1, y, N, maze, path)) {
        solveMazeUtil(x + 1, y, N, maze, path, allPaths);
    }
    if (isSafe(x, y + 1, N, maze, path)) {
        solveMazeUtil(x, y + 1, N, maze, path, allPaths);
    }
    if (isSafe(x - 1, y, N, maze, path)) {
        solveMazeUtil(x - 1, y, N, maze, path, allPaths);
    }
    if (isSafe(x, y - 1, N, maze, path)) {
        solveMazeUtil(x, y - 1, N, maze, path, allPaths);
    }
    
    // Unmark the cell as part of the path (Backtrack)
    path[x][y] = 0;
}

// main function
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n) {
    vector<vector<int>> path(n, vector<int>(n, 0));  // Initialize path matrix with 0s
    vector<vector<int>> allPaths;

    if (maze[0][0] == 1 && maze[n-1][n-1] == 1) {
        solveMazeUtil(0, 0, n, maze, path, allPaths);
    }

    return allPaths;
}
