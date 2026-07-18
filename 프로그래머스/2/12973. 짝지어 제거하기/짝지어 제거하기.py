def solution(s):
    l = []
    for c in s:
        if (len(l) > 0 and l[len(l) - 1] == c):
            l.pop()
        else:
            l.append(c)
    if (len(l) > 0):
        return 0
    else:
        return 1
            
# abbaa