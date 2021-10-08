#include<bits/stdc++.h>
using namespace std;

void binarysearch(int arr[], int n, int k)
{
    int low, high;
    bool flag = 0;
    low = 0; high = n;
    while (low<=high)
    {
        int mid;
        mid = (high+low)/2;
        if(arr[mid] == k)
        {
            cout << "Found";
            flag = 1;
            break;
        }
        else if(arr[mid] > k)
        {
            high = mid-1;
        }
        else if(arr[mid] < k)
        {
            low = mid+1;
        }
    }
    if(flag == 0)
    {
        cout << "Not found";
    }
}

int kadane(int arr[],int n)
{
    int cs = 0;
    int maxSum = INT_MIN;
    for(int i=0; i<n; i++)
    {
        cs = cs + arr[i]; 
        if(cs < 0)
        {
            cs = 0;
        }
        maxSum = max(maxSum, cs);
    }
    return maxSum;
}


int main(){
    /*********************
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    **********************/

    //sort(arr, arr + n);
    //binarysearch(arr, n, k);

    /*******************************
    int maxi = 0;
    for(int i=0; i<n; i++)
    {
        maxi = max(maxi, arr[i]);
        cout << maxi << " ";
    }
    ********************************/

    /******************************
    int sum = 0; 
    for(int i=0; i<n; i++)
    {
        sum = 0;
        for(int j=i; j<n; j++)
        {
            sum += arr[j];
            cout << sum << " ";
        }
        
    }
    *******************************/

    /*************************
     int t;
     cin >> t;
    int k = 1;
    for(k=1; k<=t; k++)
    {
        int n;
        cin >> n;
        int a[n];

        for(int i=0; i<n; i++)
        {
            cin >> a[i];
        }
    *****************************/
        

        /*****************************
        int maxi = 2;
        int pd = a[1] - a[0];
        int curr = 2;
        for(int j=2; j<n; j++)
        {
            if(pd == a[j] - a[j-1])
            {
                curr++;
            }
            else
            {
                pd = a[j] - a[j-1];
                curr = 2;
            }
            maxi = max(maxi, curr);
            //cout << curr << endl;
        }
        cout << '#' << k << ": " << maxi;
        *******************************/

        /****************************
        int maxi = 0;
        int ct = 0;
        for(int i=0; i<n; i++)
        {
           
            if(i==0)
            {
                if(a[1] < a[0])
                {
                    ct++;
                    maxi = a[0];
                }
            }
            else if(i>0 && i<n-1)
            {
                if(a[i]>a[i+1] && a[i]>maxi)
                {
                    ct++;
                    maxi = max(a[i], maxi);
                }
            }
            else if(i == n-1)
            {
                if(a[i]>maxi)
                {
                    ct++;
                }
            }
        }
        cout << ct << endl;
        *******************************/
    //}

    /******************************
    int n;
    cin >> n;
    int mx = 0;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }

    int idx[mx+1];
    for(int i=0; i<=mx+1; i++)
    {
        idx[i] = -1;
    }
    int minidx = INT_MAX;
    for(int i=0; i<n; i++)
    {
        if(idx[arr[i]] == -1)
        {
            idx[arr[i]] = i;
        }
        else if(idx[arr[i]] != -1)
        {
            minidx = min(minidx, idx[arr[i]]);
        }
    }
    cout << minidx + 1 << endl;
    ********************************/
 
    /******************************* 
    int n, s;
    cin >> n >> s;

    int a[n];
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    int i=0, j=0, sum=0;
    int st, en;

    while(j<n && sum+a[j]<=s)
    {
        sum += a[j];
        j++;
    }
    if(sum == s)
    {
        cout << i+1 << " " << j << endl;
        return 0;
    }

    while(j<n)
    {
        sum += a[j];
        while(sum > s)
        {
            sum -= a[i];
            i++
        }
        if(sum == s)
        {
            st = i+1;
            en = j+1;
            break;
        }
        j++;
    }

    cout << st << " " << en << endl;
    *********************************/

    /**********************************
    int n;
    cin >> n;

    int a[n];
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    const int t = 2e6 + 5;
    bool check[t];
    for(int i=0; i<t; i++)
    {
        check[i] = 0;
    }

    for(int i=0; i<n; i++)
    {
        if(a[i] > 0)
        {
            check[a[i]] = 1;
        }
    }
    int ans = -1;
    for(int i=0; i<t; i++)
    {
        if(check[i] == 0)
        {
            ans = i;
            break;
        }
    }

    ans == 0 ? cout << -1 : cout << ans;
    ************************************/

    // Subarrays
    
/*
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n;i++)
    {
        cin >> arr[i];
    }
*/

/********************************
    O(n**2) solution
    int csa[n+1];
    csa[0] = 0;
    for(int i=1; i<=n; i++)
    {
        csa[i] = csa[i-1] + arr[i-1];
    }

    int maxsum = INT_MIN;
    for(int i=1; i<=n; i++)
    {
        int sum = 0;
        for(int j=0; j<i; j++)
        {
            sum = csa[i] - csa[j];
            maxsum = max(maxsum, sum);
        }
    }

    cout << maxsum;
****************************************/
/****************************************
    //O(n) solution
    //kadane algo
    
    int cs = 0;
    int maxSum = INT_MIN;
    for(int i=0; i<n; i++)
    {
        cs = cs + arr[i]; 
        if(cs < 0)
        {
            cs = 0;
        }
        maxSum = max(maxSum, cs);
    }
    cout << maxSum;
*******************************************/

//Circular sub array
/*****************************************
int nonwrap_maxSum;
nonwrap_maxSum = kadane(arr, n);
//cout << nonwrap_maxSum << endl;

int sumarr = 0;
for(int i=0; i<n; i++)
{
    sumarr = sumarr + arr[i];
    arr[i] = (-1)*arr[i];
}

int wrap_maxSum = kadane(arr, n);
wrap_maxSum = (-1) * wrap_maxSum;
//cout << sumarr - wrap_maxSum << endl;

cout << max(nonwrap_maxSum,(sumarr - wrap_maxSum)) << endl;
**************************************************************/

/******************************************
// pair sum
int k;
cin >> k;
sort(arr, arr + n);
int st = 0;
int en = n-1;
while(st<en)
{
    if(arr[st] + arr[en] == k)
    {
        cout << st << " " << en << endl;
        cout << 1;
        break;
    }
    else if(arr[st] + arr[en] < k)
    {
        st++;
    }
    else if(arr[st] + arr[en] > k)
    {
        en--;
    }
}
*************************************/

/////////////////////Character array/////////////////////////
/*
char arr[100]; // char arr[n+1];
cin >> arr;
cout << arr[4];


int n;
cin >> n;
char a[n+1];
cin >> a;
bool check = 1;
for(int i = 0; i < n; i++)
{
    if(a[i] != a[n-1-i])
    {
        check = 0;
    }
}

cout << check;
*/

int n;
cin >> n;
cin.ignore();

char a[n+1];

cin.getline(a, n);
cin.ignore();


    return 0;
}