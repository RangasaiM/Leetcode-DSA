from collections import deque

class Solution:
    def bfs(self, visited, grid, i, j, m, n):
        q = deque([(i, j)])
        visited[i][j] = True

        while q:
            r, c = q.popleft()
            
            if r > 0 and grid[r - 1][c] == '1' and not visited[r - 1][c]:
                visited[r - 1][c] = True
                q.append((r - 1, c))
            
            if r < m - 1 and grid[r + 1][c] == '1' and not visited[r + 1][c]:
                visited[r + 1][c] = True
                q.append((r + 1, c))
            
            if c > 0 and grid[r][c - 1] == '1' and not visited[r][c - 1]:
                visited[r][c - 1] = True
                q.append((r, c - 1))
            
            if c < n - 1 and grid[r][c + 1] == '1' and not visited[r][c + 1]:
                visited[r][c + 1] = True
                q.append((r, c + 1))

    def numIslands(self, grid):
        m, n = len(grid), len(grid[0])
        cnt = 0
        visited = [[False] * n for _ in range(m)]

        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1' and not visited[i][j]:
                    self.bfs(visited, grid, i, j, m, n)
                    cnt += 1
        return cnt  