def solution(record):
    answer = []
    u2n = {}
    
    for str in record:
        words = str.split(" ")
        if words[0] == "Change" or words[0] == "Enter":
            u2n[words[1]] = words[2]
        else:
            continue
    
    for str in record:
        words = str.split(" ")
        if words[0] == "Enter":
            answer.append(f"{u2n[words[1]]}님이 들어왔습니다.")
        elif words[0] == "Leave":
            answer.append(f"{u2n[words[1]]}님이 나갔습니다.")
    
    return answer

# 출입기록과 이름변경기록이 별도