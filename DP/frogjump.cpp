// There is a frog on the 1st step of an N stairs long staircase.
// The frog wants to reach the Nth stair.HEIGHT[i] is the height of the(i + 1) th stair.
// If Frog jumps from ith to jth stair, the energy lost in the jump is given by | HEIGHT[i - 1] - HEIGHT[j - 1] |.
// In the Frog is on ith staircase, he can jump either to(i + 1) th stair or to(i + 2) th stair.
// Your task is to find the minimum total energy used by the frog to reach from 1st stair to Nth stair.

// For Example If the given ‘HEIGHT’ array is[10, 20, 30, 10],
// the answer 20 as the frog can jump from 1st stair to 2nd stair(| 20 - 10 | = 10 energy lost)
// and then a jump from 2nd stair to last stair(| 10 - 20 | = 10 energy lost).So, the total energy lost is 20.

// sample input

// 2
// 4

// 10 20 30 10
// 3
// 10 50 10
// Sample Output 1:
// 20
// 0
// Explanation Of Sample Input 1:
// For the first test case,
// The frog can jump from 1st stair to 2nd stair (|20-10| = 10 energy lost).
// Then a jump from the 2nd stair to the last stair (|10-20| = 10 energy lost).
// So, the total energy lost is 20 which is the minimum.
// Hence, the answer is 20.

// For the second test case:
// The frog can jump from 1st stair to 3rd stair (|10-10| = 0 energy lost).
// So, the total energy lost is 0 which is the minimum.
// Hence, the answer is 0.

// https://www.youtube.com/watch?v=EgG3jsGoPvQ&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=4
// https://www.youtube.com/watch?v=Kmh3rhyEtB8&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=5

#include <bits/stdc++.h>
using namespace std;

// Memoisation

// int countMin(int idx,vector<int>& heights,vector<int> &dp) {
//     if (idx == 0) return 0;

//     if(dp[idx] != -1) return dp[idx];

//     int left = countMin(idx-1,heights,dp) + abs(heights[idx]-heights[idx-1]);
//     int right = countMin(idx-2,heights,dp) + abs(heights[idx]-heights[idx-2]);
//     if(idx == 1) right = INT_MAX;

//     dp[idx] = min(left,right);
//     return dp[idx];
// }

int frogJump(int n, vector<int> &heights)
{ // Write your code here.
    vector<int> dp(n, -1);
    // memoisation
    //     return  countMin(n-1,heights,dp);

    // tabulation
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        if (i == 1)
            dp[i] = abs(heights[i] - heights[i - 1]) + dp[i - 1];
        else
        {
            dp[i] = min(abs(heights[i] - heights[i - 1]) + dp[i - 1], abs(heights[i] - heights[i - 2]) + dp[i - 2]);
        }
    }
    return dp[n - 1];

    // space optimization take prev and prev2 instead of whole array -> present in above video
}