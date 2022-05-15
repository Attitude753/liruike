#include <stdio.h>
int perfect_number(int num);
int main()
{
    int max;
    scanf("%d", &max);
    for (int i = 6; i <= max; i++)
    {
        if (perfect_number(i))
        {
            printf("%d:", i);
            for (int j = 1; j < i; j++)
                if (i % j == 0)
                    printf("%d,", j);
            printf("\b \n");
        }
    }
    return 0;
}
int perfect_number(int num)
{
    int sum = 0;
    for (int i = 1; i < num; i++)
        if (num % i == 0)
            sum += i;
    if (num == sum)
        return 1;
    else
        return 0;
}