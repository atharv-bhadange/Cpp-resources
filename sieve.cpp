#include <bits/stdc++.h>
using namespace std;

vector<int> sieve(int n){
    int arr[n+1] = {0};
    vector<int> v;
    for(int i=2; i*i<=n; i++)
    {
        if(!arr[i])
        {
            for(int j=i*i; j<=n; j+=i)
            {
                arr[j] = 1;
            }
        }
    }

    for(int i=2; i<n; i++)
    {
        if(!arr[i])
        {
            v.push_back(i);
        }
    }

    return v;
}

void primefactors(int n){
    int spf[n+1] = {0};
    for(int i=2; i<=n; i++)
    {
        spf[i] = i;
    }

    for(int i=2; i<=n; i++)
    {
        if(spf[i]==i)
        { 
            for(int j=i*i; j<=n; j+=i)
            {
                spf[j]=i;
            }
        }
    }

    while(n!=1)
    {
        cout << spf[n] << " ";
        n= n/spf[n];
    }
}

int main(){
    int n; cin>>n;
    vector<int> v1 = sieve(n);
    for(auto x: v1) cout<<x<<" ";
    cout<<endl;
    primefactors(n);

    return 0;
}