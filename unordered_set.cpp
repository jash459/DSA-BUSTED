#include<bits/stdc++.h>

using namespace std;

int main(){
    unordered_set<int> s;

    // function : 

    // insert()
    // clear()
    // find()
    // begin()
    // end()
    // size()
    // count()
    // erase()
    
    // insert
    s.insert(10);
    s.insert(5);
    s.insert(20);
    s.insert(15);
    
    //iterate
    for(auto it : s.begin() ; it!=s.end() ; it++){
        cout<<(*it)<<"\n";
    }

    cout<<"count no. of element : "<< s.size()<< "\n";

    s.clear();
    cout<<"count no. of element : "<<s.size()<<"\n";

    int key=20;
    if(s.begin(key)==s.end()){
        cout<<"Key not found";
    }
    else{
        cout<<"Key not found";
    }

   //  find() return the iterator to that position.
    auto temp=s.find(key);
    s.erase(temp);
    
    if(s.find(key) != s.end() ){
        cout<<"Key found"<<"\n";
    }
    else{
        cout<<"Key not found"<<"\n";
    }
     
    // count function return 1 if element found and 0 if not found.
    if(s.count(5)){
        cout<<"key found" << "\n"; 
    }
    else{
        cout<<"key not found" << "\n";
    }
    return 0;
}