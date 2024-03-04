
#include <queue>
#include <algorithm>
#include <stack>
#include <numeric>
#include <cmath>
using namespace std;

/*Definition for singly-linked list. */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution1
{
    // Remove Nth Node From end of list

public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == nullptr)
            return nullptr;
        ListNode dummy(0);
        dummy.next = head;
        ListNode *slowptr = &dummy;
        ListNode *fastptr = &dummy;

        for (int i = 0; i < n; i++)
        {
            fastptr = fastptr->next;
        }

        if (fastptr == nullptr)
            return head->next;

        while (fastptr->next != nullptr)
        {
            slowptr = slowptr->next;
            fastptr = fastptr->next;
        }
        ListNode *temp = slowptr->next;
        slowptr->next = slowptr->next->next;
        delete temp;
        return dummy.next;
    }
    // Reverse Integer
public:
    int reverse(int x)
    {
        queue<int> digits;
        int sign = (x > 0 ? 1 : -1);
        int exp = -1;
        x = abs(x);

        while (x > 0)
        {
            digits.push(x % 10);
            x /= 10;
            exp++;
        }
        long y = 0;
        while (!digits.empty())
        {
            if (y > INT_MAX)
                return 0;
            y += digits.front() * pow(10, exp);
            exp--;
            digits.pop();
        }
        y *= sign;
        return (int)y;
    }
    // Search in Rotated Sorted array
public:
    int search(vector<int> &nums, int target)
    {
        auto it = find(nums.begin(), nums.end(), target);
        if (it != nums.end())
            return distance(nums.begin(), it);
        return -1;
    }
    // Search a 2D matrix
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int rows = matrix.size();
        if (rows == 0)
            return false;
        int cols = matrix[0].size();
        int start = 0;
        int end = rows * cols - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            int midval = matrix[mid / cols][mid % cols];

            if (midval == target)
                return true;
            else if (midval > target)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return false;
    }
    // Reverse words in a string
public:
    string reverseWords(string s)
    {
        stringstream ss(s);
        vector<string> words;
        string word;
        while (ss >> word)
        {
            words.push_back(word);
        }
        string answer = "";
        for (auto it = words.rbegin(); it != words.rend(); ++it)
        {
            answer += *it;
            answer += " ";
        }
        answer.erase(answer.size() - 1);
        return answer;
    }
    // Longest increasing subsequence
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int ans = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            int count = 1;
            int prev = nums[i];
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] > nums[i] && nums[j] > prev)
                {
                    prev = nums[j];
                    count++;
                }
            }
            ans = max(ans, count);
        }
        return ans;
    }
    // Insert Greatest common divisor in Linked list
public:
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *curr = head;
        while (curr != nullptr && curr->next != nullptr)
        {
            int x = curr->val;
            int y = curr->next->val;
            int z = gcd(x, y);
            ListNode *add = new ListNode(z);
            add->next = curr->next;
            curr->next = add;

            curr = curr->next->next;
        }
        return head;
    }
};

// Min Stack
class MinStack
{
    stack<int> hmm;
    stack<int> mins;

public:
    MinStack()
    {
    }
    void push(int val)
    {
        hmm.push(val);
        if (mins.empty() || mins.top() >= val)
            mins.push(val);
    }
    void pop()
    {
        int m = hmm.top();
        hmm.pop();
        if (mins.top() == m)
            mins.pop();
    }
    int top()
    {
        return hmm.top();
    }
    int getMin()
    {
        return mins.top();
    }
};
