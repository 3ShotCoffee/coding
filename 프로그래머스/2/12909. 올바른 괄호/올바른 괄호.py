def solution(s):
    stack = []

    for c in s:
        if c == '(':
            stack.append(c)
        if c == ')':
            if len(stack) != 0 and stack[len(stack) - 1] == '(':
                stack.pop()
            else:
                return False
    
    if len(stack) == 0:
        return True
    else:
        return False