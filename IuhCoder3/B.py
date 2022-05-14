n, m=map(int, input().split())
l=n-(n//4*4)
r=n-4
n=(r-l)//4+1
print(((n*(l+r))//2)%m)

