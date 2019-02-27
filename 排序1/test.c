#include<stdio.h>
#include<assert.h>



void Insetsort(int * arr, size_t n) {
	assert(arr);
	for (size_t index = 0; index < n; ++index) {
		size_t tmp = arr[index];		//��¼ÿ����������ĵ�һ��Ԫ��
		int pos = index - 1;			
		while (pos >= 0 && arr[pos] > tmp) {
			arr[pos + 1] = arr[pos];
			pos--;
		}
		arr[pos + 1] = tmp;
	}
}


//��ʵ���ǰ���ߵ�����������ֻ��ʹ�ö��ֲ���������λ�ö���

void TwoInsetsort(int * arr, int n) {
	int left, right, num;
	int middle, j, i;
	for (i = 1; i < n; i++) {
		left = 0;	//׼��
		right = i - 1;
		num = arr[i];
		while (right >= left) {
			middle = (left + right) / 2;		//ָ��������õ��м�λ��
			if (num < arr[middle]) {
				//���������Ԫ��Ӧ����������
				right = middle - 1;
			}
			else {
				left = middle + 1;
			}
		}
		for (j = i - 1; j >= left; j--) {
			arr[j + 1] = arr[j];
		}
		arr[left] = num;		//����
	}
}

//ϣ��������ǰ�����Ϊ���飬
void ShellSort(int* arr, size_t n) {
	int gap = n / 3 + 1;
	for (size_t index = gap; index < n; index++) {
		size_t tmp = arr[index];
		int pos = index - gap;
		while (pos >= 0 && arr[pos] > tmp) {
			arr[pos + gap] = arr[pos];
			pos -= gap;
		}
		arr[pos + gap] = tmp;
	}
}

//ð������
void PopSort(int* arr, size_t n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[i + 1]) {
				int tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
			}
		}
	}
}

//ѡ������
void selectSort(int * arr, size_t n) {
	int min;
	int tmp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			min = i;
			if (arr[min] > arr[j]) {
				min = j;
			}

			tmp = arr[min];
			arr[min] = arr[j];
			arr[j] = tmp;
		}
	}
}

//ѡ������
void selectSort(int A[], int len) {
	int i, j, k;
	for (int i = 0; i < len; i++) {
		k = i;
		for (j = i + 1; j < len; j++) {
			if (A[j] < A[k]) {
				k = j;
			}
		}
		if (i != k) {
			A[i] = A[i] + A[k];
			A[k] = A[i] - A[k];
			A[i] = A[i] - A[k];
		}
	}
}




//��������
int GetMidNum(int* a, int begin, int end) {
	int mid = begin + (end - begin) / 2;
	
	if (a[begin] > a[mid]) {
		if (a[mid] > a[end]) {
			return mid;
		}
		else if (a[begin] > a[end]) {
			return end;
		}
		else {
			return begin;
		}
	}
	else {
		if (a[begin] > a[end]) {
			return begin;
		}
		else if (a[mid] < a[end]) {
			return end;
		}
		else {
			return mid;
		}
	}
}
int swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//1.����ָ�뷨
//	ʵ��˼·���ҳ�һ����Ŧ�������俪ʼ��Ԫ�أ������������Ԫ�أ�������߿�ʼ���б���
//	�ҵ�һ��������Ŧ��ֵͣ������Ȼ����ұ���С����Ŧ��ֵ��Ȼ��ͣ�������������ҵ�ֵ���н���
int PartSort1(int* a, int begin, int end) {
	int midNumIndex = GetMidNum(a, begin, end);
	if (end != midNumIndex) {
		swap(a[end], a[midNumIndex]);
	}
	int key = a[end];
	int left = begin;
	int right = end - 1;
	//����ұ�key���ֵ���ҵ���ͣ��
	//�ұ��ұ�keyС��ֵ���ҵ���ͣ��
	//���߽���
	while (left < right) {
		while (left < right && a[left] <= key) {
			++left;
		}
		while (left < right && a[right] >= key) {
			--right;
		}
		swap(a[left], a[right]);
	}
	//���leftһֱû���ҵ�����key��ֵ����ͣ����
	if (a[left] > a[end]) {
		swap(a[left], a[end]);
	}
	return left;
}
//2.�ڿӷ�������������ָ�뷨
int PartSort2(int* a, int begin, int end) {
	int midNumIndex = GetMidNum(a, begin, end);
	if (end != midNumIndex) {
		swap(a[end], a[midNumIndex]);
	}

	int key = a[end];
	int left = begin;
	int right = end;
	while (left < right) {
		while (left < right && a[left] <= key) {
			++left;
		}
		a[right] = a[left];//���ҵ���ֵ�Ԥ���Ŀ�
		while (left < right && a[right] >= key) {
			--right;
		}
		a[left] = a[right];
	}
	a[left] = key;
	return left;
}

//3.ǰ��ָ�뷨��
//	ʵ��˼·����ʼ��prevָ��begin��ǰһ��λ�ã�curָ��beginλ�ã���������
//	���ҵ�curָ���ֵС����Ŧֵ����prev���ƣ�Ȼ��prev��ָ���ֵ��cur��ָ��
//	��ֵ���н�����
int PartSort3(int* a, int begin, int end) {
	int midNumIndex = GetMidNum(a, begin, end);
	if (end != midNumIndex) {
		swap(a[end], a[midNumIndex]);
	}
	int key = a[end];
	int prev = begin - 1;
	int cur = begin;
	while (cur < end) {
		if (a[cur] < key && ++prev != cur) {
			swap(a[prev], a[cur]);
		}
		++cur;
	}
	swap(a[++prev], a[end]);
	return prev;
}

void QuickSort(int* a, int begin, int end) {
	if (begin < end) {
		int key = PartSort1(a, begin, end);
		QuickSort(a, begin, key - 1);
		QuickSort(a, key + 1, end);
	}
}


//�����ʺ���Щ�����ݣ����������ٵĻ���ջ�Ŀ����ǱȽϴ�ģ�����������ʱ��Ϊ��������
void QuickSortOP(int* a, int begin, int end) {
	if (end - begin > 13) {
		int key = PartSort3(a, begin, end);
		QuickSortOP(a, begin, key - 1);
		QuickSortOP(a, key + 1, end);
	}
	else {
		Insetsort(a + begin, end - begin + 1);
	}
}
int main()
{
	int arr[] = { 5,2,3,1,4 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	TwoInsetsort(arr, sz);
	return 0;
}