import bisect

def solution(people, limit):
    answer = 0
    
    people.sort()
    
    left = 0
    right = len(people) - 1
    
    while left <= right:
        if people[left] + people[right] <= limit:
            left += 1
        right -= 1
        answer += 1
        
    return answer


# 50, 50, 70, 80
# 어쨌든 한 명을 더 태워야 한다고 생각하면 이왕이면 무거운 사람을 담는 게 낫다 -> X
# 탈 수 있다면 그 중 아무나 타도 된다.
