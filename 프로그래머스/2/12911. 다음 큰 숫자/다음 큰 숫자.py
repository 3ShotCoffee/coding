def binary(num):
    ret = ""
    digit = 1
    while digit <= num:
        if ((num % (2*digit)) // digit == 0):
            ret = '0' + ret
        else:
            ret = '1' + ret
        digit *= 2
    return ret


def solution(n):
    cnt = binary(n).count('1')
    candidate = n + 1
    while True:
        if (cnt == binary(candidate).count('1')):
            return candidate
        candidate += 1
        