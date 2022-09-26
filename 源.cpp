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
						aa+1 指第二行数组的首元素5地址
	printf("%d %d", *(ptr1 - 1), *(ptr2 - 1));	
						1			 6, ptr2-1 首元素地址-1到元素6
	return 0;
}
#include<string.h>
#include<assert.h>
				逆序字符串  =  旋转字符串
 1. 暴力求解法
void left_move1(char arr[], int k)
{
	assert(arr);
	int len = strlen(arr);
	int i = 0;

	for (i = 0; i < k; i++)
	{
		 1 . 保存首元素需要旋转的数字
		char tmp = *arr;
		 2.  开始第一次旋转
		int j = 0;
		for (j = 0; j < len - 1; j++)
		{
			*(arr + j) = *(arr + j + 1); // 将第j+1（2）个元素赋给第j（1）个元素，循环赋值，直到最后一个
		}
		*(arr + len-1) = tmp;
	}
}

 2. 三步翻转法
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
	reverse(arr,arr+k-1);// 1.逆序左边
	reverse(arr+k,arr+len-1);// 2.逆序右边
	reverse(arr,arr+len-1);// 3.逆序整体
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

  根据以上的内容，判断2个字符串的第二个是否可以由第一个旋转某字节数而来
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