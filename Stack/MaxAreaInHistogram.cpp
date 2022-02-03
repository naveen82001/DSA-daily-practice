// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.

// Input: heights = [2,4]
// Output: 4

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> nler; // next least element right side
        stack<int> nlef; // next least element left side
        int n = heights.size();
        vector<int> nlerv(n); // array to store index of next least element to rigth side of every element
        vector<int> nlefv(n); // array to store index of next least element to rigth side of every element

        for (int i = n - 1; i >= 0; i--)
        {

            while (!nler.empty() and heights[nler.top()] >= heights[i])
                nler.pop();
            if (nler.empty())
                nlerv[i] = n;
            else
                nlerv[i] = nler.top();
            nler.push(i);
        }

        for (int i = 0; i < n; i++)
        {

            while (!nlef.empty() and heights[nlef.top()] >= heights[i])
                nlef.pop();
            if (nlef.empty())
                nlefv[i] = -1;
            else
                nlefv[i] = nlef.top();
            nlef.push(i);
        }

        // if r is index of nle to right side and l is index of  nle to left side for an element k
        // area will be (r-l-1)*k;

        int ans = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            ans = max({ans, heights[i], heights[i] * (nlerv[i] - nlefv[i] - 1)});
        }
        return ans;
    }
};

int main()
{
    return 0;
}