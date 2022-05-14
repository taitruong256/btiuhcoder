n=int(input())
if n%3!=0: 
    print(0)
    exit(0)
giaithua=[1]*(n+5)
mod=4022004
for i in range(1, n+1): giaithua[i]=(giaithua[i-1]*i) 
# print(giaithua[n], giaithua[n//3], giaithua[n-n//3])
ans=(giaithua[n//3]*giaithua[n-n//3])
ans=(giaithua[n]//ans)
print(ans)