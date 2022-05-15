#include<stdio.h>
#include<math.h>

int main()
{
	float a, b, c;
	float x1, x2;
	printf("请输入三个参数(aX^2+bX+c=0)a,b,c分别为：");
	scanf("%f,%f,%f", &a, &b, &c);
	float delta = (b * b - 4 * a * c);
	printf("该方程为： %.0fX^2+%.0fX+%.0f=0\n", a, b, c);
	if (delta >= 0 && a != 0)
	{
		x1 = (-b + sqrt(delta)) / 2 * a;
		x2 = (-b - sqrt(delta)) / 2 * a;
		if (delta == 0)
			printf("该方程有一个解为x1=x2=%.0f", x1);
		else
			printf("该方程的解为X1=%.0f,x2=%.0f。", x1, x2);
	}
	else
		printf("该方程无实数解!\n");

	return 0;
}