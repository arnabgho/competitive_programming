def collatz():
	A={}
	i=0
	while(i<1000000000):
		A[i]=0 
		i=i+1
	A[1]=0
	A[2]=1
	i=3	
	flag=1
	maxi=0
	while i<=1000000 and flag:
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
					flag=0
 				else:
					x=x/2
					nsteps=nsteps+1
			else:
				if A[3*x+1]!=0:
					nsteps+=A[3*x+1]+1
					A[i]=nsteps;
					if A[i]>maxm:
						maxi=i
						maxm=A[i]
					flag=0	
 				else:
					x=3*x+1
					nsteps=nsteps+1
				
			A[i]=nsteps;
			if A[i]>maxm :
				maxi=i
				maxm=A[i]

	print maxi
	print maxm

collatz()
