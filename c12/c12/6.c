#include <stdio.h>

/*
    数値nを入力し、そのn!を出力する
*/

/*
    factrialは階乗
    階乗は値の増え方がすごいからintだと13!くらいまでしか表示できない
    long longみたいに重ねると増やせるらしい
    if文でn <= 1で1を返すのは、1!と0!が1だから
    factorial(n - 1)の答えが出ない限りループが止まらないからループ条件とかは不要
*/

int factorial(int n)
{

    if (n <= 1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", factorial(n));

    return 0;
}