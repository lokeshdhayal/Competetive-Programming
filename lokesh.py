def f(n,s,m):
    if s == 0:
        return 1;
    p=f(n,s//2,m)
    if s%2==0:
        return p*p%m;
    else:
        return n*p*p%m;





for _ in range(int(input())):
    a=list(map(int,input().split(" ")))
    n=a[0]
    p=str(a[1])
    m=a[2]
    q=0;
    for i in p:
        q*=3;
        q+=int(i);
    print(f(n,q,m))