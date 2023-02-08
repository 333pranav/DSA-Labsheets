#include <stdio.h>

struct country_t
{
    char name[21];
    int gold, silver, bronze;
};
typedef struct country_t country;

void swap(country *i, country *j)
{
    country temp = *i;
    *i = *j;
    *j = temp;
}

void main()
{
    int n;
    scanf("%d", &n);
    country c[n];
    for (int i = 0; i < n; i++)
        scanf("%s %d %d %d", (c[i]).name, &(c[i].gold), &(c[i].silver), &(c[i].bronze));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (c[j].gold < c[j + 1].gold)
            {
                swap(&c[j], &c[j + 1]);
            }
            else if (c[j].gold == c[j + 1].gold)
            {
                if (c[j].silver < c[j + 1].silver)
                {
                    swap(&c[j], &c[j + 1]);
                }
                else if (c[j].silver == c[j + 1].silver)
                {
                    if (c[j].bronze < c[j + 1].bronze)
                    {
                        swap(&c[j], &c[j + 1]);
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++) printf("%s\n", c[i].name);
}