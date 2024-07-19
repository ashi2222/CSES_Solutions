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
ll ans;
vector<vector<int>>visited(7 , vector<int>(7 , 0));
string s;
bool check(int x, int y){
    return 0 <= x && x < 7 && 0 <= y && y < 7;
}
void solve(int index , int i , int j)
{
    if(index == s.size() and i==6 and j==0)
    {
        ans+=1;v
        return;
    }
    if(index==s.size())return ;
    if(i==6 and j==0)return ;
    
    if((!check(i+1, j) || visited[i+1][j]) && (!check(i-1, j) || visited[i-1][j]))
        if(check(i, j-1) && !visited[i][j-1] && check(i, j+1) && !visited[i][j+1])
            return;
    if((!check(i, j+1) || visited[i][j+1]) && (!check(i, j-1) || visited[i][j-1]))
        if(check(i+1, j) && !visited[i+1][j] && check(i-1, j) && !visited[i-1][j])
            return;
    
    visited[i][j]=1;
    if(s[index]=='D' or s[index]=='?')
    {
        if(check(i+1,j) and !visited[i+1][j])
        solve(index + 1 ,  i+1, j);
    }
     if(s[index]=='U' or s[index]=='?'){
        if(check(i-1,j) and !visited[i-1][j])
        solve(index + 1 ,  i-1 , j);
    }
    if(s[index]=='L' or s[index]=='?')
    {
        if(check(i,j-1) and !visited[i][j-1])
        solve(index + 1 ,   i , j-1);
    }
    if(s[index] == 'R' or s[index]=='?')
    {
        if(check(i,j+1) and !visited[i][j+1])
        solve(index+1 , i, j+1 );
    }
    visited[i][j] = 0;

}
int main() {
    
    {
        //string s ;
        cin>>s;
       // int index =0;
        //ll ans = 0;
        
        solve(0 , 0 , 0);
        cout<<ans<<endl;
    }
    return 0;
}