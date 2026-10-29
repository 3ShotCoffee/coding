import sys
sys.setrecursionlimit(10**7)

dp = {}

def solution(x, y, n):
    dp[y] = 0
    
    answer = resolve(x, y, n)    
    if (answer == float('inf')):
        return -1
    else:
        return answer

def resolve(x, y, n):
    v = dp.get(x, None)
    if (v is not None):
        return v
    
    ret = float('inf')
    if (x + n <= y):
        ret = min(ret, resolve(x + n, y, n) + 1)
    if (2 * x <= y):
        ret = min(ret, resolve(2 * x, y, n) + 1)
    if (3 * x <= y):
        ret = min(ret, resolve(3 * x, y, n) + 1)
        
    dp[x] = ret
    return ret
    

# bfs를 하거나 dp를 하거나..