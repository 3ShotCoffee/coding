def solution(topping):
    leftd, rightd = {}, {}
    for t in topping:
        val = rightd.get(t, None)
        if (val is None):
            rightd[t] = 1
        else:
            rightd[t] += 1
    
    answer = 0
    for i in range(0, len(topping)):
        t = topping[i]
        if (rightd[t] == 1):        # rightd에서 삭제
            del rightd[t]
        else:
            rightd[t] -= 1
            
        val = leftd.get(t, None)    # leftd에 삽입
        if (val is None):
            leftd[t] = 1
        else:
            leftd[t] += 1
            
        if (len(leftd) == len(rightd)):     # dict 크기가 같으면 +1
            answer += 1
            
    return answer

# leftmap rightmap 토핑종류 : 개수
