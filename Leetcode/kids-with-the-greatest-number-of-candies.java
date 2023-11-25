class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        int max = 0;
        for(int num: candies) {
            max = Math.max(num, max);
        }

        List<Boolean> res = new ArrayList<>();

        for(int num: candies) {
            if(num + extraCandies >= max) {
                res.add(true);
            } else {
                res.add(false);
            }
        }
        
        return res;
    }
}