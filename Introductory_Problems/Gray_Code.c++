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
vector<string>solve(int n )
{
    if(n==1)
    {
        return {"0" , "1"};
    }
    vector<string>ans;
    vector<string>ashu = solve(n - 1);
    for(int i =0; i < ashu.size() ; i++)
    {
        string k = "0" + ashu[i];
        ans.push_back(k);
    }
    vector<string>raj;
    for(int i =0 ; i< ashu.size() ; i++)
    {
        string k = "1" + ashu[i];
        raj.push_back(k);
    }
    reverse(raj.begin(), raj.end());
    for(int i =0 ;i < raj.size() ; i++)
    {
        ans.push_back(raj[i]);
    }
    return ans;
}
int main() {
   
    {

        int n;
        cin>>n;
        //vector<string>ans;
        vector<string>ans = solve(n);
        for(int i =0 ;i < ans.size() ; i++)
        {
            cout<<ans[i]<<endl;
        }

    }
    return 0;
}