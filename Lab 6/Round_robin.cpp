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
        return a[1] < b[1];
}


int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    clock_t z = clock();

        
        int n,qt;    cin>>n>>qt;

        vector<vector<int>> v(n , vector<int>(3));
        loop(0,n)
        {
            loopj(0,3)
                cin>>v[i][j];
        }
        

        sort(all(v),compare);

        int completed = 0;

        vector<int> previus_time(n+1,0);
        vector<int> wt(n+1) , tat(n+1);
        vector<int> completion(n+1);
        vector<int> arrival_time(n+1);
        vector<int> burst_time(n+1);

        loop(0,n)
        {
            arrival_time[v[i][0]] = v[i][1];
            burst_time[v[i][0]] = v[i][2];
        }
        


        int time = 0;
        queue<vector<int>> q;

        q.push({v[0][0] , v[0][1] , v[0][2]});
        int nprocess = 1;

        int cas = -1;
        vector<int> temp;

        while(completed < n)
        {

            if( !q.empty() )
            {
                int arr = q.front()[1];
                int bt = q.front()[2];
                int id = q.front()[0];
                
                if( bt > qt)
                {
                    wt[id] += time - previus_time[id];
                    time += qt;
                    previus_time[id] = time;

                    temp = q.front();
                    q.pop();

                    temp[2] -= qt;
                    
                    cas = 1;
                }

                else
                {
                    wt[id] += time - previus_time[id];
                    time += bt;
                    previus_time[id] = time;
                    q.pop();
                    completed++;

                    completion[id] = time;

                    cas = 2;
                }
            }

            else
                time++;


            while(true)
            {
                if( nprocess < n && v[nprocess][1] <= time)
                {
                    q.push({v[nprocess][0] , v[nprocess][1] , v[nprocess][2]});
                    nprocess++;
                }
                else
                    break;
            }

            if( cas == 1)
                q.push(temp);

        }

        cout<<"Pr_ID\tWT\n";

        loop(0,n+1)
        {
            tat[i] = completion[i] - arrival_time[i];
            wt[i] = tat[i] - burst_time[i];
        }
        
        
        outvec(arrival_time);
        cout<<endl;
        outvec(completion);
        cout<<endl;
        outvec(wt);
        cout<<endl;
        outvec(tat);
        cout<<endl;

        double avwt = (sumvec(wt)*1.0)/(n*1.0);
        cout<<"Avg Wating time = "<<avwt<<endl;



//    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

  return 0;
}

/*
1.  Failing is good.
2.  Why Self-deprecate
*/