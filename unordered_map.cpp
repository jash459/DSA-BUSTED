#include <bits/stdc++.h>

using namespace std;

int main()
{
    unordered_map<string, int> mpp;
    mpp["Jash"] = 99;
    mpp["Hinger"] = 98;
    mpp["Motii"] = 92;
    mpp["Bachee"] = 94;

    for (auto i : mpp)
    {
        cout << i.first << " " << i.second << "\n";
    }

    for (auto it = mpp.begin(); it != mpp.end(); it++)
    {
        cout << it->first << " " << it.second << "\n";
    }

    string key = "Jash";
    if (mpp.find(key) != mpp.end())
    {
        cout << "key found";
    }
    else
    {
        cout << "Key not found";
    }

    if (mpp.find(key) != mpp.end())
    {
        auto temp = mpp.find(key);
        cout < "Key is: " << temp->first << "\n";
        cout << "Value is: " << temp->second << "\n";
    }

    key = "Hinger";
    mpp.erase(key);

    mpp.insert(make_pair("Arzoo", 1212));
    for (auto it = mpp.begin(); it != mpp.end(); it++)
    {
        cout << it->first << " " << it.second << "\n";
    }

    cout << mpp.size() << "\n";


    // frequency of each element in array
    int a[]={0,1,2,3,4,5,6,7,8,9,0,1,4,6,7,8};
    unordered_map<int , int> mp;
    for (int  i = 0; i < 16; i++)
    {
        /* code */
        int key=a[i];
        mp[key]++;
    }
    
    for( auto it = mp.begin() ;it!=mp.end() ; it++){
        cout<<it->first<< " "  << it->second<<"\n";
    }


    return 0;
}