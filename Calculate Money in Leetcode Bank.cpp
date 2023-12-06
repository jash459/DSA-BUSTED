class Solution {
public:
    int totalMoney(int n) {
        int k = n / 7;      // Calculate the number of complete weeks
        int F = 28;         // Initial earning for the first week
        int L = 28 + (k - 1) * 7;  // Earning for the last week
        int arithmeticSum = k * (F + L) / 2;  // Calculate the total earnings from complete weeks using arithmetic series formula
        
        int monday = 1 + k;  // Earnings on Monday for the final week
        int finalWeek = 0;
        
        // Calculate earnings for the final incomplete week
        for (int day = 0; day < n % 7; day++) {
            finalWeek += monday + day;  // Increment earnings for each day of the final incomplete week
        }
        
        return arithmeticSum + finalWeek;  // Return the total earnings for 'n' days
    }
};

