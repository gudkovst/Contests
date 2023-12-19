#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


int main(){
	int n, q;
	scanf("%d %d\n", &n, &q);
	std::vector<int> arr;
	for (int i = 0; i < n; i++){
		int a;
		scanf("%d ", &a);
		arr.push_back(a);
	}

	for (int w = 0; w < q; w++){
		const int max_length = 16;
        char cmd[max_length] {};
        std::cin.getline(cmd, max_length);
        char c = cmd[0];
        if (c == '+'){
            int l = atoi(&cmd[2]) - 1;
            int r = atoi(&cmd[4]) - 1;
            int x = atoi(&cmd[6]);
            for (int i = l; i <= r; i++)
            	arr[i] += x;
        }
        else if (c == '?'){
            int l = atoi(&cmd[2]) - 1;
            int r = atoi(&cmd[4]) - 1;
            int k = atoi(&cmd[6]);
            int b = atoi(&cmd[8]);
            int res = 0;
            for (int i = l; i <= r; i++){
            	int m = std::min(arr[i], k * (i + 1) + b);
            	res = m > res? m : res;
            }
            std::cout << res << std::endl;
        }
	}
	return 0;
}