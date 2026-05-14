n = int(input())
trustful_turtles = set()
ans = 0
for i in range(n):
	a, b = list(map(int, input().split()))
	if a >= 0 and b >= 0 and a + b == n - 1:
		if a not in trustful_turtles:
			trustful_turtles.add(a)
			ans += 1
print(ans)
