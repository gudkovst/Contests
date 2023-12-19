#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define canBuy(i) prices[i] < min_skip && cost + prices[i] <= m
#define abs(a) a < 0? -a : a

int n, m;
std::vector<int> prices;
std::set<unsigned long long> costs;

void compute(int ind, unsigned long long cost, int min_skip){
	if (ind == n - 1){
		if (canBuy(ind))
			costs.insert(cost + prices[ind]);
		costs.insert(cost);
		return;
	}
	int new_min_skip = std::min(prices[ind], min_skip);
	compute(ind + 1, cost, new_min_skip);
	if (canBuy(ind))
		compute(ind + 1, cost + prices[ind], min_skip);
	return;
}


int main(){
    scanf("%d %d\n", &n, &m);
    for (int i = 0; i < n; i++){
    	int a;
    	scanf("%d ", &a);
    	prices.push_back(a);
    }
    compute(0, 0, m + 1);
    std::vector<unsigned long long> vc(costs.begin(), costs.end());
    vc.push_back(m + 1);
    int size = vc.size();
    unsigned long long res = 0;
    for (int i = 0; i < size - 1; i++){
    	unsigned long long sub = vc[i + 1] - vc[i];
    	res = (sub > res)? sub : res;
    }
    std::cout << res - 1;
    return 0;
}