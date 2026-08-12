class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int>> ans;

        for (int a = 1; a <= 9; a++) {
            for (int b = a + 1; b <= 9; b++) {
                for (int c = b + 1; c <= 9; c++) {
                    for (int d = c + 1; d <= 9; d++) {
                        for (int e = d + 1; e <= 9; e++) {
                            for (int f = e + 1; f <= 9; f++) {
                                for (int g = f + 1; g <= 9; g++) {
                                    for (int h = g + 1; h <= 9; h++) {
                                        for (int i = h + 1; i <= 9; i++) {

                                            vector<int> temp = {
                                                a,b,c,d,e,f,g,h,i
                                            };

                                            for (int j = 0; j < (1 << 9); j++) {

                                                vector<int> current;
                                                int sum = 0;

                                                for (int x = 0; x < 9; x++) {
                                                    if (j & (1 << x)) {
                                                        current.push_back(temp[x]);
                                                        sum += temp[x];
                                                    }
                                                }

                                                if (current.size() == k &&
                                                    sum == n) {
                                                    ans.push_back(current);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }
};