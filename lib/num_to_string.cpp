#include <bits/stdc++.h>
using namespace std;

std::vector<std::string> tokenizer( const std::string& p_pcstStr, char delim )  {
        std::vector<std::string> tokens;
        std::stringstream   mySstream( p_pcstStr );
        std::string         temp;

        while( getline( mySstream, temp, delim ) ) {
            tokens.push_back( temp );
        }

        return tokens;
    } 


string space=" ";
class Solution {
public:
    vector<string> ones= std::vector<string>(10);
    vector<string> tens=std::vector<string>(10);
    vector<string> hundreds=std::vector<string>(10);
    vector<string> parts=std::vector<string>(10);
    vector<string> tennies=std::vector<string>(10);
    int num_digits(int n){
        int ans=0;
        while(n>0){
            ans++;
            n/=10;
        }
        return ans;
    }
    int pow(int a,int b){
        int ans=1;
        for(int i=0;i<b;i++)
            ans*=a;
        return ans;    
    }
    vector<int> Parts(int n,int num_parts){
        vector<int> res;
        int val=pow(10,3);
        while(n>0){
            int rem=n%val;
            res.push_back(rem);
            n/=val;
        }
        reverse(res.begin(),res.end());
        return res;
    }
    
    string num_to_words(int num){
        string res="";
        int n_digits=num_digits(num);
        if(n_digits==1)
            return ones[num];
        if(n_digits==3){
            int msd=num/100;
            res+=ones[msd]+space+hundreds[2];
            num=num%100;
        }
        if(num==0) return res;
        if(1<=num && num<=9)
            return res+space+ones[num];
        if(num%10==0){
            res=res+space+tens[num/10];
        }
        else{
            if( 11<=num && num<=19){
                res=res+space+tennies[num-10];
            }
            else{
                res=res+space+tens[num/10]+space+ones[num%10];
            }
        }
        return res;
    }

    string clean(string s){
        std::vector<string> v;
        v=tokenizer(s,' ');
        std::vector<string> v_clean;
        for (int i = 0; i < v.size(); ++i)
        {
            if(v[i].size()!=0)
                v_clean.push_back(v[i]);
        }
        string res="";
        for (int i = 0; i < v_clean.size()-1; ++i)
        {
            res+=v_clean[i]+space;
        }
        res+=v_clean[v_clean.size()-1];
        return res;
    }
    
    string numberToWords(int num) {
        if(num==0)
            return ones[0];
        int num_dig=num_digits(num);
        int num_parts;
        if(num_dig%3!=0)
            num_parts= num_dig/3+1;
        else
            num_parts=num_dig/3;
        vector<int> part=Parts(num,num_parts);
        string res="";
        for(int i=0;i<part.size();i++){
            // cout<<"num_parts-i "<<num_parts-i<<endl;
            if(part[i]==0) continue;
            string temp_res=num_to_words(part[i])+space+parts[num_parts-i];
            res=res+temp_res+space;
        }
        return clean(res);
    }

    Solution(){
        ones[0]="Zero";ones[1]="One";ones[2]="Two";ones[3]="Three";ones[4]="Four";ones[5]="Five";ones[6]="Six";ones[7]="Seven";ones[8]="Eight";ones[9]="Nine";
        tens[0]="Zero";tens[1]="Ten";tens[2]="Twenty";tens[3]="Thirty";tens[4]="Forty";tens[5]="Fifty";tens[6]="Sixty";tens[7]="Seventy";tens[8]="Eighty";tens[9]="Ninety";
        hundreds[2]="Hundred",hundreds[3]="Thousand";
        parts[4]="Billion",parts[3]="Million";parts[2]="Thousand";parts[1]=" ";parts[0]=" ";
        
        tennies[1]="Eleven";tennies[2]="Twelve";tennies[3]="Thirteen";tennies[4]="Fourteen";tennies[5]="Fifteen";tennies[6]="Sixteen";tennies[7]="Seventeen";tennies[8]="Eighteen";tennies[9]="Nineteen";
    }
};

int main(int argc, char const *argv[])
{
    Solution * s=new Solution();
    while(1){
        cout<<"If continue give number else give negative \n";
        int n;
        cin>>n;
        if(n<0) break;
        cout<<s->numberToWords(n)<<"-------"<<endl;
    }
    return 0;
}