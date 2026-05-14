n = int(input())
a = [30, 4000]
prev = float(input())
for i in range(n-1):
    c = input().split()
    c[0] = float(c[0])
    border = (prev + c[0]) / 2
    if c[1] == "closer":
        if c[0] < prev: 
            if a[1] > border:
                a[1] = border
        else:
            if a[0] < border:
                a[0] = border
    else:
        if c[0] > prev: 
            if a[1] > border:
                a[1] = border
        else:
            if a[0] < border:
                a[0] = border
    prev = c[0]
print(*a)
