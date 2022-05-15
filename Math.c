#include<stdio.h>
#include<stdlib.h>

int add(num1, num2);
int sub(num1, num2);
int mul(num1, num2);
int divi(num1, num2);

int main()
{
	int a;
	int num1, num2, ans, mark = 0;
	char operation, ch;
	int level;
	srand((unsigned)time(NULL));

	do
	{
		printf("请选择你想进行的四则运算：");
		scanf("%c", &operation);
		getchar();
		printf("十位还是百位？\n");
		scanf("%d", &level);
		getchar();

		for (a = 0; a < 10; ++a)
		{
			num1 = rand() % level + 1;
			num2 = rand() % level + 1;
			switch (operation)
			{
			case'+':
				ans = add(num1, num2);
				break;
			case'-':
				ans = sub(num1, num2);
				break;
			case'*':
				ans = mul(num1, num2);
				break;
			case'/': {
				while (1) {
					num1 = rand() % level + 1;
					num2 = rand() % level + 1;
					if (num1 % num2 == 0)
						break;
				}
				ans = divi(num1, num2);
				break;
			}
				   /*
					case'/': //另一个除法版本
					   num2 = rand() % (level / (num1 + 1));
					   num2 = (num2 == 0 ? 1 : num2);
					   ans = num1;
					   num1 *= num2;
					   break;
				   */
			default:
				return 0;
				break;
			}
			int player_ans;
			printf("%d %c %d=", num1, operation, num2);
			scanf("%d", &player_ans);
			printf(ans == player_ans ? "right!\n" : "wrong!\n");
			if (ans == player_ans)
				mark = mark++;
		}
		printf("满分十分，你的分数是%d\n", mark);
		printf("请问您想继续吗？（y/n）:");
		scanf(" %c", &ch);
		getchar();
	} while ('y' == ch || 'Y' == ch);
	return 0;
}
int add(num1, num2)
{
	int ans;
	ans = num1 + num2;
}
int sub(num1, num2)
{
	int ans;
	ans = num1 - num2;
}
int mul(num1, num2)
{
	int ans;
	ans = num1 * num2;
}
int divi(num1, num2)
{
	int ans;
	ans = num1 / num2;
}