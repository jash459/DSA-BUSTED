class NumberContainers {
private:
    void fast(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
public:
    unordered_map<int, int> mp1;
    unordered_map<int, set<int>> mp2;
    NumberContainers() {
        fast();
    }
    void change(int index, int number) {
        if(mp1.count(index)){
            int oldi=mp1[index];
            mp2[oldi].erase(index);
            if(mp2[oldi].empty()){
                mp2.erase(oldi);
            }
        }
        mp1[index]=number;
        mp2[number].insert(index);
    }
    int find(int number) {
        if(mp2.count(number) and !mp2[number].empty()){
            return *mp2[number].begin();
        }
        return -1;
    }
};

