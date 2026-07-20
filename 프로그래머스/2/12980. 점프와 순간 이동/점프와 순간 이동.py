def minimal_use(n):
    ret = 0
    dig = 1
    while dig <= n:
        ret += (n % (2 * dig)) // dig
        dig *= 2
    return ret
    
def solution(n):
    return minimal_use(n)

# "점프로 이동하는 것은 최소로 하려고 한다"
# dist(N) = dist(2N) = dist(4N) = dist(8N) = ...
# n보다 작은 가장 큰 2의 거듭제곱수? -> X

