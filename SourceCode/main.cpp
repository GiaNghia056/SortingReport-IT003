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

// Viết lại hàm random để sử dụng cho thuận tiện. Hàm random này sinh ngẫu nhiên số trong phạm vi long long, số sinh ra >= l và <= h.
ll a[N];
ll L[N], R[N];
unsigned long long llrand()
{
    unsigned long long r = 0;

    for (int i = 0; i < 5; ++i)
    {
        r = (r << 15) | (rand() & 0x7FFF);
    }

    return r & 0xFFFFFFFFFFFFFFFFULL;
}
long long Rand(long long l, long long h)
{
    assert(l <= h);
    return llrand() % (h - l + 1) + l;
}

string str (int n)
{
    string res = "";
    while(n)
    {
        res = char(n%10+'0') + res;
        n/=10;
    }
    if(res.size() == 0)
        res="0";
    return res;
}
void QuickSort(ll a[], int l, int r)
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
    if(i<r) QuickSort(a,i,r);
    if(l<j) QuickSort(a,l,j);
}

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
double solveQuickSort(string inp, string out)
{
    //Speed;
    ifstream cin ((inp + ".txt").c_str());
    //ofstream cout ((out + ".txt").c_str());
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    //cout<<1;
    clock_t start, end;
    double time_use;
    start = clock();
    QuickSort(a,0,n-1);
    end = clock();
    time_use = (double)(end - start) / CLOCKS_PER_SEC;
    return time_use;
}
double solveHeapSort(string inp, string out)
{
    //Speed;
    ifstream cin ((inp + ".txt").c_str());
    //ofstream cout ((out + ".txt").c_str());
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    //cout<<1;
    clock_t start, end;
    double time_use;
    start = clock();
    HeapSort(a,n);
    end = clock();
    time_use = (double)(end - start) / CLOCKS_PER_SEC;
    return time_use;
}
double solveMergeSort(string inp, string out)
{
    //Speed;
    ifstream cin ((inp + ".txt").c_str());
    //ofstream cout ((out + ".txt").c_str());
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    //cout<<1;
    clock_t start, end;
    double time_use;
    start = clock();
    MergeSort(a,0,n-1);
    end = clock();
    time_use = (double)(end - start) / CLOCKS_PER_SEC;
    return time_use;
}
double solveCppLibSort(string inp, string out)
{
    //Speed;
    ifstream cin ((inp + ".txt").c_str());
    //ofstream cout ((out + ".txt").c_str());
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    //cout<<1;
    clock_t start, end;
    double time_use;
    start = clock();
    sort(a,a+n);
    end = clock();
    time_use = (double)(end - start) / CLOCKS_PER_SEC;
    return time_use;
}

int main()
{
    srand(time(NULL));
    int T = 10, start = 1;
    string inp = "TestCase", out = "CppLibSortResult";
    ofstream fo ((out + ".txt").c_str());
    for(int i=0; i<T; i++)
    {
        string num = str(i + start);
        fo<<fixed<<setprecision(9);
        fo<<"Thoi gian chay "<<inp+" "+num<<" la: "<<solveCppLibSort(inp+num, out+num)<<"\n";
        cout<<"Test "<<i+start<<" "<<"OK\n";
    }
    return 0;
//cout<<Pow(2,29);
}

