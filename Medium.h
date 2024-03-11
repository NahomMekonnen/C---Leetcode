
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

    // Bag of Tokens
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        sort(tokens.begin(), tokens.end());
        // int maxScore=0;
        int start = 0;
        int end = tokens.size() - 1;
        int score = 0;
        while (start <= end)
        {
            if (power >= tokens[start])
            {
                score++;
                power -= tokens[start];
                start++;
                // maxScore=max(score,maxScore);
            }
            else if (score > 0 && start != end)
            {
                score--;
                power += tokens[end];
                end--;
            }
            else
            {
                break;
            }
        }
        return score;
    }
    // Minimum Length of String After Deleting Similar Ends
public:
    int minimumLength(string s)
    {
        int start = 0;
        int end = s.size() - 1;
        while (start < end && s[start] == s[end])
        {
            char ch = s[start];
            while (start <= end && s[start] == ch)
            {
                start++;
            }
            while (end >= start && s[end] == ch)
            {
                end--;
            }
        }
        return end - start + 1;
    }
    // Delete node in a linked list
public:
    void deleteNode(ListNode *node)
    {
        ListNode *prev = node;
        while (node->next != nullptr)
        {
            int val = node->next->val;
            node->val = val;
            prev = node;
            node = node->next;
        }
        prev->next = nullptr;
    }
    // Minimum Common Value
public:
    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {
        // First solution
        // for(int i=0;i<nums1.size();i++)
        // {
        //     int target=nums1[i];
        //     int start=0;
        //     int end=nums2.size()-1;
        //     while(start<=end){
        //         int mid=start+(end-start)/2;
        //         if(nums2[mid]==target)
        //             return target;
        //         else if(nums2[mid]>target)
        //             end=mid-1;
        //         else
        //             start=mid+1;
        //     }
        // }
        // Second Solution
        // int n1=nums1.size();
        // int n2=nums2.size();
        // int i=0,j=0;
        // while(i<n1&&j<n2){
        //     if(nums1[i]<nums2[j])
        //         i++;
        //     else if(nums1[i]>nums2[j])
        //         j++;
        //     else
        //         return nums1[i];
        // }
        // return -1;
        // Third Solution
        // unordered_map<int,int> freq;
        // for(int i : nums1)
        //     freq[i]++;
        // for(int i : nums2)
        //     if(freq[i]>0)
        //         return i;
        // return -1;

        // Fourth Solution
        unordered_set<int> freq;
        for (int i : nums1)
            freq.insert(i);
        for (int i : nums2)
            if (freq.find(i) != freq.end())
                return i;

        return -1;
    }

    // Double a number represented as a linked list
public:
    ListNode *doubleIt(ListNode *head)
    {
        // First Solution
        // stack<int> nums;
        // ListNode* p=head;
        // while(p!=nullptr){
        //     nums.push(p->val);
        //     p=p->next;
        // }
        // int carry=0;
        // ListNode* ans=nullptr;
        // while(!nums.empty()){
        //     int num=nums.top();
        //     cout <<  num << endl;
        //     nums.pop();
        //     num*=2;
        //     num+=carry;
        //     if(num>=10)
        //     {
        //         carry=num/10;
        //         num=num%10;
        //     }else{
        //         carry=0;
        //     }
        //     ListNode* node=new ListNode(num,ans);
        //     ans=node;
        // }
        // if(carry)
        // {
        //     ListNode* node=new ListNode(carry,ans);
        //     ans=node;
        // }
        // return ans;
        // Second Solution
        head = reverseList(head);
        ListNode *p = head;
        int carry = 0;
        while (p)
        {
            int val = p->val;
            val *= 2;
            val += carry;
            carry = val / 10;
            val = val % 10;
            p->val = val;
            if (p->next == nullptr)
                break;
            p = p->next;
        }
        if (carry)
        {
            p->next = new ListNode(carry);
        }
        return reverseList(head);
    }
    ListNode *reverseList(ListNode *head)
    {
        // ListNode* prevPtr=nullptr;
        // ListNode* p=head;
        // while(p!=nullptr){
        //     ListNode* dummy=new ListNode(p->val);
        //     dummy->next=prevPtr;
        //     prevPtr=dummy;
        //     p=p->next;
        // }
        // return prevPtr;
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *forward = NULL;
        while (curr != NULL)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    // Custom Sort String
public:
    string customSortString(string order, string s)
    {
        unordered_map<char, int> letters;
        string answer = "";
        for (char i : s)
            letters[i]++;
        for (char i : order)
        {
            if (letters.find(i) != letters.end())
            {
                while (letters[i] > 0)
                {
                    answer += i;
                    letters[i]--;
                }
                letters.erase(i);
            }
        }
        if (!letters.empty())
        {
            for (auto it = letters.begin(); it != letters.end(); it++)
            {
                while (it->second > 0)
                {
                    answer += it->first;
                    it->second--;
                }
            }
        }
        return answer;
    }
    // Sort Colors
public:
    void sortColors(vector<int> &nums)
    {
        int start = 0;
        int mid = 0;
        int end = nums.size() - 1;
        while (mid <= end)
        {
            if (nums[mid] == 0)
            {
                swap(nums[mid], nums[start]);
                start++;
                mid++;
            }
            else if (nums[mid] == 2)
            {
                swap(nums[mid], nums[end]);
                end--;
            }
            else
            {
                mid++;
            }
        }
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