class Solution {
public:
    int countSeniors(vector<string>& details) {
        // First 10 (0-9) is phone number of passenger
        // Next number (index 10) is gender of passenger
        // Next two are age of person (index 11-12) of passenger
        // Last two are seat number (index 13-14) of passenger

        // Return the number of passengers who are strictly more than 60 years old.
        int count = 0;

        for (int i = 0; i < details.size(); i++) {
            string x = "";
            x += details[i][11];
            x += details[i][12];
            int age = stoi(x);
            if (age > 60) {
                count++;
            }
        }
        return count;
    }
};