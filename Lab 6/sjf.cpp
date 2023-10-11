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


bool compare(vector<int> a , vector<int> b)
{
    if( a[1] == b[1])
    {
        if( a[2] == b[2])
            return a[0] < b[0];

        else
            return a[2] < b[2];
    }

    else
        return a[1] < b[1];
}

/*
1. First priority is arrival time then burst time
2. First sort by arrival time then by burst time
*/


int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    clock_t z = clock();

        
        int n;  cin>>n;

        vector< vector<int> > v(n, vector<int>(3));
        vector<int> wt(n+1) , tat(n+1) , schduling;

        wt[0]=0;
        tat[0]=0;

        loop(0,n)
        {
            loopj(0,3)
                cin>>v[i][j];
        }

        sort(all(v),compare);

        priority_queue< vector<int> , vector<vector<int>> , greater<vector<int>> > pq;


        pq.push( {v[0][2],v[0][1],v[0][0]});    // { burst time , arrival time , process id}
        int time = v[0][1];

        int sch = 1;

        while(!pq.empty())
        {
            // Assign CPU to the process having least burst time from the already arrived process

            int arr = pq.top()[1];                  // arrival time
            int bt = pq.top()[0];                   // burst time
            int id = pq.top()[2];                   // process id
            pq.pop();
        
            schduling.push_back(id);
            wt[id] = time - arr;
            tat[id] = wt[id]+bt;
            time += bt;


            while(true)
            {
                if( sch<n && v[sch][1] <= time)
                {
                    pq.push({v[sch][2],v[sch][1],v[sch][0]});
                    sch++;
                }

                else
                    break;
            }
        }


        cout<<"Process id\tWT\tTAT\n";

        for(auto &id : schduling)
            cout<<id<<"\t\t"<<wt[id]<<"\t"<<tat[id]<<endl;
        

        double avgwt = (sumvec(wt)*1.0)/(n*1.0);
        double avgtat = (sumvec(tat)*1.0)/(n*1.0);


        cout<<"Average wating time = "<<avgwt<<endl;
        cout<<"Average turn arround time = "<<avgtat<<endl;


//    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

  return 0;
}

/*
1.  Failing is good.
2.  Why Self-deprecate
*/