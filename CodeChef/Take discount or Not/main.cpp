#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t > 0) {
        int n, x, y;
        cin >> n >> x >> y;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        // your code goes here

        // N - # of items
        // X - cost of coupon
        // Y - # to reduce each item by
        //   if item is <= Y, it becomes 0

        // My steps/thought process
        // 1) Cost of no coupon
        // 2) Cost of coupon + cost of items with discount
        // 3) If cost of coupon + cost of items with discount is
        //    strickly less than cost of no coupon, then print
        //    "COUPON", otherwise print "NO COUPON"

        int noCouponCost = 0;
        int couponCost = x;

        for (int i = 0; i < n; i++) {
            noCouponCost += a[i];
            if (a[i] > y) {
                a[i] -= y;
                couponCost += a[i];
            }
        }

        if (couponCost < noCouponCost) {
            cout << "COUPON" << endl;
        }
        else {
            cout << "NO COUPON" << endl;
        }

        t--;
    }
    return 0;
}
