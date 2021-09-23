#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    /*for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=i; j++)
        {
            if(i%2 == 0 && j%2 == 0)   // i + j % 2 == 0; 
            {
                cout << "1 ";
            }
            else if(i%2 != 0 && j%2 != 0)
            {
                cout << "1 ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }  */

    /*   //rohombus
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n-i; j++)
        {
            cout << "  ";
        }
        for(int j=1; j<=n; j++)
        {
            cout << "* ";
        }
        cout << '\n';
    }
    */

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n-i; j++)
        {
            cout << " ";
        }
        for(int j=1; j<=i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    

    return 0;
}