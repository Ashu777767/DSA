

class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        List<Integer> ans = new ArrayList<>();

        for (int num : asteroids) {
            boolean alive = true;

            while (!ans.isEmpty() && ans.get(ans.size() - 1) > 0 && num < 0) {
                int last = ans.get(ans.size() - 1);

                if (Math.abs(last) < Math.abs(num)) {
                    ans.remove(ans.size() - 1);
                } 
                else if (Math.abs(last) == Math.abs(num)) {
                    ans.remove(ans.size() - 1);
                    alive = false;
                    break;
                } 
                else {
                    alive = false;
                    break;
                }
            }

            if (alive) {
                ans.add(num);
            }
        }

        // Convert List → Array
        int[] result = new int[ans.size()];
        for (int i = 0; i < ans.size(); i++) {
            result[i] = ans.get(i);
        }

        return result;
    }
}