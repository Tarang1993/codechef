z=9500*[0]
z[1]=0
z[2]=1
for i in range(3,9500):
        z[i]=z[i-1]+z[i-2]
t=input()
 
while t!=0:
        p=raw_input()
        x=int(p)
        f=0
        for i in range(1,9500):
                if z[i]==x:
                        f=1
                        break
 
        if f==1:
                print "YES"
        else:
                print "NO"
        t-=1
