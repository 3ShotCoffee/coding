def gcd(a, b):
    if (a%b == 0):
        return b
    return gcd(b, a%b)

def lcm(a, b):
    return a // gcd (a, b) * b

def solution(arr):
    answer = 1
    
    for num in arr:
        answer = lcm(answer, num)
    
    return answer