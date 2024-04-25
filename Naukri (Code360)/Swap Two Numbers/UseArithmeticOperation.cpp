/*
* Using arithmetic operation
We can swap values of two variables by using a third variable and instead of that, we can use the arithmetic operation to do it without an extra variable.

The idea is to store the sum of two variables in the first variable. 
Now if we assign the sum(which is 1st variable) - 2nd variable in the 2nd variable then the value in the 2nd variable will be equal to the 1st variable.
Again assign the first variable equal to the sum(first variable) - 2nd variable(which has a value equal to 1st variable) so 1st variable will now have a value equal to 2nd variable.

Time Complexity
O(1), 
The Time Complexity is O(1).

Space Complexity
O(1), 
The Space Complexity is O(1).
*/

/*
    Time complexity: O(1)
    Space complexity: O(1).
*/

void swapNumber(int& a, int& b) {

    /*
        Store the sum of the 2 variables in 'a'.
        Assign difference of 'a' and 'b' to 'b' and difference of 'a' and 'b' to 'a'.
    */
    a = a + b;
    b = a - b;
    a = a - b;
}