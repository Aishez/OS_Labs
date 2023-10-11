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

        
        int n;  cin>>n;

        int x,y;
        vector<pair<int,int>> process;

        loop(0,n)
        {
            cin>>x>>y;
            process.push_back({x,y});
        }

        sort(all(process));

        int time = 0;
        vector<int> wt(n) , tat(n);
        
        wt[0] = 0;
        time += process[0].second;
        tat[0] = wt[0] + process[0].second;

        loop(1,n)
        {
            bug(time);
            wt[i] = time - process[i].first;
            time += process[i].second;
            tat[i] = wt[i] + process[i].second;
        }

        bug(time);


        cout<<"Process\tWT\tTAT"<<endl;
        loop(0,n)
            cout<<i+1<<"\t"<<wt[i]<<"\t"<<tat[i]<<endl;

        double avgwt = sumvec(wt)*1.0/n*1.0;

        cout<<"avg wt = "<<avgwt<<endl;
        


//    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

  return 0;
}

/*
1.  Failing is good.
2.  Why Self-deprecate
*/