from collections import deque
from math import ceil

def solution(progresses, speeds):
    answer = []
    dq = deque()
    
    for p, s in zip(progresses, speeds):
        dq.append(ceil((100 - p) / s))
    
    while dq:
        top = dq[0]
        cnt = 0
        while dq and dq[0] <= top:
            dq.popleft()
            cnt += 1
        answer.append(cnt)
    
    return answer

# 각 기능이 며칠 뒤에 개발 완료되는지 한 번의 패스로 구할 수 있음
# 7, 3, 9. 나보다 큰 애가 나올 때까지 한번에 빼면 된다