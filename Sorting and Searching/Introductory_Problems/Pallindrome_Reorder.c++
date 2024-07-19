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

int main() {
    
    {
        string s ;
        cin>>s;
        unordered_map<char,int>mp;
        for(auto i : s)
        {
            mp[i]++;
        }
        string a="";
        string b="";
        char ashu ;
        int count = 0;
        bool flag = false;
        for(auto i : mp)
        {
            if(i.second %2 == 0)
            {
                string k="" ;
                k.insert(0, i.second/2 , i.first);
                a+=k;
                b = k+b;
            }
            else if(count == 0)
            {
                string k="" ;
                k.insert(0, i.second/2 , i.first);
                a+=k;
                b = k+b;
                ashu = i.first;
                count =1 ;
            }
           else if(count == 1)
           {
            flag  = true;
            break;
           }
        }
        if(flag)cout<<"NO SOLUTION"<<endl;
        else {
            if(count == 1)
            {
                a = a + ashu + b;
            }
            else{
                a = a+b;
            }
            cout<<a<<endl;
        }


    }
    return 0;
}