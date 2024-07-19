//Ashish Patel

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define forn(i,n) for(int i = 0; i <n;i++) 
#define invec(a,n)  vector<int>a; for(int i =0 ; i < n ; i++){long long int x ; cin>>x; a.push_back(x);}
#define outvec(a,n) for(int i =0 ; i < n ; i++){cout<<a[i]<<" ";}cout<<endl;
#define vec(a,n) vector<int>a(n,0);
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;

void solve(int i, vector<int>&col , vector<int>&first , vector<int>&second , vector<vector<char>>&mat ,int &ans )
{
    if(i==8)
    {
        ans++;
        //cout<<"Succes "<<endl;
        return;
    }
    
    for(int j =0 ; j < 8 ; j++)
    {
        if(mat[i][j] == '*' or col[j]==1 or first[i+j]==1 or second[i-j+8]==1)
        {
            //cout<<"Terminated at "<<i<<" "<<j<<endl;
            // return;
            continue;
        }
        col[j] = 1 ;
        first[i+j] = 1;
        second[i-j+8] = 1;
        solve(i+1 , col , first , second , mat , ans);
        col[j] = 0;
        first[i+j] = 0;
        second[i-j+8] = 0;
    }
    
}
int main() {
    {
        vector<vector<char>>mat(8 , vector<char>(8));
        for(int i =0 ;i < 8 ; i++)
        {
            for(int j =0 ; j< 8 ; j++)
            {
                cin>>mat[i][j];
            }
        }
        vector<int>col(8 , 0);
        vector<int>first(64 , 0);
        vector<int>second(64 , 0);
        int ans =0 ;
        // we will place the queens on each row 
        // for(int j = 0 ; j < 8;  j++){
            solve(0 , col , first , second , mat , ans);
        // }
        cout<<ans<<endl;


    }
    return 0;
}