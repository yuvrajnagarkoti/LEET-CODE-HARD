class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int ans = INT_MAX;
        while (low <= high) {
            int mid = (low + high) / 2;

            // Case when subarray is already sorted
            if (nums[low] < nums[high]) {
                ans = min(ans, nums[low]);
                break;
            }

            // Handle duplicates
            if (nums[low] == nums[high]) {
                ans = min(ans, nums[low]);
                low++;
                high--;
            }

            // Left half is sorted
            else if (nums[low] <= nums[mid]) {
                ans = min(ans, nums[low]);
                low = mid + 1;
            }

            // Right half is sorted
            else {
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};