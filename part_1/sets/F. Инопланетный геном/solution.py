first = input()
second = input()
second = set([second[i:i+2] for i in range(len(second)-1)])
ans = 0
for i in range(len(first)-1):
	if first[i:i+2] in second:
		ans += 1
print(ans)
