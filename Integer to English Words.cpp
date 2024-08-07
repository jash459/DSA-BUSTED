class Solution {
public:
    string hundred(map<int, string> word, int num) {
        string ans;
        vector<int> t;
        int num2 = num % 1000;
        int numb = num2;
        int i=0;
        if (num2 == 0)
            return "";
        while (i!=3) {
            t.push_back(num2 % 10);
            num2 /= 10;
            i++;
        }
        if (t[1] == 1 ) {
            ans = word[numb % 100];
        } else if (t[1] == 0) {
            ans = word[numb % 100];
        } else {
            ans = word[t[1] * 10] + word[numb % 10]; 
        }
        if ( t[2] > 0) {
            ans = word[t[2]] + "Hundred " + ans;
        }
        return ans;
    }
    string numberToWords(int num) {
        map<int, string> word;
        word[0] = "";
        word[1] = "One ";
        word[2] = "Two ";
        word[3] = "Three ";
        word[4] = "Four ";
        word[5] = "Five ";
        word[6] = "Six ";
        word[7] = "Seven ";
        word[8] = "Eight ";
        word[9] = "Nine ";
        word[10] = "Ten ";
        word[11] = "Eleven ";
        word[12] = "Twelve ";
        word[13] = "Thirteen ";
        word[14] = "Fourteen ";
        word[15] = "Fifteen ";
        word[16] = "Sixteen ";
        word[17] = "Seventeen ";
        word[18] = "Eighteen ";
        word[19] = "Nineteen ";
        word[20] = "Twenty ";
        word[30] = "Thirty ";
        word[40] = "Forty ";
        word[50] = "Fifty ";
        word[60] = "Sixty ";
        word[70] = "Seventy ";
        word[80] = "Eighty ";
        word[90] = "Ninety ";
        word[100] = "Hundred ";
        word[1000] = "Thousand ";
        word[1000000] = "Million ";
        word[1000000000] = "Billion ";

        // for first hundred
        string ans = hundred(word, num);
        int org = num;
        string temp;
        if(num==0) return "Zero";
        if(org >=1000){
            
            temp=hundred(word,num/1000);
            if(temp.length()!=0){
                ans="Thousand "+ ans;
                ans=temp+ans;
            }
            num=num/1000;
        }
        if(org>=1000000){
            temp=hundred(word,num/1000);
            if(temp.length()!=0){
                ans="Million " + ans;
                ans=temp+ans;
            }
            num=num/1000;
        }
        if(org>=1000000000){
            ans="Billion " + ans;
            temp=hundred(word,num/1000);
            if(temp.length()!=0){
                ans=temp+ans;
            }
        }

        return ans.substr(0,ans.length()-1);
    }
};
