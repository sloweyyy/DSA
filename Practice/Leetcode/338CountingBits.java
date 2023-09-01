
import java.util.Vector;
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;
        for (int i = 0; i <= n; i++) {
            result.push_back(countBitsHelper(i));
        }
        return result;
    }
};