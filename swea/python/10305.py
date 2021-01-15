def AA(string):
    print(string.upper(),end=' ')
 
 
def BB(n):
    print(n+10,end=' ')
 
     
a,b = input().split()
 
if  ord('A') <= ord(a[0]) <=ord('z'):
    AA(a)
    BB(int(b))
else:
    AA(b)
    BB(int(a))
print()