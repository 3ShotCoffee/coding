def solution(n):
    answer = 0
    
    # 숫자 i부터 시작하는 연속된 수로 구할 수 있는지?
    for i in range(1, n + 1):
        sum = 0
        for j in range(i, n + 1):
            sum += j
            if (sum == n):
                answer += 1
                break
            if (sum > n):
                break
            
    return answer