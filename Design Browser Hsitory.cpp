class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        pages_.emplace_back(homepage);
    }
    
    void visit(string url) {
        pages_.resize(curr+1);
        pages_.emplace_back(url);
       curr++;
    }
    
    string back(int steps) {
        if (steps <=curr)
        {
           curr -= steps;
        }
        else curr = 0;
        return pages_[curr];
    }
    
    string forward(int steps) {
       curr += steps;
        const int max_index = pages_.size() -1; 
        if (curr > max_index)curr = max_index;
        return pages_[curr];
    }
private:
    vector<string> pages_{};
    int curr{0};
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */