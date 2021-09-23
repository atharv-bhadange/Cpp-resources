#include<bits/stdc++.h>
using namespace std;

bool ispowerof2(int n){
    //To get n-1 from n in binary form, filpping the bits after rightmost set bit(1) would give n-1 
    //so if n is power of 2 then it's & with n-1 will be zero
          //'n &&' is done to treat corner case of 0
    return (n && !(n & n-1));
}

int onesinnumber(int n){
    // (n & n-1) gives same bits as n except the rightmost setbit

    int count = 0;
    while(n != 0)
    {
        n = n & (n-1);
        count++;
    }
    return count;
}

void unique_ele(int n){
    int arr[n];
    int xorus = 0;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        xorus = xorus ^ arr[i]; //same elements cancel out each other
    }

    cout<<xorus<<endl;
}

void two_unique_eles(int n){
    int arr[n];
    int xorus = 0;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        xorus = xorus ^ arr[i];
    }
    int sb = 0;
    int pos = 0;
    while(sb != 1)
    {
        sb = xorus & 1; //give the rightmost bit in binary representation of number
        pos++;
        xorus >>= 1;
    }
    
}

int main(){
    int n; cin>>n;
    //Q. Write a program to check if a number is power of 2
    //cout << ispowerof2(n) << endl;

    //Q. Write a program to count number of 1s in binary reprsentation of a number 
    //cout << onesinnumber(n) << endl;

    //Q. Write a program to find a unique number in an array where all numbers except one, are present twice.
    unique_ele(n);

    return 0;
}