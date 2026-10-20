#include <stdio.h>

/*
    数値nを入力し、1からnまでの和を求める
*/

/*
    nが入力した値を入れる変数
    totalは合計
    iはtotalに加算するときに使う
*/

int n;
int total;
int i;

int main()
{
    printf("enter number: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        total = total + i;
    }

    printf("%d", total);

    return 0;
}