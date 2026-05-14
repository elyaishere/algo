list_1 = set(map(int, input().split()))
list_2 = set(map(int, input().split()))
print(*sorted(list_1 & list_2))
