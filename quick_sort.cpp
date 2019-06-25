#include <iostream>

#define AR_SIZE(arrays) sizeof(arrays)/sizeof(arrays[0])

using namespace std;

int main()
{
	void print(int* arrays, int length);
	void quick_sort(int* arrays, int left, int right);

	int a[] = { 7,1,518,55,8748,4,6456,1,62,10,11,15,-7 };
	print(a, AR_SIZE(a));
	quick_sort(a, 0, AR_SIZE(a) - 1);
	print(a, AR_SIZE(a));
	system("pause");
}

void print(int* arrays, int length) {
	cout << "--------------------" << endl;
	for (int i = 0; i < length; i++) {
		cout << arrays[i] << " ";
	}
	cout << endl;
	cout << "--------------------" << endl;
}

// def 快排
// arg0 数组 arg1 排序起点 arg2 排序终点
void quick_sort(int* arrays, int start, int end) {
	if (nullptr == arrays) {
		cout << "quick_sort : arrays is null" << endl;
		return;
	}
	if (start >= end) {
		return;
	}
	int left = start;
	int right = end;
	bool direct = true;
	while (left != right)
	{
		if (arrays[left] <= arrays[right]) {
			direct ? left += 1 : right -= 1;
		}
		else {
			direct = !direct;
			int temp = arrays[left];
			arrays[left] = arrays[right];
			arrays[right] = temp;
		}
	}
	quick_sort(arrays, start, left - 1);
	quick_sort(arrays, right + 1, end);
}