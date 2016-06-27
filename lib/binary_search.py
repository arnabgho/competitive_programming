binary_search(lo, hi, p):
   while lo < hi:
      mid = lo + (hi-lo)/2
      if p(mid) == true:
         hi = mid
      else:
         lo = mid+1
          
   if p(lo) == false:
      complain                // p(x) is false for all x in S!
      
   return lo         // lo is the least x for which p(x) is true



 		int lo=0;
        int hi=n-1;
        int ans=0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            // cout<<"mid "<<mid<<endl;
            // cout<<"hi "<<hi<<endl;
            // cout<<"lo "<<lo<<endl;
            
            if(citations[mid]>=mid+1){
                ans=max(ans,mid+1);
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }