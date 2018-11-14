#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;

long long fiboiter(long long n)
{
    long long f = 0, i = 1;
    for(long long  k=1;k<n;k++)
    {
        f=i+f;
        i=f-i;
        cout<<setw(16) <<f;
    }
}
long long fiborecu(long long n)
{
    if(n<2) return n;
    return (fiborecu(n-1)+fiborecu(n-2));
}


int main(int argc, char *argv[])
{
    clock_t inicio, fim;
    long long n,i;
    double ptime;
    cout<<"Digite quantidade de termos: ";
    cin>>n;
    if(n<=0) cout<<"erro!!!\n";
    else
    {
        cout<<"Fibonacci interativo:\n";
        inicio = clock();
        fiboiter(n);
        fim=clock();
        ptime = fim-inicio;
        ptime = ptime/CLOCKS_PER_SEC;
        cout<<"\n"
              "tempo interativo = " << ptime << "segundos.\n";
        cout<<"\nFibonacci Recursivo:\n";
        inicio = clock();
        for(i=0; i<n; i++)
        {
            cout<<setw(16) << fiborecu(i+1);
        }
        fim = clock();
        ptime = fim-inicio;
        ptime = ptime/CLOCKS_PER_SEC;
        cout<<"\nTempo recursivo = " << ptime << "segundos.\n";
    }
    return 0;
}
