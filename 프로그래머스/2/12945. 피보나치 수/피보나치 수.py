MOD = 1234567
dp = [-1] * 100001

def fibonacci(n):
    if dp[n] != -1:
        return dp[n]
    dp[n] = (fibonacci(n-1) % MOD + fibonacci(n-2) % MOD) % MOD
    return dp[n]

def solution(n):
    dp[0] = 0
    dp[1] = 1
    for i in range(2, n + 1):
        fibonacci(i)
    answer = fibonacci(n)
    return answer