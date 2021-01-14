n_list = input().split()
n_list = [int(i) for i in n_list]
 
n_set = set(n_list)
 
if len(n_set) == 3:
    print("모두 다르다")
elif len(n_set) == 2:
    print("일부 같다")
else:
    print("모두 같다")