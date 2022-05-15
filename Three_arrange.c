#include <stdio.h>
int ex(int* j, int* k)
{
	int t;t = *j;*j = *k;*k = t;
}
int main()
{
	int a, b, c, q = 0;
	printf("请输入你想要比较的三个数（中间用逗号隔开）：");
	scanf("%d,%d,%d", &a, &b, &c);
	if (a > b)
		ex(&a, &b);
	if (a > c)
		ex(&a, &c);
	if (b > c)
		ex(&b, &c);
	printf("%d,%d,%d", a, b, c);
}