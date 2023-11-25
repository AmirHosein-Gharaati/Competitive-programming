class Solution {
    public String mergeAlternately(String word1, String word2) {
        int len1 = word1.length();
        int len2 = word2.length();

        StringBuilder builder = new StringBuilder();

        int i1 = 0, i2 = 0;

        while(true) {

            if(i1 < len1) {
                builder.append(word1.charAt(i1));
                i1++;
            }

            if(i2 < len2) {
                builder.append(word2.charAt(i2));
                i2++;
            }

            if(i1 == len1 && i2 == len2)
                break;
        }

        return builder.toString();
    }
}