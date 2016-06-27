struct D{
    int val,pos;
    D(int x,int y):val(x),pos(y){}
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<D> Q;
        vector<int> res;
        if(k==0 || nums.size()==0)
            return res;
        for(int i=0;i<k;i++){
            if(Q.empty())
                Q.push_back(D(nums[i],i));
            else{
                while(!Q.empty() && Q.front().val<nums[i]){
                    Q.pop_front();
                }
                Q.push_front(D(nums[i],i));
            }
        }
        
        for(int i=k;i<nums.size();i++){
            res.push_back(Q.back().val);
            
            if(Q.back().pos<=i-k)
                Q.pop_back();
            
            while(!Q.empty() && Q.front().val<nums[i]){
                Q.pop_front();
            }
            Q.push_front(D(nums[i],i));    
        }
        res.push_back(Q.back().val);
        return res;
    }
};