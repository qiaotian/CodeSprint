/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-06-23T04:35:55+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   root
* @Last modified time: 2016-06-23T13:28:57+08:00
* @License: Free License
*/

Given two arrays of length m and n with digits 0-9 representing two numbers. Create the maximum number of length k <= m + n from digits of the two. The relative order of the digits from the same array must be preserved. Return an array of the k digits. You should try to optimize your time and space complexity.

Example 1:
nums1 = [3, 4, 6, 5]
nums2 = [9, 1, 2, 5, 8, 3]
k = 5
return [9, 8, 6, 5, 3]

Example 2:
nums1 = [6, 7]
nums2 = [6, 0, 4]
k = 5
return [6, 7, 6, 0, 4]

Example 3:
nums1 = [3, 9]
nums2 = [8, 9]
k = 3
return [9, 8, 9]

class Soluton {
public:
    vector<int> maxVector(vector<int>& nums, int k) {
        vector<int> ans(k, 0);
        stack<int> s;

        int start = 0;
        for(int i=0; i<k; i++) {
            for(int j=start; j<nums.size()-k; j++){
                start = nums[j]>ans[i]?(j+1):start;
                ans[i] = max(nums[j], ans[i]);
            }
        }
        return ans;
    }

    vector<int> merge(vector<int>& nums1, vector<int>& nums2, int len1, int len2) {
        vector<int> ans(len1+len2, 0);

        vector<int> sub1 = maxVector(nums1, len1);
        vector<int> sub2 = maxVector(nums2, len2);

        for(int i=0, j=0, k=0; (i<len1 || j<len2) && r<len1+len2; k++) {
            if(i>=len1) ans[k] = nums2[j++];
            else if(j>=len2) ans[k] = nums1[i++];
            else {
                ans[k] = max(nums1[i], nums2[j]);
                if(nums1[i]>nums2[j]) i++;
                else j++;
            }
        }
        return ans;
    }

    bool cmp(vector<int>& nums1, vector<int>& nums2) {
        for(int i=0; i<nums1.size(); i++) {
            if(nums1[i]>nums2[i]) return true;
        }
        return false;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();

        string str1;
        string str2;

        for(auto i:nums1) str1+=(i+'0');
        for(auto i:nums2) str2+=(i+'0');

        vector<int> bench(k, 0);

        for(int i=max(0, k-n); i<min(k, m); i++) {
            int len1 = i;
            int len2 = k-i;
            vector<int> tmp = merge(nums1, nums2, len1, len2);
            if(cmp(tmp, bench)) bench = tmp;
        }
        return bench;
    }
};

class Solution {
public:
    /**
     * @param nums1 an integer array of length m with digits 0-9
     * @param nums2 an integer array of length n with digits 0-9
     * @param k an integer and k <= m + n
     * @return an integer array
     */

    vector<int> maxVector(vector<int>& nums, int k) {
        vector<int> ans(k, 0);
        stack<int> s;

        int start = 0;
        for(int i=0; i<k; i++) {
            for(int j=start; j<nums.size()-k; j++){
                start = nums[j]>ans[i]?(j+1):start;
                ans[i] = max(nums[j], ans[i]);
            }
        }
        return ans;
    }

    vector<int> merge(vector<int>& nums1, vector<int>& nums2, int len1, int len2) {
        vector<int> ans(len1+len2, 0);

        vector<int> sub1 = maxVector(nums1, len1);
        vector<int> sub2 = maxVector(nums2, len2);

        for(int i=0, j=0, k=0; (i<len1 || j<len2) && k<len1+len2; k++) {
            if(i>=len1) ans[k] = nums2[j++];
            else if(j>=len2) ans[k] = nums1[i++];
            else {
                ans[k] = max(nums1[i], nums2[j]);
                if(nums1[i]>nums2[j]) i++;
                else j++;
            }
        }
        return ans;
    }

    bool cmp(vector<int>& nums1, vector<int>& nums2) {
        for(int i=0; i<nums1.size(); i++) {
            if(nums1[i]>nums2[i]) return true;
            if(nums1[i]<nums2[i]) return false;
        }
        return false;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();

        vector<int> bench(k, 0);

        for(int i=max(0, k-n); i<min(k, m); i++) {
            int len1 = i;
            int len2 = k-i;
            vector<int> tmp = merge(nums1, nums2, len1, len2);
            cout << tmp[0] << endl;
            if(cmp(tmp, bench)) bench = tmp;
        }
        return bench;
    }
};
