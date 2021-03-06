/* CASE 434: COUNT WORDS */
// O(n) Time, O(1) Space

#include <string>


class Solution {
public:
    int countSegments(std::string s) {
        int counts = 0;
        bool newword = false;
        std::string::iterator it = s.begin(); // use auto next time
        while (it != s.end()) {
            if (!newword && *it != ' ') {
                newword = true;
                ++counts;
            }
            else if (newword && *it == ' ') {
                newword = false;
            }
            ++it;
        }
        return counts;
        
    }
};
