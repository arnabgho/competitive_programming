#include <iostream>
#include <string>

using namespace std;
int main ()
{
  std::string str1 ("10");
  std::string str2 ("11");
  // int ans=str1.compare(str2);
  int ans=str1<str2;
  cout<<ans;
  return 0;
}  