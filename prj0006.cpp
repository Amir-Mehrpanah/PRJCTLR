/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int
main ()
{
    int sumsq=0;
    int sqsum = pow(100*101/2,2);
    for(int i=1;i<101;i++){
        sumsq+=pow(i,2);
    }
    cout<<sqsum-sumsq;
    return 0;
}