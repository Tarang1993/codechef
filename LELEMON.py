t=input()
while t!=0:
        s=raw_input()
        s=s.split()
        n=int(s[0])
        m=int(s[1])
        p=raw_input()
        p=p.split()
        for i in range(0,m):
                p[i]=int(p[i])
        a=[]
        while n!=0:
                s=raw_input()
                s=s.split()
                for i in range(0,len(s)):
                        s[i]=int(s[i])
                a.append(s)
                n=n-1
        drink=0
        for i in range(0,m):
                drink+=int(max(a[p[i]][1:]))
                ind = a[p[i]].index(max(a[p[i]][1:]))
                a[p[i]][ind]=0;
#               print a[p[i]]
        print drink
        t=t-1
