#include <vector>
#include <unordered_set>

using namespace std;

/*
Given two integer arrays nums1 and nums2, return an array of their
intersection. Each element in the result must be unique and you may return the result in any order.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
*/

vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
    unordered_set<int> set = unordered_set<int>(nums1.begin(), nums1.end());

    unordered_set<int> intersectionsSet = unordered_set<int>();

    vector<int>intersections = vector<int>();

    for (int n : nums2)
    {
        if (set.count(n))
        {
            intersectionsSet.insert(n);
        }
    }

    return vector<int>(intersectionsSet.begin(), intersectionsSet.end());
}

int main()
{
    vector<int> nums1 = { 4,9,5 };
    vector<int> nums2 = { 9,4,9,8,4 };

    vector<int> result = intersection(nums1, nums2);

    return 0;
}