#include<stdio.h>
int narcissistic_judge();
int main()
{
	int digit, max = 1, min = 1;
	printf("请输入水仙花数的位数n：");
	scanf("%d", &digit);
	for (int i = 1; i <= digit; i++)
	{
		max *= 10;
		min = max / 10;
	}
	for (int j = min; j < max; j++)
	{
		if (narcissistic_judge(j, digit) == 1)
			printf("%d ", j);
	}
	return 0;
}
int narcissistic_judge(int num, int digit)
{
	int nums, numss, sum = 0;
	int num_t = num;
	for (int j = 1; j <= digit; j++)
	{
		nums = num % 10;
		num /= 10;
		numss = 1;
		for (int i = 1; i <= digit; i++)
			numss *= nums;
		sum += numss;
	}
	if (num_t == sum)
		return 1;
	else
		return 0;
}