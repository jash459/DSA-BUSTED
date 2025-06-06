class Solution {
public:
    string robotWithString(string s) {
        vector<int> freq(26, 0);
        int low = 0;
        string p, t;

        for (auto i : s) {
            freq[i - 'a']++;
        }

        for (auto i : s) {
            t += i;
            freq[i - 'a']--;

            while (low < 25 && freq[low] == 0) {
                low++;
            }

            while (!t.empty() && low >= t.back() - 'a') {
                p += t.back();
                t.pop_back();
            }
        }

        return p;
    }
};
