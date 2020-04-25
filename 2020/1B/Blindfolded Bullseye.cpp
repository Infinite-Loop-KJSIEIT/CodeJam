#include <bits/stdc++.h>

using namespace std;

mt19937 gen;
uniform_int_distribution<int> dist(-1e9,1e9);

int main()
{
    int t, T, A, B;
    cin >> T >> A >> B;
    for (t = 1; t <= T; t++)
    {
        int x, y, done = 0;
        string s;
        while (1)
        {
            x = dist(gen), y = dist(gen);
            cout << x << " " << y << endl;
            cin >> s;
            if (s == "CENTER")
            {
                done = 1;
                break;
            }
            else if (s == "HIT")
                break;
        }
        if (done)
            continue;
        int l = -1e9, r = x;
        while (l < r)
        {
            int m = l + (r - l) / 2;
            cout << m << " " << y << endl;
            cin >> s;
            if (s == "CENTER")
            {
                done = 1;
                break;
            }
            if (s == "HIT")
                r = m;
            else
                l = m + 1;
        }
        if (done)
            continue;
        int ll = l;
        l = x, r = 1e9;
        while (l < r)
        {
            int m = l + (r - l + 1) / 2;
            cout << m << " " << y << endl;
            cin >> s;
            if (s == "CENTER")
            {
                done = 1;
                break;
            }
            if (s == "HIT")
                l = m;
            else
                r = m - 1;
        }
        if (done)
            continue;
        int rr = r;
        int cx = (ll + rr) / 2;
        l = -1e9, r = y;
        while (l < r)
        {
            int m = l + (r - l) / 2;
            cout << x << " " << m << endl;
            cin >> s;
            if (s == "CENTER")
            {
                done = 1;
                break;
            }
            if (s == "HIT")
                r = m;
            else
                l = m + 1;
        }
        if (done)
            continue;
        ll = l;
        l = y, r = 1e9;
        while (l < r)
        {
            int m = l + (r - l + 1) / 2;
            cout << x << " " << m << endl;
            cin >> s;
            if (s == "CENTER")
            {
                done = 1;
                break;
            }
            if (s == "HIT")
                l = m;
            else
                r = m - 1;
        }
        if (done)
            continue;
        rr = r;
        int cy = (ll + rr) / 2;
        cout << cx << " " << cy << endl;
        cin >> s;
        assert(s == "CENTER");
    }

    return 0;
}
