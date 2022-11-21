class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        d = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        xRange = len(maze)
        yRange = len(maze[0])
        visited = [[False for _ in range(yRange)] for _ in range(xRange)]
        
        queue = deque([[entrance[0], entrance[1], 0]])
        ans = 0
        while queue:
            x, y, level = queue.popleft()
            if [x, y] != entrance and (x == 0 or y == 0 or x == xRange-1 or y == yRange-1):
                return level
            for dx, dy in d:
                nx = x + dx
                ny = y + dy
                if 0 <= nx < xRange and 0 <= ny < yRange:
                    if maze[nx][ny] != '+' and not visited[nx][ny]:
                        queue.append((nx, ny, level + 1))
                        visited[nx][ny] = True
        return -1
    
