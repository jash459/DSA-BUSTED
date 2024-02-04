class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();

        // store frequency of each character in t
        unordered_map<char, int> freq;
        for(int i=0; i<n; i++){
            freq[t[i]]++;
        }

        // store indices of characters in s
        // that are also present in t 
        unordered_map<char, deque<int>> pos;

        // store the indices in sorted order
        set<int> st;

        // store the begin and end of smallest window 
        pair<int, int> result_ind = {0, INT_MAX}, initial;

        // store the initial value of result_ind 
        // useful in case no such window exist
        initial = result_ind;

        // iterate through s
        for(int i=0; i<m; i++){
            // if present in t
            if(freq[s[i]] > 0){

                // add index to position array of s[i] character
                pos[s[i]].push_back(i);

                // add the index to set too
                st.insert(i);

                // if s[i].size() > number of times it occurs in t
                // then we don't need the first occurence anymore
                if(pos[s[i]].size() > freq[s[i]]){
                    int first = pos[s[i]].front();
                    pos[s[i]].pop_front();
                    st.erase(first);
                }

                // if set contains all elements of t
                if(st.size() == n){
                    //check if current substring is the least length
                    if(i - *st.begin() < result_ind.second - result_ind.first){
                        result_ind = {*st.begin(), i};
                    }
                }
            }
        }

        // if no such window is found
        if(result_ind == initial) return "";

        // result will be the substring starting from 
        // first result of length second - first + 1
        string result = s.substr(result_ind.first, result_ind.second - result_ind.first + 1);
        return result;
    }
};
