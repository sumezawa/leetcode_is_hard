/* CASE 2108: FIND FIRST PALINDROME IN AN ARRAY */

#include <string>
#include <utility>
#include <vector>

class Solution {
public:
    std::string firstPalindrome(std::vector<std::string>& words) {
        bool found_palindrome = false;
        for (std::vector<std::string>::iterator it = words.begin(); it != words.end(); ++it) {
            std::size_t n = it->size() / 2;
            // e.g.
            // aba 2 check up to a 0 (n < index 1)
            // aabbaa 5 check up to aab 2 (n < index 3)
            
            found_palindrome = true;
            for (std::size_t i = 0; i < n; ++i) {
                if ((*it)[i] != (*it)[it->size() - 1 - i]) {
                    found_palindrome = false;
                    break;
                }    
            }
            
            if (found_palindrome) {
                return *it;
            }
        }
        return "";
    }

    // less variables
    // less operations per loop
    std::string improved_firstPalindrome(std::vector<std::string>& words) {
        bool found_palindrome = false;
        std::size_t word_size;
        for (std::string& word : words) {
            word_size = word.size();
            // special case: one-letter word is always palindrome
            if (word_size == 1) {
                return word;
            }
            // e.g.
            // aba 2 check up to a 0 (n < index 1)
            // aabbaa 5 check up to aab 2 (n < index 3)
            
            for (std::size_t i = 0; i < word_size / 2; ++i) {
                if (word[i] == word[word_size - 1 - i]) {
                    if (i == word_size / 2 - 1) {
                        return word;    
                    }
                    
                }
                else {
                    break; // not palindrome
                }
            }
        }
        return "";
    }
};
