#include <stdio.h>

/*
    二つの数値を入力し大きい方を出力(等しい場合の処理も)
*/

/*
    num1,2が入力した数値を入れる変数
    scanfの時変数の前に&つけないと書き込み先が指定されずに挙動がおかしくなる
    if elseで大小比較してコンソールに表示する
*/

int num1, num2;

int main()
{
    printf("first number: ");
    scanf("%d", &num1);
    printf("second number: ");
    scanf("%d", &num2);

    if (num1 > num2)
    {
        printf("%d", num1);
    }
    else if (num1 < num2)
    {
        printf("%d", num2);
    }
    else
    {
        printf("等しい");
    }

    return 0;
}