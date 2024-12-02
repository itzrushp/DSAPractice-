#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ar array
#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)

template <class T>
void read(T &x)
{
    cin >> x;
}
template <class H, class... T>
void read(H &h, T &...t)
{
    read(h);
    read(t...);
}

string to_string(char c)
{
    return string(1, c);
}
string to_string(bool b)
{
    return b ? "true" : "false";
}
string to_string(const char *s)
{
    return string(s);
}
string to_string(string s)
{
    return s;
}

template <class T>
void write(T x)
{
    cout << to_string(x);
}
template <class H, class... T>
void write(const H &h, const T &...t)
{
    write(h);
    write(t...);
}

void print()
{
    write("\n");
}
template <class H, class... T>
void print(const H &h, const T &...t)
{
    write(h);
    if (sizeof...(t))
        write(' ');
    print(t...);
}

const int d4i[4] = {-1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};
const int d8i[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    set<int> s;
    int q = 1;
    int n = 1;
    cin >> n;
    cin >> q;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        s.insert(a);
    }
    int count = 0;

    while (q--)
    {
        int x = 0;
        cin >> x;

        auto it = s.lower_bound(x);
        int count_less_than_x = distance(s.begin(), it);

        auto iti = s.upper_bound(x);
        int count_more_than_x = distance(iti, s.end());

        cout << count_less_than_x << " " << count_more_than_x << "\n";
    }

    return 0;
}