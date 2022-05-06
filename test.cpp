//

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
};

int main()
{
    // Your are given a sequence of inputs
    int maxLen = 0, maxProd = 1;

    int x; // to take input
    int currLen = 0, currProd = 1;
    while (true)
    {
        cin >> x; // scan from the stream
        if (x == -1)
        {
            break; // The sequence ends with a -1
        }
        if (x && currProd)
        {
            currLen++;
            currProd *= x;
        }
        else
        {
            // When input is 0, compare the maxRecord with current record

            if (currLen > maxLen)
            {
                maxLen = currLen;
                maxProd = currProd;
            }

            currLen = 0;
            currProd = 1;
        }
    }
    // return maxProd and MaxLen;
    return 0;
}