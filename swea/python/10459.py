import re
 
arr = [[0,1,2,3,4],[1,1,1,2,2],[2,2,2,1,1],[2,2,2,1,1],[1,1,1,2,2]]
 
str_list= []
for r in range(5):
    temp = ""
    for c in range(5):
        temp += chr(arr[r][c]+65)
    str_list.append(temp)
     
for c in range(5):
    temp = ""
    for r in range(5):
        temp += chr(arr[r][c]+65)
    str_list.append(temp)
 
for i in range(1,5):
    temp = ""
    for j in range(i):
        temp += chr(arr[j][5-i+j]+65)
    str_list.append(temp)
 
temp = ""
for i in range(5):
    temp += chr(arr[i][i]+65)
str_list.append(temp)
     
for i in range(1,5):
    temp = ""
    for j in range(5-i):
        temp += chr(arr[i+j][j]+65)
    str_list.append(temp)
 
n = int(input())
for i in range(n):
    temp = input()
    ans = 0
    for s in str_list:
        ans += len(re.findall(temp,s))
    print(temp, ans)
