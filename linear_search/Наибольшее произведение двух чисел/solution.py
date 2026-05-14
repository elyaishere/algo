seq = list(map(int, input().split()))
min_1 = min(seq[0], seq[1])
min_2 = max(seq[0], seq[1])
max_1, max_2 = min_2, min_1
for i in range(2, len(seq)):
    if seq[i] < min_1:
        min_1, min_2 = seq[i], min_1
    elif seq[i] < min_2:
        min_2 = seq[i]
    if seq[i] > max_1:
        max_1, max_2 = seq[i], max_1
    elif seq[i] > max_2:
        max_2 = seq[i]
if max_1 * max_2 > min_1 * min_2:
    print(max_2, max_1)
else:
    print(min_1, min_2)
