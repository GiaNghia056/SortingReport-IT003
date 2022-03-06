#include <bits/stdc++.h>

#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define mid ((l+r)>>1)
#define sz(a) (int)a.size()
#define file ""

using namespace std;

const ll oo = 2e18;
const int N = 2*100001;
const ll mod = 1e9 + 7;
typedef pair<ll,ll> ii;
typedef pair<ll,pair<ll,ll>> edge;
#define Speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

void Quicksort(ll a[], int l, int r)
{
    ll x = a[mid];
    int i = l, j = r;
    do
    {
        while(a[i] < x && i <= j) i++;
        while(a[j] > x && j >= i) j--;
        if(i<=j)
        {
            swap(a[i],a[j]);
            i++;j--;
        }
    }
    while(i<=j);
    if(i<r) Quicksort(a,i,r);
    if(l<j) Quicksort(a,l,j);
}
int main()
{
    Speed;
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    int n;
    cin>>n;
    ll a[n+1];
    for(int i =0 ;i<n;i++)
        cin>>a[i];
    Quicksort(a,0,n-1);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}
