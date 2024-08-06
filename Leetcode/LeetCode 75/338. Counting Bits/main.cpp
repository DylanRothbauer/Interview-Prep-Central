class Solution {
public:
    vector<int> countBits(int n) {
        // Without using __builtin_popcount

        vector<int> result;

        for (int i = 0; i <= n; i++) {
            // Convert integer i to its binary string representation
            string bitRep = bitRepresentation(i);
            std::bitset<32> foo(bitRep); // Using bitset, assuming at most 32 bits needed
            result.push_back(foo.count()); // Count the number of 1s in the bitset
        }
        return result;
    }

private:
    string bitRepresentation(int num) {
        if (num == 0) {
            return "0";
        }

        if (num == 1) {
            return "1";
        }

        string result = "";
        while (num > 0) {
            result = char('0' + (num % 2)) + result;
            num /= 2;
        }
        return result;
    }
};