class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int i = 0, j = 0;
        double m;
        vector<int> v;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] < nums2[j])
            {
                v.push_back(nums1[i++]);
            }
            else if (nums1[i] > nums2[j])
            {
                v.push_back(nums2[j++]);
            }
            else
            {
                v.push_back(nums1[i++]);
            }
        }
        while (i < nums1.size())
        {
            v.push_back(nums1[i++]);
        }
        while (j < nums2.size())
        {
            v.push_back(nums2[j++]);
        }
        for (int i = 0; i < v.size(); ++i)
        {
            cout << v[i] << " ";
        }
        int n = v.size();
        double r = n % 2 == 0 ? (double)(v[n / 2] + v[n / 2 - 1]) / 2 : v[n / 2];
        return r;
    }
};
