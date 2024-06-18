n=list(map(int,input().split()))
n=n[0]

cash=[0 for i in range(n+1)]
if n==1 or n==2:
    print(n)
else:
    cash[1],cash[2]=1,2
    for index in range(3,n+1):
        cash[index]=cash[index-1]+cash[index-2]
    print(cash[n]%10007)