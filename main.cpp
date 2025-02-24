#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
 public:
  string getPermutation(int n, int k) {
    string ans;
    vector<int> nums(n);
    vector<int> factorial(n + 1, 1);  // factorial[i] := i!

    // Initialize nums with numbers from 1 to n
    std::iota(begin(nums), end(nums), 1);

    // Calculate factorials from 2 to n
    for (int i = 2; i <= n; ++i)
      factorial[i] = factorial[i - 1] * i;

    --k;  // 0-indexed

    // Generate the k-th permutation
    for (int i = n - 1; i >= 0; --i) {
      const int j = k / factorial[i];
      k %= factorial[i];
      ans += to_string(nums[j]);
      nums.erase(begin(nums) + j);
    }

    return ans;
  }
};

int main() {
  Solution solution;

  // Test cases
  cout << "Input: n = 3, k = 3" << endl;
  cout << "Output: \"" << solution.getPermutation(3, 3) << "\"" << endl;

  cout << "Input: n = 4, k = 9" << endl;
  cout << "Output: \"" << solution.getPermutation(4, 9) << "\"" << endl;

  cout << "Input: n = 3, k = 1" << endl;
  cout << "Output: \"" << solution.getPermutation(3, 1) << "\"" << endl;

  return 0;
}
