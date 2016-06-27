#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

vector<string> tokenize(const string & str, const string & delim)
{
  vector<string> tokens;
  size_t p0 = 0, p1 = string::npos;

  while(p0 != string::npos)
  {
    p1 = str.find_first_of(delim, p0);
    if(p1 != p0)
    {
      string token = str.substr(p0, p1 - p0);
      tokens.push_back(token);
    }
    p0 = str.find_first_not_of(delim, p1);
 }
return tokens;
}

int main() {
  string s="I am Arnab Ghosh";
  std::vector<string> v;
  v=tokenize(s," ");
  for (int i = 0; i < v.size(); ++i)
  {
    cout<<v[i]<<endl;/* code */
  }
  return 0;
}