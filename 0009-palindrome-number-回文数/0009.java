class Solution {
    public boolean isPalindrome(int x) {
        if (x >= 0 && x <= 9) {
            return true;
        } else if (x < 0) {
            return false;
        } else if (x % 10 == 0) {
            return false;
        }
        int y = 0;
        while (x > y) {
            y = y * 10 + x % 10;
            if (x == y) {
                return true;
            }
            x /= 10;
            if (x == y) {
                return true;
            }
        }
        return false;
    }
}