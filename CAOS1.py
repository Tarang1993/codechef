t=input()

while t!=0:
        s=raw_input().split()
        r=int(s[0])
        c=int(s[1])
        a=[]
        ans=0
        for i in range(0,r):
                a.append(raw_input())
        if r<5 or c<5:
                print 0
        else:
                for i in range(2,r-2):
                        for j in range(2,c-2):
                                if a[i][j]=='^' and a[i][j+1]=='^' and a[i][j+2]=='^' and a[i][j-1]=='^' and a[i][j-2]=='^' and a[i-1][j]=='^' and a[i-2][j]=='^' and a[i+1][j]=='^' and a[i+2][j]=='^':

                                        ans=ans+1
                print ans
        t=t-1
