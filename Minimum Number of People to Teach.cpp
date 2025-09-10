class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        vector<unordered_set<int>> user_lang(m);
        for (int i = 0; i < m; ++i) {
            for (int lang : languages[i]) {
                user_lang[i].insert(lang);
            }
        }
        vector<int> must_teach(m, 0);
        vector<int> lang_cnt(n + 1, 0);

        for (const auto& f : friendships) {
            int u = f[0] - 1;
            int v = f[1] - 1;
            bool can = false;
            for (int lang : user_lang[u]) {
                if (user_lang[v].count(lang)) {
                    can = true;
                    break;
                }
            }
            if (!can) {
                must_teach[u] = 1;
                must_teach[v] = 1;
            }
        }

        for (int i = 0; i < m; ++i) {
            if (must_teach[i]) {
                for (int lang : languages[i]) {
                    lang_cnt[lang]++;
                }
            }
        }

        int count_users = 0;
        for (int val : must_teach) {
            count_users += val;
        }
        int max_known = 0;
        for (int i = 1; i <= n; ++i) {
            max_known = max(max_known, lang_cnt[i]);
        }
        return count_users - max_known;
    }
};
