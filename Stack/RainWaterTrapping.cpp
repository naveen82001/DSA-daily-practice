// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

// Input: height = [4,2,0,3,2,5]
// Output: 9

// basically just find the biggest element to left and right to every element;
// using those we can easily tell how many units of water can be stored above every element;

#include <bits/stdc++.h>
using namespace std;

int Solve(vector<int> &height)
{
    if (height.size() == 0)
        return 0;
    stack<int> left;
    stack<int> right;

    vector<int> lv(height.size());
    vector<int> rv(height.size());
    int temp;

    // finding biggest element in the left side of every element
    for (int i = 0; i < height.size(); i++)
    {
        temp = -1;
        if (left.empty())
            left.push(height[i]);
        else
        {
            while (!left.empty() and left.top() < height[i])
                left.pop();
            if (!left.empty())
                temp = left.top();
            else
                left.push(height[i]);
        }
        lv[i] = temp;
    }
    // finding biggest element in the right side of every element
    for (int i = height.size() - 1; i >= 0; i--)
    {
        temp = -1;
        if (right.empty())
            right.push(height[i]);
        else
        {
            while (!right.empty() and right.top() < height[i])
                right.pop();
            if (!right.empty())
                temp = right.top();
            else
                right.push(height[i]);
        }
        rv[i] = temp;
    }

    int ans = 0;
    for (int i = 0; i < height.size(); i++)
    {
        if (lv[i] == -1 || rv[i] == -1)
            continue;
        ans = ans + min(lv[i], rv[i]) - height[i];
    }
    return ans;
}

int main()
{
    vector<int> height = {4, 2, 0, 3, 2, 5};
    cout << Solve(height);
}