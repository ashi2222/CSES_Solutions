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
        string s;
        cin>>s ;
        set<string>st;
        int count =0;
        sort(s.begin() , s.end());
        do{
            st.insert(s);
        }while(next_permutation(s.begin() , s.end()));
        cout<<st.size()<<endl;
        for(auto i : st)
        {
            cout<<i<<endl;
        }


    }
    return 0;
}