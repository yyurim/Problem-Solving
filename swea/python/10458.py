p = int(input())
apt = [i for i in map(int, input().split())]
 
apt = apt[:p]
 
apt.reverse()
 
now_max = apt[0]
cnt = 0
for i in range(1,len(apt)) :
        if apt[i-1] > apt[i]  :
            cnt +=1
        else:
            if now_max > apt[i]:
                cnt+=1
            else:
                now_max = apt[i]
                 
print(p-cnt+1)