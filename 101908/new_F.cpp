#include <bits/stdc++.h>

using namespace std;

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

struct show
{
    int i, f, o;

    bool operator<(const show &a) const
    {
        return f < a.f;
    }
    friend ostream& operator<<(ostream& os, const show& a) { return os << a.i << a.f << a.o; }


};

vector<pair<int, int>> pd[(1 << 10) + 1];

int main()
{
    vector<vector<show>> shows;

    int n, m;

    cin >> n;

    shows.resize(n);

    vector<pair<int, int>> events;

    for(int i = 0; i < n; i++)
    {
        cin >> m;

        shows[i].resize(m);

        for(auto &it : shows[i])
            cin >> it.i >> it.f >> it.o, events.emplace_back(it.f, i);

        sort(shows[i].rbegin(), shows[i].rend());
    }

    sort(events.rbegin(), events.rend());
    dbg(events); dbg(shows);

    int maxi = (1 << n);

    pd[0].emplace_back(0, 0);

    while(events.size())
    {
        int k = events.back().second;
        events.pop_back();

        for(int i = 1; i < maxi; i++)
        {
            if((i & (1 << k)) == 0)
                continue;

            auto &shw = shows[k].back();

            int r = -(1 << 30);

            if(pd[i].size())
                for(auto &it : pd[i])
                    if(it.first <= shw.i)
                        r = max(r, it.second + shw.o);

            if(pd[i ^ (1 << k)].size())
                for(auto &it : pd[i ^ (1 << k)])
                    if(it.first <= shw.i)
                        r = max(r, it.second + shw.o);

            if(r != -(1 << 30))
                pd[i].emplace_back(shw.f, r);
        }

        shows[k].pop_back();
    }

    int r = -(1 << 30);

    if(pd[maxi - 1].size())
        for(auto &it : pd[maxi - 1])
            r = max(r, it.second);

    cout << (r < 0 ? -1 : r) << endl;
}
