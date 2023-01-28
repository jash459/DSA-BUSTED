class SummaryRanges {
public:
 
  SummaryRanges() {
        
  }
    
  void addNum(int val) {
    data_given.insert(val);
  }
    
  vector<vector<int>> getIntervals() {
      vector<vector<int>> result;
      int start = -1;
      int end = -1;
      for ( auto  &item: data_given) {
          if (start == -1) {
              start = item;
              end = item;
          } else if (item == end + 1) {
              end = item;
          } else {
              result.push_back({start, end});
              start = end = item;
          }
      }
      
      if (start != -1) result.push_back({start, end});
      
      return result;
  }
private:
  set<int> data_given;
};