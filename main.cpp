#include <iostream>
#include <algorithm>
#include <math.h>
#include <fstream>

using namespace std;

int get_e(int t)
{
    for (int i=2; i<t; i++)
    {
        if(__gcd(i,t)==1)
        {
            return i;
        }
    }
    return -1;
}

int get_d(long long t,long long e)
{

    double d=0;
    int l=0;
    while(true)
    {
        d=(t*l+1)/(1.0 * e);
        if(d==(int)d)
        {
            break;
        }
        l++;
    }
    return floor(d);
}

long long mod(long long x, long long n, long long m)
{
    if(n==0)
        return 1;
    else if(n%2==0)
    {
        long long y = mod(x,n/2,m);
        return (y*y) %m;
    }
    else
    {
        return( ((x%m)* mod(x,n-1,m)) % m );
    }
}



int main()
{
    string x;
    cout<<"Enter the message"<<endl;
    cin>>x;
    long long arrayx[x.length()];
    long long arrayy[x.length()];
    long long arrayz[x.length()];
    for(int i=0; i<x.length(); i++)
    {
        arrayx[i]=int(x[i]);
    }
    long long p=7;
    long long q=19;
    long long n=p*q;
    long long t=(p-1)*(q-1);
    long long e=get_e(t);
    long long d=get_d(t,e);
    cout<<"decrypted message is "<<endl;
    for(int i=0; i<x.length(); i++)
    {
        cout<<arrayx[i]<<" ";
    }
    cout<<endl;
    cout<<"encrypted message is "<<endl;
    for(int i=0; i<x.length(); i++)
    {
        arrayy[i] = mod(arrayx[i],e,n);
        cout<<arrayy[i]<<" ";
    }
    cout<<endl;
    cout<<"encrypted message is"<<endl;
    for(int i=0; i<x.length(); i++)
    {
        arrayz[i] = mod(arrayy[i],d,n);
        cout<<arrayz[i]<<" ";
    }
    cout<<endl;
    for(int i=0; i<x.length(); i++)
    {
        char ascii =arrayz[i];
        cout<<ascii;
    }

    return 0;
}
