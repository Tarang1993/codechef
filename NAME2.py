t = int(raw_input())
while t != 0:
    a = raw_input()
    s = a.split()
    if len(s[0]) > len(s[1]):
        x=s[0]
        y=s[1]
    else:
        x=s[1]
        y=s[0]
    l = len(x)
    ans=0
    c1=0
    c2=0
    while l!=0:
        
        if y[c1] == x[c2]:
            ans=ans+1
            c1=c1+1
            c2=c2+1
        else:
            c2=c2+1
        l=l-1
        if ans == len(y):
            break
    if ans == len(y):
        print "YES"
    else:
        print "NO"
    t = t-1
