from collections import deque

def is_distanced(place, directions):
    dq = deque()
    visited = [[0] * 5 for _ in range(5)]
    for i in range(5):
        for j in range(5):
            if (place[i][j] != "P"):
                continue
            else:
                dq.append((i, j, 0))
                while dq:
                    cur = dq.popleft()
                    if (cur[2] >= 2):       # 거리가 2를 넘으면 보지 않음
                        continue
                    for d in directions:
                        newR = cur[0] + d[0]
                        newC = cur[1] + d[1]
                        if (newR < 0 or newR >= 5 or newC < 0 or newC >= 5):
                            continue
                        if (place[newR][newC] == "X"):
                            continue
                        if (place[newR][newC] == "P" and (newR != i or newC != j)):
                            return False
                        dq.append((newR, newC, cur[2] + 1))
                        visited[newR][newC] = 1
    return True  
                

def solution(places):
    answer = []
    directions = [[-1, 0], [1, 0], [0, 1], [0, -1]]
    
    for place in places:
        answer.append(1 if is_distanced(place, directions) else 0)
    
    
    return answer

# 맨해튼 거리가 2려면 하나 띄우고 앉든가 대각선으로 앉든가
# 각 사람에 대해서 내가 0을 따라 움직여서 거리 2 안쪽으로 다른 사람에 도달가능하면 X