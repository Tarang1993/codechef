from math import sqrt
t=input()
while t!=0:
        n=input()
        c=0
        for i in range(2,int(sqrt(n))+1):
                if n%i==0:
                        if str(i).find('5')!=-1 or str(i).find('3')!=-1 or str(i).find('6')!=-1:
                                c+=1
                        #       print i
                        if str(n/i).find('5')!=-1 or str(n/i).find('3')!=-1 or str(n/i).find('6')!=-1:
                                c+=1
                        #       print n/i
 
 
        if str(n).find('3')!=-1 or str(n).find('5')!=-1 or str(n).find('6')!=-1:
                c+=1
        print c
        t-=1
