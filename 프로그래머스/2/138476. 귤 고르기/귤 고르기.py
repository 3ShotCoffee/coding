import bisect

def solution(k, tangerine):
    answer = 0
    
    tangerine.sort()
    
    nums = []       # 같은 크기의 귤이 몇 개 있는지?
    
    # 같은 크기를 가진 귤이 몇 개인지 확인
    i = 0
    while i < len(tangerine):
        size = tangerine[i]
        
        left = bisect.bisect_left(tangerine, size)
        right = bisect.bisect_right(tangerine, size)
        
        num = right - left
        nums.append(num)
        
        i = right
    
    nums.sort()
    
    total = 0
    while total < k:
        n = nums.pop()          # 가장 개수가 많은 것
        total += n
        answer += 1
        
    return answer



# k개를 고르기 100,000 C k
# 1, 2, 2, 3, 3, 4, 5, 5
# 1(1), 2(2), 3(2), 4(1), 5(2)
# 개수가 가장 적은 1, 4 크기를 없애면 됨.


# 소팅 -> 크기마다 개수 세서 (개수, 크기) -> 개수가 가장 많은 것부터 그리디. (팔 수 있으면 파는 것이 좋다)