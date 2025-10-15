
/*

Rat in a Maze

Difficulty: MediumAccuracy: 35.75%Submissions: 382K+Points: 4Average Time: 25m
Consider a rat placed at position (0, 0) in an n x n square matrix maze[][]. The rat's goal is to reach the destination at position (n-1, n-1). The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).

The matrix contains only two possible values:

0: A blocked cell through which the rat cannot travel.
1: A free cell that the rat can pass through.
Your task is to find all possible paths the rat can take to reach the destination, starting from (0, 0) and ending at (n-1, n-1), under the condition that the rat cannot revisit any cell along the same path. Furthermore, the rat can only move to adjacent cells that are within the bounds of the matrix and not blocked.
If no path exists, return an empty list.

Note: Return the final result vector in lexicographically smallest order.

Examples:

Input: maze[][] = [[1, 0, 0, 0], [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1]]
Output: ["DDRDRR", "DRDDRR"]
Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.
Input: maze[][] = [[1, 0], [1, 0]]
Output: []
Explanation: No path exists as the destination cell (1, 1) is blocked.
Input: maze[][] = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
Output: ["DDRR", "RRDD"]
Explanation: The rat has two possible paths to reach the destination: DDRR and RRDD.
Constraints:
2 ≤ n ≤ 5
0 ≤ maze[i][j] ≤ 1

Expected Complexities
Company Tags
AmazonMicrosoft

*/





#include <bits/stdc++.h>
using namespace std;


/*
// optimized code
class Solution {
private:
    void findPaths(vector<vector<int>>& maze, int i, int j, int n, vector <string> &paths, string temp) {
        if (((i >= 0 && i < n) && (j >= 0 && j < n) && (maze[i][j] == 1)) == false) {
            return;
        }
        
        if (i == n-1 && j == n-1) {
            paths.push_back(temp);
            return;
        }
        
        maze[i][j] = 0;
        // down explore
        temp.push_back('D');
        findPaths(maze, i+1, j, n, paths, temp);
        temp.pop_back();
        
        // Left explore
        temp.push_back('L');
        findPaths(maze, i, j-1, n, paths, temp);
        temp.pop_back();
        
        // down explore
        temp.push_back('R');
        findPaths(maze, i, j+1, n, paths, temp);
        temp.pop_back();
        
        // down explore
        temp.push_back('U');
        findPaths(maze, i-1, j, n, paths, temp);
        temp.pop_back();
        
        maze[i][j] = 1;
    }
    
public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        
        int n = maze.size();
        int i = 0, j = 0;
        vector <string> paths;
        string temp;
        findPaths(maze, i, j, n, paths, temp);
        
        return paths;
    }
};
*/



// optimized code
// more cleaner code
class Solution {
private:
    bool checkInBoundry(int i, int j, int n) {
        if ((i >= 0 && i < n) && (j >= 0 && j < n)) {
            return true;
        }
        return false;
    }

    void findPaths(vector<vector<int>>& maze, int i, int j, int n, vector <string> &paths, string temp) {
        if (!checkInBoundry(i, j, n) || maze[i][j] == 0) {
            return;
        }
        
        if (i == n-1 && j == n-1) {
            paths.push_back(temp);
            return;
        }
        
        maze[i][j] = 0;
        // down explore
        temp.push_back('D');
        findPaths(maze, i+1, j, n, paths, temp);
        temp.pop_back();
        
        // Left explore
        temp.push_back('L');
        findPaths(maze, i, j-1, n, paths, temp);
        temp.pop_back();
        
        // down explore
        temp.push_back('R');
        findPaths(maze, i, j+1, n, paths, temp);
        temp.pop_back();
        
        // down explore
        temp.push_back('U');
        findPaths(maze, i-1, j, n, paths, temp);
        temp.pop_back();
        
        maze[i][j] = 1;
    }
    
public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        
        int n = maze.size();
        int i = 0, j = 0;
        vector <string> paths;
        string temp;
        findPaths(maze, i, j, n, paths, temp);
        
        return paths;
    }
};





// optimized code
// more More cleaner code
// tc = generaly 4 paths so tc = O(4^n^2)   n is the no of cells
// but more precisly tc = O(3^n^2)   because rat come from direction it will not go again to that same direction
// sc = o(m*n)  or (n^2) or no of cells
class Solution {
private:
    bool isInBounds(int i, int j, int n) {
        return (i >= 0 && i < n && j >= 0 && j < n);
    }
    
    void findPaths(vector<vector<int>>& maze, int i, int j, int n, vector<string>& paths, string path) {
        // Check for invalid cell or out of bounds
        if (!isInBounds(i, j, n) || maze[i][j] == 0)
            return;
    
        // Destination reached
        if (i == n - 1 && j == n - 1) {
            paths.push_back(path);
            return;
        }
    
        // Mark current cell as visited
        maze[i][j] = 0;
    
        // Explore all directions
        findPaths(maze, i + 1, j, n, paths, path + 'D'); // Down
        findPaths(maze, i, j - 1, n, paths, path + 'L'); // Left
        findPaths(maze, i, j + 1, n, paths, path + 'R'); // Right
        findPaths(maze, i - 1, j, n, paths, path + 'U'); // Up
        /*
        Here, path + 'D' creates a new string copy for each recursive call.
        That means every call has its own independent version of the string —
        so changes (adding 'D', 'L', 'R', 'U') do not affect the parent call.
        
        Terefore, you don’t need pop_back() anymore,
        because each recursive branch works with its own copy of path.
        */
    
        // Backtrack: unmark cell
        maze[i][j] = 1;
    }
// private section ends here
public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        
        int n = maze.size();
        int i = 0, j = 0;
        vector <string> paths;
        string temp;
        findPaths(maze, i, j, n, paths, temp);
        
        return paths;
    }
};





/*

#include <bits/stdc++.h>

using namespace std;

class Solution {
  void findPathHelper(int i, int j, vector < vector < int >> & a, int n, vector < string > & ans, string move,
    vector < vector < int >> & vis) {
    if (i == n - 1 && j == n - 1) {
      ans.push_back(move);
      return;
    }

    // downward
    if (i + 1 < n && !vis[i + 1][j] && a[i + 1][j] == 1) {
      vis[i][j] = 1;
      findPathHelper(i + 1, j, a, n, ans, move + 'D', vis);
      vis[i][j] = 0;
    }

    // left
    if (j - 1 >= 0 && !vis[i][j - 1] && a[i][j - 1] == 1) {
      vis[i][j] = 1;
      findPathHelper(i, j - 1, a, n, ans, move + 'L', vis);
      vis[i][j] = 0;
    }

    // right 
    if (j + 1 < n && !vis[i][j + 1] && a[i][j + 1] == 1) {
      vis[i][j] = 1;
      findPathHelper(i, j + 1, a, n, ans, move + 'R', vis);
      vis[i][j] = 0;
    }

    // upward
    if (i - 1 >= 0 && !vis[i - 1][j] && a[i - 1][j] == 1) {
      vis[i][j] = 1;
      findPathHelper(i - 1, j, a, n, ans, move + 'U', vis);
      vis[i][j] = 0;
    }

  }
  public:
    vector < string > findPath(vector < vector < int >> & m, int n) {
      vector < string > ans;
      vector < vector < int >> vis(n, vector < int > (n, 0));

      if (m[0][0] == 1) findPathHelper(0, 0, m, n, ans, "", vis);
      return ans;
    }
};

int main() {
  int n = 4;

   vector < vector < int >> m = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};

  Solution obj;
  vector < string > result = obj.findPath(m, n);
  if (result.size() == 0)
    cout << -1;
  else
    for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
  cout << endl;

  return 0;
}

*/




