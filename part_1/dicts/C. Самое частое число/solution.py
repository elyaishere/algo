import sys

text = sys.stdin.readlines()
d = dict()
mx_cnt = 0
mx_word = None
for line in text:
    words = line.split()
    for word in words:
        if word in d:
            d[word] += 1
        else:
            d[word] = 1
        if d[word] > mx_cnt:
            mx_cnt = d[word]
            mx_word = word
        elif d[word] == mx_cnt:
            if not mx_word or word < mx_word:
                mx_word = word

print(mx_word)
