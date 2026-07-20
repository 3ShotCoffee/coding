def solution(elements):
    n = len(elements)
    
    s = set()
    for i in range(0, n):
        l = [(i + j) % n for j in range (0, n)]
        acc = 0
        for k in l:
            acc += elements[k]
            s.add(acc)
    
    return len(s)


# 간단히 생각해서 특정 수를 하나 찝어서 거기서부터 시작하는 부분수열의 합
# O(N^2)

