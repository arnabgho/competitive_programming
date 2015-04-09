def collatz:
	A[1]=0
	A[2]=1
	i=3	
	flag=0
	while i<=1000000 and !flag:
		x=i
		nsteps=0
		while x!=1:
			if x%2==0:	
				if A[x/2]!=0:
					nsteps+=A[x/2]+1
					A[i]=nsteps;
					if A[i]>maxm:
						maxi=i
						maxm=A[i]
					flag=1	
 				else:
					x=x/2
					nsteps++
			else
				
