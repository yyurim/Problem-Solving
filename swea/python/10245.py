numbers = [i for i in map(int, input().split())]
 
num_set = set(numbers)
 
for i in num_set:
    if numbers.count(i) ==1:
        print(i)
        break