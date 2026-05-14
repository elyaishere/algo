n = int(input())
all_know = set()
some_know = set()
m = int(input())
for i in range(m):
	lang = input()
	all_know.add(lang)
	some_know.add(lang)
for i in range(n-1):
	m = int(input())
	one_know = set()
	for j in range(m):
		lang = input()
		one_know.add(lang)
		some_know.add(lang)
	all_know &= one_know
print(len(all_know))
print(*all_know, sep='\n')
print(len(some_know))
print(*some_know, sep='\n')
