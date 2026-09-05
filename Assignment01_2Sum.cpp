#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;

// Brute-force approach: check pairs until the target is found
pair<int, int> twoSumBruteForce(const vector<int>& nums, int target) {

    for (int i = 0; i < nums.size(); i++) {

        for (int j = i + 1; j < nums.size(); j++) {

            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }

    return {-1, -1};
}


// Hash approach: store values that were already seen
pair<int, int> twoSumHash(const vector<int>& nums, int target) {

    unordered_map<int, int> index;

    for (int i = 0; i < nums.size(); i++) {

        int needed = target - nums[i];

        if (index.count(needed)) {
            return {index[needed], i};
        }

        index[nums[i]] = i;
    }

    return {-1, -1};
}


int main() {

    // Test 1: required test case
    vector<int> nums = {
        15, 4, 18, 8, 19, 22, 24, 59, 59, 20, 18, 12, 36, 42, 9
    };

    int target = 24;

    pair<int, int> bruteResult = twoSumBruteForce(nums, target);

    bool bruteValid =
        bruteResult.first >= 0 &&
        bruteResult.second >= 0 &&
        bruteResult.first != bruteResult.second &&
        nums[bruteResult.first] + nums[bruteResult.second] == target;

    cout << "\nTest 1 - Required Test\n";
    cout << "Target: " << target << "\n";
    cout << "Brute Force Indices: [" << bruteResult.first
         << ", " << bruteResult.second << "]\n";
    cout << "Values: " << nums[bruteResult.first] << " + "
         << nums[bruteResult.second] << "\n";
    cout << "Valid: " << (bruteValid ? "Yes" : "No") << "\n";

    pair<int, int> hashResult = twoSumHash(nums, target);

    bool hashValid =
        hashResult.first >= 0 &&
        hashResult.second >= 0 &&
        hashResult.first != hashResult.second &&
        nums[hashResult.first] + nums[hashResult.second] == target;

    cout << "Hash Indices: [" << hashResult.first
         << ", " << hashResult.second << "]\n";
    cout << "Values: " << nums[hashResult.first] << " + "
         << nums[hashResult.second] << "\n";
    cout << "Valid: " << (hashValid ? "Yes" : "No") << "\n";


    // Test 2: basic example
    nums = {2, 7, 11, 15};
    target = 9;

    bruteResult = twoSumBruteForce(nums, target);

    bruteValid =
        bruteResult.first >= 0 &&
        bruteResult.second >= 0 &&
        bruteResult.first != bruteResult.second &&
        nums[bruteResult.first] + nums[bruteResult.second] == target;

    hashResult = twoSumHash(nums, target);

    hashValid =
        hashResult.first >= 0 &&
        hashResult.second >= 0 &&
        hashResult.first != hashResult.second &&
        nums[hashResult.first] + nums[hashResult.second] == target;

    cout << "\nTest 2 - Basic Example\n";
    cout << "Target: " << target << "\n";
    cout << "Brute Force Indices: [" << bruteResult.first
         << ", " << bruteResult.second << "]\n";
    cout << "Values: " << nums[bruteResult.first] << " + "
         << nums[bruteResult.second] << "\n";
    cout << "Valid: " << (bruteValid ? "Yes" : "No") << "\n";
    cout << "Hash Indices: [" << hashResult.first
         << ", " << hashResult.second << "]\n";
    cout << "Values: " << nums[hashResult.first] << " + "
         << nums[hashResult.second] << "\n";
    cout << "Valid: " << (hashValid ? "Yes" : "No") << "\n";


    // Test 3: pair later in the vector
    nums = {3, 2, 4};
    target = 6;

    bruteResult = twoSumBruteForce(nums, target);

    bruteValid =
        bruteResult.first >= 0 &&
        bruteResult.second >= 0 &&
        bruteResult.first != bruteResult.second &&
        nums[bruteResult.first] + nums[bruteResult.second] == target;

    hashResult = twoSumHash(nums, target);

    hashValid =
        hashResult.first >= 0 &&
        hashResult.second >= 0 &&
        hashResult.first != hashResult.second &&
        nums[hashResult.first] + nums[hashResult.second] == target;

    cout << "\nTest 3 - Pair Later in Vector\n";
    cout << "Target: " << target << "\n";
    cout << "Brute Force Indices: [" << bruteResult.first
         << ", " << bruteResult.second << "]\n";
    cout << "Values: " << nums[bruteResult.first] << " + "
         << nums[bruteResult.second] << "\n";
    cout << "Valid: " << (bruteValid ? "Yes" : "No") << "\n";
    cout << "Hash Indices: [" << hashResult.first
         << ", " << hashResult.second << "]\n";
    cout << "Values: " << nums[hashResult.first] << " + "
         << nums[hashResult.second] << "\n";
    cout << "Valid: " << (hashValid ? "Yes" : "No") << "\n";


    // Test 4: duplicate values
    nums = {3, 3};
    target = 6;

    bruteResult = twoSumBruteForce(nums, target);

    bruteValid =
        bruteResult.first >= 0 &&
        bruteResult.second >= 0 &&
        bruteResult.first != bruteResult.second &&
        nums[bruteResult.first] + nums[bruteResult.second] == target;

    hashResult = twoSumHash(nums, target);

    hashValid =
        hashResult.first >= 0 &&
        hashResult.second >= 0 &&
        hashResult.first != hashResult.second &&
        nums[hashResult.first] + nums[hashResult.second] == target;

    cout << "\nTest 4 - Duplicate Values\n";
    cout << "Target: " << target << "\n";
    cout << "Brute Force Indices: [" << bruteResult.first
         << ", " << bruteResult.second << "]\n";
    cout << "Values: " << nums[bruteResult.first] << " + "
         << nums[bruteResult.second] << "\n";
    cout << "Valid: " << (bruteValid ? "Yes" : "No") << "\n";
    cout << "Hash Indices: [" << hashResult.first
         << ", " << hashResult.second << "]\n";
    cout << "Values: " << nums[hashResult.first] << " + "
         << nums[hashResult.second] << "\n";
    cout << "Valid: " << (hashValid ? "Yes" : "No") << "\n";


    // Test 5: negative number
    nums = {-5, 2, 9, 12};
    target = 7;

    bruteResult = twoSumBruteForce(nums, target);

    bruteValid =
        bruteResult.first >= 0 &&
        bruteResult.second >= 0 &&
        bruteResult.first != bruteResult.second &&
        nums[bruteResult.first] + nums[bruteResult.second] == target;

    hashResult = twoSumHash(nums, target);

    hashValid =
        hashResult.first >= 0 &&
        hashResult.second >= 0 &&
        hashResult.first != hashResult.second &&
        nums[hashResult.first] + nums[hashResult.second] == target;

    cout << "\nTest 5 - Negative Number\n";
    cout << "Target: " << target << "\n";
    cout << "Brute Force Indices: [" << bruteResult.first
         << ", " << bruteResult.second << "]\n";
    cout << "Values: " << nums[bruteResult.first] << " + "
         << nums[bruteResult.second] << "\n";
    cout << "Valid: " << (bruteValid ? "Yes" : "No") << "\n";
    cout << "Hash Indices: [" << hashResult.first
         << ", " << hashResult.second << "]\n";
    cout << "Values: " << nums[hashResult.first] << " + "
         << nums[hashResult.second] << "\n";
    cout << "Valid: " << (hashValid ? "Yes" : "No") << "\n";

    return 0;
}
