#include <bits/stdc++.h> 
bool checkMeta(string& str1, string& str2)
{
    // Write your code here.
    if (str1.length() != str2.length() || str1 == str2) {
        return false; // If lengths are different or strings are equal, they cannot be meta strings
    }
    // for (int i = 0; i < str1.length(); i++) {
    //     int k = i;
    //     if (str1[i] != str2[k]) {
    //         for (int j = k + 1; k < str2.length(); j++) {
    //             if (str2[j] == str1[i]) {
    //                 // swap
    //                 swap(str2[k], str2[j]);
    //                 break;
    //             }
    //         }

    //     }
    // }

    int differenceCounter = 0;
    int missMatch1;
    int missMatch2;

    for (int i = 0; i < str1.length(); i++) {
        if (str1[i] != str2[i]) {
            differenceCounter++;
            if (differenceCounter == 1) {
                missMatch1 = i;
            }
            else if (differenceCounter == 2) {
                missMatch2 = i;
            }
            else {
                return false; // More than two mistakes
            }
        }
    }

    return differenceCounter == 2 && str1[missMatch1] == str2[missMatch2] &&
        str1[missMatch2] == str2[missMatch1];
}
