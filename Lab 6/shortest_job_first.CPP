#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n, 0), burst(n, 0), arrival(n, 0);
    vector<pair<int, pair<int, int>>> v;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> burst[i] >> arrival[i];
        v.push_back({arrival[i], {--a[i], burst[i]}});
    }
    sort(v.begin(), v.end());

    int wt[n], tat[n];

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
    // priority_queue<pair<int, pair<int, int>>, greater<pair<int, pair<int, int>>>> q;
    int time = 0;
    map<int, pair<pair<int, int>, int>> m;
    // queue<pair<int,pair<int,int>>>q;
    pair<int, pair<int, int>> p = {v[0].second.second, {v[0].second.first, v[0].first}};
    q.push(p);
    int j = 1;
    int waiting = 0, turn = 0;
    cout << endl;
    while (q.size())
    {
        int ind = q.top().second.first;
        int burst_time = q.top().first;
        int arrival_time1 = q.top().second.second;
        q.pop();
        cout << ind + 1 << " " << arrival_time1 << " " << time << endl;
        int arrival_time = max(time, arrival_time1);
        time += burst_time;
        for (j; j < n; j++)
        {
            if (v[j].first > time)
                break;
            p = {v[j].second.second, {v[j].second.first, v[j].first}};
            q.push(p);
        }
        m[ind] = {{arrival_time, arrival_time1}, burst_time};
        waiting += arrival_time - arrival_time1;
        turn += arrival_time - arrival_time1 + burst_time;
        if (q.size() == 0 && j < n)
        {
            p = {v[j].second.second, {v[j].second.first, v[j].first}};
            q.push(p);
            j++;
        }
    }

    // wt[0] = v[0].first;
    // for (int i = 1; i < n ; i++ ) wt[i] = max(v[i-1].second.second + wt[i-1] , v[i].first) ;
    // for (int i = 0; i < n ; i++) tat[i] = v[i].second.second + wt[i];

    // cout << "Processes "<< " Burst time " << " Waiting time " << " Turn around time"<<endl;

    // double total_wt = 0, total_tat = 0;
    // for (int i=0; i<n; i++){
    //     // int i = v[j].second.first;
    // 	total_wt += m[i].first.first - m[i].first.second;
    // 	total_tat += m[i].first.first + m[i].second-m[i].first.second;
    // 	cout << " " << i+1 << "\t\t" << m[i].second <<"\t "<< m[i].first.first - m[i].first.second <<"\t\t " << m[i].first.first + m[i].second-m[i].first.second <<endl;
    // }

    cout << "Average waiting time = " << (double)waiting / n << endl;
    cout << "Average turn around time = " << (double)turn / n << endl;

    return 0;
}