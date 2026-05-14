import sys

text = sys.stdin.readlines()
d = dict()
for line in text:
	words = line.split()
	for word in words:
		if word in d:
			print(d[word])
			d[word] += 1
		else:
			print(0)
			d[word] = 1
