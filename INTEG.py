n=input()
s=raw_input().split()
x=input()
c=0
n=len(s)
i=0
for i in range(0,len(s)):
        s[i]=int(s[i])
        if(s[i]>=0):
                s[i]=0
 
s=filter(lambda a: a != 0, s)
 
n=len(s)
if x==0:
        print 0
elif x==1:
        print abs(min(s))
else:
        sum1 = abs(sum(s))
        s.sort()
        a= s[x:n]
        sum2=abs(sum(a))
        print sum1-sum2
