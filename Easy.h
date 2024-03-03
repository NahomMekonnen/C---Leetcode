#include <vector>

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int total = (n * (n + 1) / 2);
        int sum = 0;
        for (int i : nums)
        {
            sum += i;
        }
        return total - sum;
    }

public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int t = 0;
        for (char i : letters)
        {
            int l = i;
            if (i > target)
            {
                t = l;
                break;
            }
        }
        if (t == 0)
            return letters[0];
        return (char)t;
    }
};