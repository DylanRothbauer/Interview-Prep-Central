bool isPalindrome(string& s)
{
	// Write your code here.
	int left = 0;
	int right = s.length() - 1;

	while (left <= right) {
		if (s[left] != s[right]) {
			return false;
		}
		left++;
		right--;
	}

	return true;
}