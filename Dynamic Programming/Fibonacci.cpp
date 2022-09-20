#include<iostream>
using namespace std;

//Regular fibonacci function
int fib_reg(int n);

//Fibonacci Function using Dynamic Programming(Memoisation(Top-down))
int fib_memo(int n);

//Fibonacci Function using Dynamic Programming(Tabular(Bottom-up))
int fib_tabular(int n);

//Count no of function calls 
int functionCallCount[2]{0,0};

int main(){

    int n{5};
    cout<<"Output(regular fibonacci) :"<<fib_reg(n)<<" No of function calls :"<<functionCallCount[0]<<endl;
    cout<<"Output(memoised fibonacci) :"<<fib_memo(n)<<" No of function calls :"<<functionCallCount[1]<<endl;
    cout<<"Output(tabular fibonacci) :"<<fib_tabular(n)<<endl;
    return 0;
}

int fib_reg(int n)
{
    functionCallCount[0]++;
    if(n<=1)
        return n;
    return (fib_reg(n-1)+fib_reg(n-2));
}

int fib_memo(int n)
{
    functionCallCount[1]++;
    if(n<=1)
        return n;
    static int memoArr[6]{-1,-1,-1,-1,-1,-1};
    if(memoArr[n]!=-1)
        return memoArr[n];
    else
        memoArr[n]=fib_memo(n-1)+fib_memo(n-2);
    return memoArr[n];
}

int fib_tabular(int n)
{
    if(n<=1)
        return n;
    int f[n+1]{0,1};
    for(int i=2;i<=n;i++)
        f[i]=f[i-1]+f[i-2];
    return f[n];

    
}