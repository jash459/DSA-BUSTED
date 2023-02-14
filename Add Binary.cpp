class Solution {
public:
    string addBinary(string a, string b) {
        if(b.size() > a.size()) swap(a,b);    
        while(b.size() < a.size()) b = "0" + b;
        int carry = 0;
        string result = "";
        for(int i = b.size()-1; i >= 0 ; --i)
        {
             if(b[i] == '1' && a[i]=='1')
             {
                if(carry == 0) result = "0" + result;
                else result = "1" + result;      
                carry = 1;
             }
             else if(b[i] =='0' && a[i] =='0')
             {
                if(carry == 0) result = "0" + result;   
                else
                {
                    result = "1" + result;
                    carry = 0;
                }
             }
             else if((b[i]=='0' && a[i]=='1') || (b[i]=='1' && a[i] == '0'))
             {
                if(carry == 0) result = "1" + result;
                else result = "0" + result;   
             }        
    }    
        if(carry == 1) result = "1" + result;
        return result;
    }
};
