xyz = set(map(int, input().split()))
ch = int(input())
if ch == 0:
	xyz.add(0)
while ch > 0:
	t = ch % 10
	xyz.add(t)
	ch = ch // 10
print(len(xyz)-3)
