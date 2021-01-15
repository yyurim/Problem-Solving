n = int(input())
 
dt = {}
for i in range(n):
    ani, lev = input().split()
    if lev not in dt:
        dt[lev] = []
    dt[lev].append(ani)
 
ans = set(dt[input()])
for i in ans:
    print(i,end=' ')