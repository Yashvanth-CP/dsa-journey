#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution{

    public :
     int maxProfit(vector<int> & prices){
        int minPrice = prices[0];  // Minimum price seen so far
        int maxProfit = 0;  
        
    
        for(int i = 1; i < prices.size(); i++){
           int profit = prices[i] - minPrice;
           maxProfit = max(maxProfit, profit);
           minPrice = min(minPrice, prices[i]);

     }
     return maxProfit;
    }
};

int main(){
    Solution sol;
// Test 1
    vector<int> prices1 = { 7, 1, 3, 5, 3, 6, 4};
    int profit1 = sol.maxProfit(prices1);
    cout << "Test 1: " << profit1 << endl;

    // Test 2
    vector<int> prices3 = {7, 1, 3, 5, 3, 6, 4};
    int profit3 = sol.maxProfit(prices3);
    cout << "Test 3: " << profit3 << endl;

 // Test 3
    vector<int> prices2 = {7, 6, 4, 3, 1};
    int profit2 = sol.maxProfit(prices2);
    cout << "Test 2: " << profit2 << endl;  

    return 0;
}
