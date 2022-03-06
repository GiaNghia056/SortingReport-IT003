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

void heapify (ll a[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if(l < n && a[l] > a[largest])
        largest = l;
    if(r < n && a[r] > a[largest])
        largest = r;
    if(largest != i)
    {
        swap(a[i],a[largest]);
        heapify(a,n,largest);
    }

}

void HeapSort (ll a[], int n)
{
    for(int i=n/2-1;i>=0;i--)
        heapify(a,n,i);
    for(int i = n - 1; i>0;i--)
    {
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}
ll a[N];
int main()
{
    Speed;
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    HeapSort(a,n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}
