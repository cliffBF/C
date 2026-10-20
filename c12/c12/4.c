#include <stdio.h>

/*
    数値をいくつか入力し、その和と平均を求める
    幾つでも値を入力できるようにする
*/

/*
    allは合計,averageは平均, numberは入力する値
    no dataの下にreturn 0がついてるのは、no dataになった時点でプログラムは終わりだから
    小数点に対応させるために計算時に(double)で変換する
*/

int main()
{
    int all, input, number;
    double average;
    all = 0;
    number = 0;

    while (1)
    {
        printf("number: ");
        scanf("%d", &input);
        if (input == -1)
        {
            break;
        }
        all = all + input;
        number = number + 1;
    }

    if (number == 0)
    {
        printf("no data\n");

        return 0;
    }

    average = (double)all / number;
    printf("%d\n", all);
    printf("%f\n", average);

    return 0;
}