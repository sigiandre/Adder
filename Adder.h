
#ifndef COMMON_ADDER_H
#define COMMON_ADDER_H
#include<string>

using namespace std;

class Adder {
public:
	int max(int a, int b) { return(a > b) ? a : b; }
	int max(int a, int b, int c) { return max(max(a, b), c); }

	int maxCrossingSum(int arr[], int l, int m, int h) {
		int sum = 0;

		int left_sum = std::numeric_limits<int>::min();
		for (int i = m; i >= l; i--) {
			sum = sum + arr[i];
			if (sum > left_sum)
				left_sum = sum;
		}
		sum = 0;
		int right_sum = std::numeric_limits<int>::min();
		for (int i = m + 1; i <= h; i++) {
			sum = sum + arr[i];
			if (sum > right_sum)
				right_sum = sum;
		}
		return left_sum + right_sum;
	}

	int maxSubArraySum(int arr[], int l, int h) {
		if (l == h)return arr[l];
		int m = (l + h) / 2;
		int maxleft = maxSubArraySum(arr, l, m);
		int maxRight = maxSubArraySum(arr, m + 1, h);
		return max(maxleft, maxRight, maxCrossingSum(arr, l, m, h));
	}
};

#endif
