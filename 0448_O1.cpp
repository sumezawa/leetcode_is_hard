/* CASE 448: FIND MISSING ELEMENTS OF SEQUENCE */

// O(n) Time, O(1) Space Version
// works for integers, doubles, basically anything with negatives

#include <cmath>
#include <vector>

class Solution {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        // The sequence is from 1 to n, where n is the length of the input array
        // If only distinct numbers appear in the nums array, ideally we will get all of the sequence
        // If not, we get repeats, and we need to know which numbers repeat to know which ones don't.
        // The fastest and lightest algorithm will leave markers on the original input array.
        
        // we multiply negatives to elements that are in the sequence;
        // (this is possible because the sequence size is the array size)
        
        // for duplicate elements, we do not apply this marker twice (that would undo the marker).
        // any index that does not contain a negative is 'missing' from the sequence.
        
        unsigned short count = 0;
        unsigned short size = nums.size();
        
        for (int i = 0; i < size; ++i) {
            if (nums[std::abs(nums[i]) - 1] > 0) { // check duplicate
                nums[std::abs(nums[i]) - 1] *= -1; // take into consideration zero indices
                ++count;
            }
        }
        
        std::vector<int> missing;
        missing.reserve(size - count);
        for (int i = 0; i < size; ++i) {
            if (nums[i] > 0) {
                missing.push_back(i + 1); // missing numbers are the indices, not the elements
            }
        }
        
        return missing;
    }
};
