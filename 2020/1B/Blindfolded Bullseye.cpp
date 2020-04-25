/*
To find the center of a circle, we can find 3 points on the edge of the circle, and then calculate a center from those. 
This has an issue: we only have nanometer precision, which means we would typically find points near the edge of the circle, but not 
exactly in it. 

The error that this introduces in our calculations could be significant. We can overcome this by bounding the error and then checking 
not only our calculated center, but also other nearby points too. The math to calculate the center, and most importantly, to bound the 
error of it, can be hard and time consuming, but it is doable. In addition, you can wing it by not bounding the error and instead 
starting to throw at your calculated center and then spiral around it on nearby points until you find the actual center. 
This requires a leap of faith that you won't run out of tries, but it's a reasonable assumption. Fortunately, there is a simpler related 
approach that is more clearly correct, that we describe below. Of course, we still need to solve the problem of finding "almost-edge" 
points of the circle, which we also need for our simpler approach.

To find a point in the edge, we can't use the approach in Test Set 1, because if the dartboard's radius is not very large, those points 
could be really far away from the wall's edge. A different way of doing it is via a binary search. Say we know that point (x0, y0) is 
within the dartboard. Then, we know that for all x in the range [-109, x0] the points (x, y0) are grouped such that there is a (possibly 
empty) interval having all misses, and then an interval having all hits. The same holds (in reverse) for [x0, 109]. Analogously, points 
(x0, y) for y in [-109, y0] or [y0, 109] are grouped by hits/misses. Then, for each of those ranges, we can do a binary search to find 
the switching point — that is, a point in the edge of the circle.

The searches above get us leftmost and rightmost points inside the dartboard for a given y-coordinate y0, and topmost and bottommost 
points for a given x-coordinate x0. Notice that the dartboard is symmetric with respect to the horizontal and vertical lines that go 
through its center. Therefore, the leftmost and rightmost points inside the dartboard in any fixed y-coordinate mirror each other, and 
the x-coordinate of the center is the midpoint between their x-coordinates. Similarly, we can find the y-coordinate of the center as 
the midpoint between the y-coordinates of the topmost and bottommost points inside the dartboard at any fixed x-coordinate.
The remaining task is to find a single point inside the dartboard. Since the area of the dartboard makes up a significant percentage of 
the wall area (at least π / 16), we could do this by throwing darts at random until we hit one point (the probability of hitting could 
be slightly less than π / 16 because we consider only points with integer nanometer coordinates, but the difference is negligible). 
This has an overwhelmingly high chance of hitting in 100 throws or fewer for all cases. However, there is a deterministic way that also 
works, which is to divide the wall into squares of side A. If the center of the dartboard is inside a square, it is guaranteed that at 
least one of the corners of that square is inside the dartboard. Therefore, we can simply try all those corners (there are only 25, and 
it is even possible to restrict it further), and we will find a hit point.

So, we need a fixed small number of darts (up to 100, depending on our method of choice) to find a point inside the dartboard, and each 
binary search needs at most 31 = ceil(log2 (2 × 109 + 1)). That is at most 4 × 31 + 100, which is a lot less than the 300 limit. In the 
first version, you need one fewer binary search — 3 edge points are enough to find a unique center — so after finding the center with 
error, you could have 150 darts left to explore its vicinity. Notice that if your initial point is actually one of the points (X - R, Y), 
(X + R, Y), (X, Y - R) or (X, Y + R), you would end up with two points instead of three and be unable to find the center. If we use the 
random procedure to find (x0, y0), the probability of this happening is negligible. Otherwise, we can detect the case and know that the 
two found points are opposite each other, so the center is their middle point.
*/

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
