/*
Suppose that (X, Y) = (7, 10). In what direction should we make our initial 1-unit jump? As we saw above, we need our final X coordinate to be odd, but it is currently even, and we have only one chance to go from even to odd. Moving north or south will make our Y coordinate odd, but then we will never have another chance to make that even and the X coordinate odd. So we should either move west or east. For now, let's guess that we will go west; we will revisit the other possibility later.

That jump will take us to (-1, 0), and we will next need to make a 2-unit jump. Notice that we can make this look identical to the original problem setup, if we make two changes:

Shift (-1, 0) to be the new (0, 0). Then the goal becomes (8, 10) rather than (7, 10).
Transform the scale of the problem such that a 2-unit jump (to a "neighboring" cell) becomes the new 1-unit jump. Then the goal becomes (4, 5) instead of (8, 10).
With this in mind, let's revisit our original decision to jump to the west. If we had jumped east instead, we would have ended up at (1, 0), and if we had changed the problem in the same way we did above, our new goal would have been (3, 5). But that would be an "even" position (after rescaling), which cannot be reached! So we had no choice after all; we had to move west to be able to eventually reach the goal. It's a good thing we were so lucky!

So now the problem has "reset", and we are at (0, 0) and trying to get to (4, 5). In what direction should we make our "first" jump? Now we know we must move vertically, since 5 is odd and we will only have "one chance" to go from even to odd. If we jump north, the next rescaling will have a target of (2, 2), but if we jump south, the target will be (2, 3), which is the "odd" position that we want. From there, we should jump south to change the target to (1, 2), then east to change the target to (0, 1). At that point, we have a choice between jumping north and reaching the goal, and jumping south (which could still allow us to reach the goal after some further moves, e.g. one more to the south and then one more to the north). But the problem requires that we choose the shortest solution, so we should jump right to the goal! Therefore, the answer in this case is WSSEN.

Notice that this method is deterministic: we always have only one choice out of the four possible directions. We can rule out two of them because they will not make the correct coordinate odd. Of the other two, the new goal states they would leave us with must differ only in one of the coordinates and only by exactly 1 unit, and therefore one must be an "odd" position and the other must be an "even" position. It is possible that that "even" position is the goal, in which case we should jump there, but otherwise, we must choose the "odd" position.

The above analysis also shows that the only time we have a choice is when one of those options is to jump directly to the goal, in which case we obviously should. So we can be confident that our method produces the shortest possible solution. (We also know that that solution is unique, since if we were to choose to not jump directly to the goal when we had that option, we would only end up with a longer solution.)

Our method has a running time which is logarithmic in the magnitudes of the coordinates, so it will solve this test set blazingly fast!
*/


// SOURCE CODE

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, T, X, Y;
    cin >> T;
    for (t = 1; t <= T; t++)
    {
        cin >> X >> Y;

        if (X%2 == Y%2)
            printf("Case #%d: IMPOSSIBLE\n", t);
        else
        {
            string ans;
            while (X || Y)
            {
                if (abs(X) + abs(Y) == 1)
                {
                    if ((X == 0) && (Y == 1))
                        ans += 'N', Y = 0;
                    else if ((X == 0) && (Y == -1))
                        ans += 'S', Y = 0;
                    else if ((Y == 0) && (X == 1))
                        ans += 'E', X = 0;
                    else
                        ans += 'W', X = 0;
                    break;
                }
                if (X & 1)
                {
                    int y = Y / 2, x = (X + 1) / 2;
                    if ((x + y) & 1)
                        ans += 'W', Y = y, X = x;
                    else
                        ans += 'E', Y = y, X = (X - 1) / 2;
                }
                else
                {
                    int y = (Y + 1) / 2, x = X / 2;
                    if ((x + y) & 1)
                        ans += 'S', Y = y, X = x;
                    else
                        ans += 'N', Y = (Y - 1) / 2, X = x;
                }
            }
            printf("Case #%d: %s\n", t, ans.c_str());
        }
    }

    return 0;
}
