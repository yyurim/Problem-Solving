input_list = input().split()
n_list = [int(i) for i in input_list]
 
sum = 0
flag = False
for i in n_list:
    if i == 7:
        flag = True
    else:
        sum += i
if flag:
    print("lucky")
print(sum)