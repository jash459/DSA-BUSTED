class Solution {
public:
    string clearStars(string s) {
        priority_queue<pair<char,int>,vector<pair<char,int>>,greater<pair<char,int>>> pq;
        for(int i=0;i<s.size();i++){
           if(s[i]!='*'){
            pq.push({s[i],s.size()-i-1});
           }
           else{
            if(!pq.empty()){
                pq.pop();
            }
           }
        }
         vector<char> v(s.size(),'0');
         while(!pq.empty()){
            char c=pq.top().first;
            int index=pq.top().second;
            index=s.size()-index-1;
            pq.pop();
            v[index]=c;
         }

         string ans;
         for(int i=0;i<v.size();i++){
            if(v[i]!='0'){
               ans+=v[i];
            }
         }
         return ans;
    }
};
