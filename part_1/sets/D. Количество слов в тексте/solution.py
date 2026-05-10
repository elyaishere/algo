import sys


lines = sys.stdin.readlines()
words = []
for line in lines:
	words += line.split()
print(len(set(words)))
