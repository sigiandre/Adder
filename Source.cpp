#include<iostream>
#include "adder.h"

using namespace std;

int main() {
	
	int arr[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
	int n = sizeof(arr) / sizeof(arr[0]);

	Adder* a = new Adder();
	int max_sum = a->maxSubArraySum(arr,0,n-1);
	cout << "Maximiun Contiguous sum is=>" << max_sum;
	cout << endl;

	system("pause");
	return 0;
}
