n = int(input())
x_coords = set()
for i in range(n):
	x, _ = list(map(int, input().split()))
	x_coords.add(x)
print(len(x_coords))
