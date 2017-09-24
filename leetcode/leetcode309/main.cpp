#include <iostream>
#include<vector>
using namespace std;
int maxProfit(vector<int>& prices) {
    int buy(INT32_MIN), sell(0), prev_sell(0), prev_buy;
    for (int price : prices) {
        prev_buy = buy;
       buy = max(prev_buy, prev_sell - price);
        prev_sell = sell;
        sell = max(prev_sell, prev_buy + price);
    }
    return sell;

}
int main() {
    vector<int> a = {1, 2, 3, 0, 2};
    maxProfit(a);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}