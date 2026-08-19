class Solution {
  public int nearestExit(char[][] maze, int[] s) {
        Queue<int[]> q = new LinkedList<>();
        int r = 1, dirs[] = {-1, 0, 1, 0, -1}, n = maze.length, m = maze[0].length;
        for (q.add(s), maze[s[0]][s[1]] = '+'; !q.isEmpty(); r++)
            for (int size = q.size(); size > 0; size--)
                for (int d = 1, p[] = q.poll(); d < dirs.length; d++) {
                    int x = p[0] + dirs[d - 1], y = p[1] + dirs[d];
                    if (0 <= x && x < n && 0 <= y && y < m && maze[x][y] == '.') {
                        if (x == 0 || x == n - 1 || y == 0 || y == m - 1)
                            return r;
                        maze[x][y] = '+';
                        q.add(new int[]{x, y});
                    }
                }
        return -1;
    }
};