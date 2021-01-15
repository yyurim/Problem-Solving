input()
str1 = input()
str2 = input()
 
size = len(str1)
 
max = 0
ans = ''
for i in range(size):
    for start_idx in range(0,size-i):
        subs = str1[start_idx:start_idx+i]
        if subs in str2:
            if max < len(subs):
                max = i
                ans = subs
print(ans)