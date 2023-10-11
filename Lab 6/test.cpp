#include <bits/stdc++.h>

#define int long long
#define all(a) a.begin(),a.end()
#define pb push_back
#define eb emplace_back
#define testcases int t; cin >> t; while(t--)
#define loop(a,b) for(int i=a;i<b;i++)
#define loopj(a,b) for(int j=a;j<b;j++)
#define sumvec(vec) accumulate(vec.begin(),vec.end(),(int)0)
#define sumarr(arr) accumulate(arr,arr+sizeof(arr)/sizeof(arr[0]),(int)0)
#define outarr(arr) for(int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++) cout<<arr[i]<<" ";
#define outvec(v) for(int j=0;j<v.size();j++) cout<<v[j]<<" ";
#define outmap(m) for(auto &it: m){ cout << it.first << " " << it.second << endl;}
#define remove_duplicate(v) v.erase(unique(all(v)), v.end());
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
using namespace std;


template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr (names + 1, ',');
    cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}



int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    clock_t z = clock();

        
        priority_queue<int> pq;

        pq.push(1);
        pq.push(2);
        pq.push(3);

        bug(pq.top());


//    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

  return 0;
}

/*
1.  Failing is good.
2.  Why Self-deprecate
*/