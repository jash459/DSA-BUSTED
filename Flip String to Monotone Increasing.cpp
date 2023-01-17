class Solution
{
public:
    int minFlipsMonoIncr(string S)
    {
        int countlfip = 0, countone = 0;
        for (auto i : S)
        { 
 //keep track of all one (we will use countone in else condition if we need)  
//if we want flip one into 0
            if (i == '1')
                countone++;
            else{
                countlfip++;
            countlfip = min(countlfip, countone);
            }
        }
        return countlfip;
    }
};