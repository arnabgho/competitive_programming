#!/usr/bin/python
import math 

def power(a,b):
	if( b==0):
		return 1;
	elif(b==1):
		return a;
	else:		
		if(b%2==0):
			t=power(a,b/2);
			return t*t;
		else:
			t=power(a,b/2);
			return t*t*a;		 
		
		
def main():
	T=int(raw_input());
	c=0;
	while (c<T):
		c=c+1;
		L,D,S,C = [int(x) for x in raw_input().split()]	;
		lres=math.log10(S)+(D-1)*math.log10(1+C);
		lL=math.log10(L);
		temp=(1+C)**(D-1);
		res=S*temp;
		
		if(lres>=lL):
			print "ALIVE AND KICKING"
		else:
			print "DEAD AND ROTTING"
				
				
main();				
