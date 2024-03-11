class Solution {
public:
    string customSortString(string order, string s) {

        string sortedString;
        unordered_map<char, int> map;
        for(char ch : s)  
            map[ch]++;
        for(char ch : order){
            if(map.find(ch) != map.end()){
                int count = map[ch];
                while(count-- > 0)    
                    sortedString += ch;
                map.erase(ch);
            }
        }
        for(auto& entry : map){
            int count = entry.second;
            while(count-- > 0)    
                sortedString += entry.first;
        }
        return sortedString;
    }
};
