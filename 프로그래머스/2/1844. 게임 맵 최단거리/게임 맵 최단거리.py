from collections import deque

def solution(maps):
    n, m = len(maps), len(maps[0])
    visited = [[0] * m for _ in range(n)]
    
    directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]
    
    dq = deque([(0, 0, 1)])
    visited[0][0] = 1
    while dq:
        cur = dq.popleft()
        if (cur[0] == n - 1 and cur[1] == m - 1):
            return cur[2]
        for d in range(4):
            newR = cur[0] + directions[d][0]
            newC = cur[1] + directions[d][1]
            if newR < 0 or newR >= n or newC < 0 or newC >= m:
                continue
            if maps[newR][newC] == 0:
                continue 
            if visited[newR][newC]:
                continue
            visited[newR][newC] = 1
            dq.append((newR, newC, cur[2] + 1))
    
    return -1