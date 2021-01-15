import re
 
n = int(input())
 
cnt = 0
for i in range(n):
    string = input()
    ans = re.findall("MINCO",string)
    cnt += len(ans)
     
print(cnt)