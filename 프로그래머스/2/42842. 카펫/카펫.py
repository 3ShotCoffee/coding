def solution(brown, yellow):
    for h in range(3, 5000):
        for w in range(h, 5000):
            b = 2 * h + 2 * w - 4
            y = (h - 2) * (w - 2)
            if (b == brown and y == yellow):
                return [w, h]