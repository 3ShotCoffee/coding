# x1, y1에서 시작 -> 시계방향
def rotate(x1, y1, x2, y2, board):
    # x1 고정, y1 -> y2
    # x1 -> x2, y2 고정
    # x2 고정, y2 -> y1
    # x2 -> x1, y1 고정
    xlen, ylen = x2 - x1, y2 - y1
    n = 2 * (xlen + ylen)
    xlist = [x1] * ylen + [x for x in range(x1, x2)] \
            + [x2] * ylen + [x for x in range(x2, x1, -1)]
    ylist = [y for y in range(y1, y2)] + [y2] * xlen \
            + [y for y in range(y2, y1, -1)] + [y1] * xlen
    
    tmp = [board[xlist[i] - 1][ylist[i] - 1] for i in range(n)]
    
    #print(tmp)
    
    minnum = float('inf')
    for i in range(n):
        board[xlist[i] - 1][ylist[i] - 1] = tmp[i - 1]
        minnum = min(minnum, board[xlist[i] - 1][ylist[i] - 1])
    
    return minnum
    
    
def solution(rows, columns, queries):
    answer = []
    
    board = [[0] * columns for _ in range(rows)]
    for i in range(rows):
        for j in range(columns):
            board[i][j] = 1 + i * columns + j
    
    for query in queries:
        answer.append(rotate(*query, board))
    
    return answer