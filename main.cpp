

#include "Complex.h"
#include "TempDynArray.cpp"
#include <iostream>
using namespace std;

/** 
 * You can drop off the main() function
 * whenever use DynArray as a library.
 */
int main(int argc, char* argv[])
{
  DynArray<Complex> arr;

  for(int i = 0; i<5; i++)
    arr.add(Complex(i,i*i));
  cout<<arr<<endl;
	
  arr.insert(2,Complex(5,1));
  cout<<arr<<endl;
  
  arr[3] = Complex(6,2);
  cout<<arr<<endl;
  
  arr.remove(2);
  cout<<arr<<endl;

  arr.clear();
  cout<<arr<<endl;
 
  return 0;
}
