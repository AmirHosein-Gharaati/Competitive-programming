class Solution {
    public String reverseWords(String s) {
        String[] strings = s.split("\\s+");

        List<String> res = new ArrayList<>();
        for(int i = strings.length - 1; i >= 0; i--) {
            if(!strings[i].isBlank()) {
                res.add(strings[i]);
            }
        }

        return String.join(" ", res);
    }
}