#include <stdio.h>
#include <math.h>

/*
    二次方程式の係数と定数項の値を入力してその解を求める
*/

/*
    ax^2 + bx + c = 0の解の公式

    +と-の2つあるからそれぞれ*x1, *x2にする
    returnだと1つしか返せないからポインタで書き込み先を受け取るようにする
    dは解の公式のrootの中の部分
    d>=0なら解は二つだが、d=0なら重解
    d<0ならx1は実数でx2は虚数
    解は x1 +- x2 iになる
*/
double kai(double a, double b, double c, double *x1, double *x2)
{
    double d = b * b - 4 * a * c;

    /*
        sqrtはマイナスの値を計算できず、nanと出力される
        d>=0なら解の公式をそのまま使えるが
        d<0だと rootd = rootd * iと書き直す、その後実部をx1へ、虚部をx2へ
        fabsは絶対値を返す
        b = 0のとき-bが-0.0になるが計算自体は合ってる
    */
    if (d >= 0)
    {
        *x1 = (-b + sqrt(d)) / (2 * a);
        *x2 = (-b - sqrt(d)) / (2 * a);
    }
    else
    {
        *x1 = -b / (2 * a);
        *x2 = sqrt(-d) / (2 * fabs(a));
    }
    return d;
}

/*
    abcが係数と定数項、x1,2に解を入れる
    scanfでlfなのはdouble型を表示するため
    printfだとfloatでもdoubleでもfでいいらしい
*/
int main()
{
    double a, b, c, x1, x2;

    printf("a b c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (a == 0)
    {
        printf("二次方程式ではない\n");

        return 0;
    }

    if (kai(a, b, c, &x1, &x2) >= 0)
    {
        printf("x = %f, %f\n", x1, x2);
    }
    else
    {
        printf("実部 = %f 虚部 = ±%f\n", x1, x2);
    }
    return 0;
}