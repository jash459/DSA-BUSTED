class Router {
public:
    queue <vector<int>> q;
    unordered_set <string> duplicates;
    unordered_map<int,vector<int>> ump;
    int limit;
    Router(int memoryLimit) {
        limit=memoryLimit;
        
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        vector <int> v={source,destination,timestamp};
        string check=to_string(source)+"s"+to_string(destination) +"d"+to_string(timestamp)+"t";
        if(duplicates.contains(check)){
            return false;
        }
        if(q.size()==limit){
            vector <int> temp=q.front();
            q.pop();
            string to_delete=to_string(temp[0])+"s"+to_string(temp[1])+"d"+to_string(temp[2])+"t";
            duplicates.erase(to_delete);
            int d=temp[1];
            int t=temp[2];
            auto it=find(ump[d].begin(),ump[d].end(),t);
            ump[d].erase(it);
            
        }
        duplicates.insert(check);
        q.push(v);
        ump[destination].push_back(timestamp);
        return true;
        
    }
    
    vector<int> forwardPacket() {
        if(q.size()==0){
            return {};
        }
        vector <int> v= q.front();
        q.pop();
        string to_delete=to_string(v[0])+"s"+to_string(v[1])+"d"+to_string(v[2])+"t";
        duplicates.erase(to_delete);
        auto it=find(ump[v[1]].begin(),ump[v[1]].end(),v[2]);
        ump[v[1]].erase(it);
        return v;
        
        
    }
    
    int getCount(int destination, int startTime, int endTime) {
        int answer=0;
        for(auto it:ump[destination]){
            if(it>=startTime&&it<=endTime){
                answer++;
            }
        }
        return answer;
        
    }
};

