def solution(citations):
    n = len(citations)
    max_h = 0
    for h in range(0, n + 1):
        cnt = 0
        for c in citations:
            if c >= h:
                cnt += 1
        if (cnt >= h and h > max_h):
            max_h = h
    
    return max_h