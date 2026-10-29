import heapq

def solution(book_time):
    answer = 0
    heap = []
    
    book_time = list(map(lambda x : [to_min(x[0]), to_min(x[1]) + 10], book_time))
    
    for start, _ in book_time:
        heapq.heappush(heap, start)
    
    maxcnt = 0
    for h in heap:
        cnt = 0
        for start, end in book_time:
            if (start <= h < end):
                cnt += 1
        if (cnt > maxcnt):
            maxcnt = cnt
    
    return maxcnt

def to_min(str):
    return int(str[0:2]) * 60 + int(str[3:5])

# 시작 시간 순으로 정렬
