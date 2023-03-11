class Solution {
    public boolean isPalindrome(int x) {
        String num = Integer.toString(x);

        int left, right;

        if(num.length() % 2 == 0) {
            left = num.length() / 2 - 1;
        } else {
            left = num.length() / 2;
        }
        right = num.length() / 2;

        boolean flag = true;

        while(left >= 0 && right < num.length()) {
            if(num.charAt(left) != num.charAt(right)) {
                flag = false;
                break;
            }
            left--;
            right++;
        }

        return flag;
    }
}