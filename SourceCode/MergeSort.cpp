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
const int N = 1000001;
const ll mod = 1e9 + 7;
typedef pair<ll,ll> ii;
typedef pair<ll,pair<ll,ll>> edge;
#define Speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

ll a[N];
ll L[N], R[N];
void Merge(ll a[], int l, int m, int r)
{
    int i,j,k;
    int n1 = m - l + 1;
    int n2 = r - m;

    for(i=0; i<n1; i++)
        L[i] = a[l+i];
    for(j=0; j<n2; j++)
        R[j] = a[m+j+1];
    i = 0;
    j = 0;
    k = l;
    while(i<n1 && j<n2)
    {
        if(L[i] <= R[j])
            a[k] = L[i],i++;
        else
            a[k] = R[j],j++;
        k++;
    }
    while(i<n1) a[k++] = L[i++];
    while(j<n2) a[k++] = R[j++];
}
void MergeSort(ll a[], int l, int r)
{
    if(r<=l) return;
    MergeSort(a,l,mid);
    MergeSort(a,mid+1,r);
    Merge(a,l,mid,r);
}
int main()
{
    Speed;
    //freopen("TestCase1.txt","r",stdin);
    //freopen("TestCase1.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    MergeSort(a,0,n-1);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}
