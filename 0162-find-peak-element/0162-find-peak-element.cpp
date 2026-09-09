#include <vector>

class Solution {
public:
    int findPeakElement(std::vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // If we are on an upward slope, peak is to the right
            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } 
            // If we are on a downward slope, peak is to the left (or is mid)
            else {
                right = mid;
            }
        }
        
        // left and right converge to the peak index
        return left;
    }
};