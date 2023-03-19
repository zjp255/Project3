#define _CRT_SECURE_NO_DEPRECATE









//#include<stdio.h>
////将最大加数n1不大于m的划分的个数记作q(n,m)
//int q(int n, int m) {
//    if ((n < 1) || (m < 1))
//        return 0;
//    if ((n == 1) || (m == 1))
//        return 1;
//    if (n < m)
//        return q(n, n);
//    if (n == m)
//        return q(n, m - 1) + 1;
//    return q(n, m - 1) + q(n - m, m);
//}
//int main() {
//    int n, m;
//    printf("请输入加数n:");
//    scanf_s("%d", &n);
//    printf("请输入正整数m（不大于m的划分）:");
//    scanf_s("%d", &m);
//    int a = q(n, m);
//    printf("%d", a);
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include<math.h>
//char A[100];
//void swap(char *a,char *b)
//{
//    char c = *a;
//    *a = *b;
//    *b = c;
//}
//void PrintA(int n)
//{
//    for (int i = 1; i <= n; i++)
//        printf("%c ", A[i]);
//    printf("\n");
//}
//void perm(char A[], int k, int n)
//{
//    if (k == 1)
//        PrintA(n);
//    else
//    {
//        for (int i = n - k + 1; i <= n; i++)
//        {
//            swap(&A[i], &A[n - k + 1]);
//            perm(A, k - 1, n);
//            swap(&A[i], &A[n - k + 1]);
//        }
//    }
//}
//int main()//1 2 3
//{
//    int n;
//    scanf("%d", &n); 
//    for (int i = 1; i <= n; i++)
//        scanf("%s", &A[i]);
//    perm(A, n, n);
//    return 0;
//}





//#include <stdio.h>
//
//#define SIZE 6
//
////快速排序
//void quick_sort(int num[], int low, int high)
//{
//    int i, j, temp;
//    int tmp;
//
//    i = low;
//    j = high;
//    tmp = num[low];   //任命为中间分界线，左边比他小，右边比他大,通常第一个元素是基准数
//
//    if (i > j)  //如果下标i大于下标j，函数结束运行
//    {
//        return;
//    }
//
//    while (i != j)
//    {
//        while (num[j] >= tmp && j > i)
//        {
//            j--;
//        }
//
//        while (num[i] <= tmp && j > i)
//        {
//            i++;
//        }
//
//        if (j > i)
//        {
//            temp = num[j];
//            num[j] = num[i];
//            num[i] = temp;
//        }
//    }
//
//    num[low] = num[i];
//    num[i] = tmp;
//
//    quick_sort(num, low, i - 1);
//    quick_sort(num, i + 1, high);
//}
//
//int main()
//{
//    //创建一个数组
//    int num[SIZE] = { 0 };
//    int i;
//
//    //输入数字
//    for (i = 0; i < SIZE; i++)
//    {
//        scanf_s("%d", &num[i]);
//    }
//
//    quick_sort(num, 0, SIZE - 1);
//
//    for (i = 0; i < SIZE; i++)
//    {
//        printf(" %d ", num[i]);
//    }
//
//    return 0;
//}

//#include<stdio.h>
//int main()
//{
//    int arr[10] = { 0,2,3,4,5,6,7,8,9,10 };//已知的整形有序数组
//    int ar[10];
//
//    int n = 0;
//    int left = 0;//左下标
//    int right = sizeof(arr) / sizeof(arr[0]) - 1;//数组右下标  
//
//    while (left <= right)
//    {
//        int mid = left + (right - left) / 2;//找到最中间的数
//        if (mid == arr[mid]) {
//            ar[n] = mid;
//            n++;
//
//        }
//        if (mid < arr[mid])
//        {
//            right = mid - 1;
//        }
//        else if (mid > arr[mid])
//        {
//            left = mid + 1;
//        }
//        else
//        {
//            break;
//        }
//    }
//    if (n != 0) {
//        for (int i = 0; i < n; i++) {
//            printf("%d", ar[i]);
//        }
//    }
//    else {
//        printf("不存在");
//    }
//    return 0;
//}


//int main()
//{
//    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };//已知有序数组
//    int x = 0;//x是要寻找的数
//    int min = -1;
//    int mix = -1;
//    int n = 0;
//    int left = 0;//左下标
//    int right = sizeof(arr) / sizeof(arr[0]) - 1;//数组右下标  
//    scanf("%d", &x);
//    while (left <= right)
//    {
//        int mid = left + (right - left) / 2;//找到最中间的数
//        if (x < arr[mid])
//        {
//            right = mid - 1;
//        }
//        else if (x > arr[mid])
//        {
//            left = mid + 1;
//        }
//        else
//        {
//            mix = mid;
//            min = mid;
//            printf(" i = %d\n", min);
//            printf(" j = %d\n", mix);
//            n = 1;
//            break;
//        }
//    }
//    return 0;
//}




//int removeDuplicates(int* nums, int numsSize) {
//    if (numsSize == 0) {
//        return 0;
//    }
//    int fast = 1, slow = 1;
//    while (fast < numsSize) {
//        if (nums[fast] != nums[fast - 1]) {
//            nums[slow] = nums[fast];
//            ++slow;
//        }
//        ++fast;
//    }
//    
//    return slow;
//}
//int main()
//{
//	int n=0,nums[100];
//    printf("输入数组长度\n");
//    scanf("%d", &n);
//   
//    printf("输入数组\n");
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%d", &nums[i]);
//    }
//    int slow = removeDuplicates(&nums, n);
//    printf("%d\n", slow);
//    for (int i = 0; i < slow; i++)
//    {
//        printf("%d ", nums[i]);
//    }
//    scanf("%d", &n);
//	return 0;
//}




//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int x, y, z;
//	for (int i = 100; i < 1000; i++)
//	{
//		x = i % 10;
//		y = (i / 10) % 10;
//		z = i / 100;
//		if (pow(x,3) + pow(y,3) + pow(z,3) == i)
//		{
//			printf("%d\n", i);
//		}
//	}
//	getchar();
//	return 0;
//}