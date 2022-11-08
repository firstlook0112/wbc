#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int maxsum(int a[], int left, int right)
{
    int sum = 0, center, leftsum, rightsum, s1 = 0, lefts = 0, s2 = 0, rights = 0, i, j;
    if (left == right)//只有一个数据
    {
        if (a[left] > 0)sum = a[left];
        else sum = 0;
    }
    else
    {
        center = (left + right) / 2;
        leftsum = maxsum(a, left, center);
        rightsum = maxsum(a, center + 1, right);
        for (i = center; i >= left; i--)
        {
            lefts += a[i];
            if (lefts > s1)
            {
                s1 = lefts;
            }
        }
        for (j = center + 1; j <= right; j++)
        {
            rights += a[j];
            if (s2 < rights)
            {
                s2 = rights;
            }
        }
        sum += s1 + s2;
        if (sum < leftsum)sum = leftsum;
        if (sum < rightsum)sum = rightsum;
    }
    return sum;
}
int main()
{
    int n, left, right, i, j, a[50], max_sum;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    left = 0;
    right = n - 1;
    max_sum = maxsum(a, left, right);
    printf("%d", max_sum);
}