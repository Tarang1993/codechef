t=input()
while t!=0:
	n=input()
	if n==1:
		s=input()
		j=input()
		if s==j:
			print 0
		elif j<s:
			print s-j
		else:
			print -1
	else:
		h=raw_input().split()
		for i in range(0,n):
			h[i]=int(h[i])
		d=raw_input().split()
		diff=n*[0]
                for i in range(0,n):
                        d[i]=int(d[i])
			diff[i]=d[i]-h[i]
		if n==2:
			if sum(diff)!=0:
				print -1
			elif h!=d:
				print abs(diff[0])
			elif h==d:
				print 0			
		else:
			flag=0
			for i in range(0,n-1):
				for j in range(i+1,n):
					if (diff[i]-diff[j])%2!=0:
						flag=1
						break
		
			if flag==0:
				if sum(diff) == 0:
					if h == d:
						print 0
					else:
						print -1
				else:
					if sum(diff)%(n-2)==0 and abs(max(diff))<=sum(diff)/(n-2) and abs(min(diff))<=sum(diff)/(n-2):
						print sum(diff)/(n-2)
					else:
						print -1
			else:
				print -1
	t-=1 
