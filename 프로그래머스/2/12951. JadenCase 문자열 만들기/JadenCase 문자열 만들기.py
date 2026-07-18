def jadencase(word):
    new_word = ''
    new_word += word[0].upper()
    for i in range(1, len(word)):
        new_word += word[i].lower()
    return new_word

def solution(s):
    answer = ""
    word = ""
    for c in s:
        if c == " ":
            if (len(word) > 0):
                answer += jadencase(word)
                word = ""
            answer += c
        else:
            word += c
    if (len(word) > 0):
        answer += jadencase(word)
    
    return answer