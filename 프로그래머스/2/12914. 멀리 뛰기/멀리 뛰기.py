MOD = 1234567
dp = [-1] * 2001

def resolve(num):
    if (dp[num] != -1):
        return dp[num]
    dp[num] =  ((resolve(num-1) % MOD) + (resolve(num-2) % MOD)) % MOD;
    return dp[num]

def solution(n):
    dp[0] = 0
    dp[1] = 1
    dp[2] = 2
    for i in range(3, n + 1):
        resolve(i)
    
    return resolve(n)