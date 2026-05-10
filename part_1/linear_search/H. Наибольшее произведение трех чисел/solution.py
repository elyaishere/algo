seq = list(map(int, input().split()))
min_1 = min(seq[0], seq[1], seq[2])
min_3 = max(seq[0], seq[1], seq[2])
min_2 = seq[0] + seq[1] + seq[2] - min_1 - min_3
max_1, max_2, max_3 = min_3, min_2, min_1
for i in range(3, len(seq)):
    if seq[i] < min_1:
        min_1, min_2, min_3 = seq[i], min_1, min_2
    elif seq[i] < min_2:
        min_2, min_3 = seq[i], min_2
    elif seq[i] < min_3:
        min_3 = seq[i]
    if seq[i] > max_1:
        max_1, max_2, max_3 = seq[i], max_1, max_2
    elif seq[i] > max_2:
        max_2, max_3 = seq[i], max_2
    elif seq[i] > max_3:
        max_3 = seq[i]
if max_1 * max_2 * max_3 > min_1 * min_2 * max_1:
    print(max_3, max_2, max_1)
else:
    print(min_1, min_2, max_1)
