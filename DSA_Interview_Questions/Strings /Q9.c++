// <aside>
// 💡 **Question 1**

// A permutation perm of n + 1 integers of all the integers in the range [0, n] can be represented as a string s of length n where:

// - s[i] == 'I' if perm[i] < perm[i + 1], and
// - s[i] == 'D' if perm[i] > perm[i + 1].

// Given a string s, reconstruct the permutation perm and return it. If there are multiple valid permutations perm, return **any of them**.

// **Example 1:**

// **Input:** s = "IDID"

// **Output:**

// [0,4,1,3,2]

// </aside>

#include <iostream>
#include <vector>
#include <string>

std::vector<int> reconstructPermutation(const std::string& s) {
    int n = s.length();
    std::vector<int> result(n + 1);
    int low = 0, high = n;

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'I') {
            result[i] = low++;
        } else {           // s[i] == 'D'
            result[i] = high--;
        }
    }

    // Place the last remaining number
    result[n] = low;

    return result;
}

int main() {
    std::string s = "IDID";
    std::vector<int> result = reconstructPermutation(s);

    std::cout << "[";
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i];
        if (i < result.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}
