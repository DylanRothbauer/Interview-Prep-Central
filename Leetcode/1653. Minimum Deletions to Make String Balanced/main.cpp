class Solution {
public:
    int minimumDeletions(string s) {
        // vector<int> vec;

        // if (s.length() < 2) {
        //     return 0;
        // }

        // for (int i = 1; i < s.length(); i++) {
        //     int tmp = 0;
        //     int k = i - 1;
        //     int j = i + 1;

        //     while (k > 0) {
        //         if (s[k] != 'a') {
        //             tmp++;
        //             k--;
        //         }
        //     }

        //     while (j < s.length() - 1) {
        //         if (s[j] != 'b') {
        //             tmp++;
        //             j++;
        //         }
        //     }
        //     vec.push_back(tmp);

        // }
        // auto min = min_element(vec.begin(), vec.end());
        // return *min;

        /* Above code gets a Time Exceeding. This was my initial approach */

        /* Below is referenced ely242 submittion for assistance */

        // We iterate through each character in s. If the current character is a 'b', increment bCount. 
        // This means we've encountered a 'b' that may need to be deleted if there's an 'a' ahead of it.

        // On the other hand, if the current character is an 'a' and bCount is not equal to zero (meaning there's some 'b's before it), 
        // increment aCount (indicating a deletion needs to occur), and decrement bCount since we've removed a character to balance s.

        

        int aCount = 0;
        int bCount = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'b') {
                bCount++;
            }
            else if (bCount != 0) {
                aCount++;
                bCount--;
            }
        }
        return aCount;
    }
};