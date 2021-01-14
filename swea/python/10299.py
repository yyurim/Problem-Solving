n  = int(input())
n_list = input().split()
 
n_list[n] = "change"
for i in range(len(n_list)):
    if i==n:
        print(n_list[i],end=' ')
    else:
        print(int(n_list[i]),end=' ')