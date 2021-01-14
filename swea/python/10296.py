n = int(input())
 
for i in range(n):
    t = str(i+1)
    cnt = 0
    for c in t:
        c = int(c)
        if c == 3 or c==6 or c==9:
            cnt += 1
    if cnt >0:
        for j in range(cnt):
            print("짝",end='')
        print(" ",end='')
    else:
        print(int(t),end=' ')