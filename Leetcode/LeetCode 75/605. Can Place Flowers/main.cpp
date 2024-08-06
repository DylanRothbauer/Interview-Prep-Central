class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) {
            return true;
        }

        for (int i = 0; i < flowerbed.size(); i++) {
            // Can plant flower on a 0
            // Must check left and right of spot so its not adjacent
            // ... include boundary checking

            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)) {
                flowerbed[i] = 1;
                n--;
            }

            if (n == 0) { // all plants planted
                return true;
            }
        }
        return false;
    }
};