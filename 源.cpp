#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int a[5] = { 5,4,3,2,1 };
	int* ptr = (int*)(&a + 1);
	printf("%d %d", *(a + 1), *(ptr - 1));
					 4        1
	return 0;
}

int main()
{
	int aa[2][5] = { 10,9,8,7,6,5,4,3,2,1 };
	int* ptr1 = (int*)(&aa + 1);
	int* ptr2 = (int*)(*(aa + 1));
						aa+1 ָ�ڶ����������Ԫ��5��ַ
	printf("%d %d", *(ptr1 - 1), *(ptr2 - 1));	
						1			 6, ptr2-1 ��Ԫ�ص�ַ-1��Ԫ��6
	return 0;
}
#include<string.h>
#include<assert.h>
				�����ַ���  =  ��ת�ַ���
 1. ������ⷨ
void left_move1(char arr[], int k)
{
	assert(arr);
	int len = strlen(arr);
	int i = 0;

	for (i = 0; i < k; i++)
	{
		 1 . ������Ԫ����Ҫ��ת������
		char tmp = *arr;
		 2.  ��ʼ��һ����ת
		int j = 0;
		for (j = 0; j < len - 1; j++)
		{
			*(arr + j) = *(arr + j + 1); // ����j+1��2����Ԫ�ظ�����j��1����Ԫ�أ�ѭ����ֵ��ֱ�����һ��
		}
		*(arr + len-1) = tmp;
	}
}

 2. ������ת��
void reverse(char* left, char* right)
{
	assert(left);
	assert(right);
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}

}
void left_move2(char arr[], int k)
{ //  +0+1+2+3+4+5
	 a b c d e f
	assert(arr);
	int len = strlen(arr);
	assert(k <= len);
	reverse(arr,arr+k-1);// 1.�������
	reverse(arr+k,arr+len-1);// 2.�����ұ�
	reverse(arr,arr+len-1);// 3.��������
}


int main()
{
	char arr[] = "abcdef";
	int n = 0;
	scanf("%d", &n);
	left_move2(arr, n);
	printf("%s\n", arr);
	return 0;
}

  �������ϵ����ݣ��ж�2���ַ����ĵڶ����Ƿ�����ɵ�һ����תĳ�ֽ�������
int is_lefe_move(char* arr1, char* arr2)
{
	int sum = 0;
	int len = strlen(arr1);
	int i = 0;
	for (i = 0; i < len; i++)
	{
		left_move2(arr1, 1);
		sum++;
		if (strcmp(arr1, arr2) == 0)
			return 1;
	}
	return 0;
	printf("%d ", sum);
}
int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "defabc";
	int ret = is_lefe_move(arr1, arr2);
	if (ret == 1)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}