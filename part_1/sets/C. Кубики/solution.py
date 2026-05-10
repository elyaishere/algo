n, m = list(map(int, input().split()))
cubes_a = set()
cubes_b = set()
for i in range(n):
	t = int(input())
	cubes_a.add(t)
for i in range(m):
	t = int(input())
	cubes_b.add(t)
common = cubes_a & cubes_b
print(len(common))
print(*sorted(common))
cubes_a -= common
print(len(cubes_a))
print(*sorted(cubes_a))
cubes_b -= common
print(len(cubes_b))
print(*sorted(cubes_b))
