w, h, n = list(map(int, input().split()))

l, r = 0, n * max(h, w)

while r != l:
    m = (l + r) // 2
    if (m//h) * (m//w) < n:
        l = m + 1
    else:
        r = m
print(l)
