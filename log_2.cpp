/* log2 example */
#include <stdio.h>      /* printf */
#include <math.h>       /* log2 */
#include <iostream>

using namespace std;
int main ()
{
  double param, result;
  param =  65536.0;
  result = log2 (param);
  printf ("log2 (%f) = %f.\n", param, result );
  long long test_param,test_result;
  test_param=3;
  test_result=log2(test_param)+1;
  cout<<"Test "<<ceil(test_result)<<endl;
  return 0;
}
