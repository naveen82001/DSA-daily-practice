// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// Example 1:

// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps
// Example 2:

// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step

// https://www.youtube.com/watch?v=Y0lT9Fck7qI&list=PLot-Xpze53lcvx_tjrr_m2lgD2NsRHlNO&index=2

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countWays(int count, unordered_map<int, int> &mp, int n)
    {
        unordered_map<int, int>::iterator itr;
        if (count == n)
            return 1;
        else if (count > n)
            return 0;

        itr = mp.find(count);
        if (itr != mp.end())
            return mp[count];

        mp[count] = countWays(count + 1, mp, n) + countWays(count + 2, mp, n);
        return mp[count];
    }

    int climbStairs(int n)
    {
        unordered_map<int, int> mp;
        int count = 0;

        return countWays(count, mp, n);
    }
};

// efficient bottom up
// just the fibonacci
//  soln available in above given leetcode link