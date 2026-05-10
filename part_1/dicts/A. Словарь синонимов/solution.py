n = int(input())
d = dict()
for i in range(n):
	s1, s2 = input().split()
	d[s1] = s2
	d[s2] = s1
s = input()
print(d[s])
