#include <stdio.h>
#include <math.h>

/*
    個人別に、各教科ごとと総合得点の偏差値を出力するプログラムを作る
    表に示すデータはあらかじめ配列に入れて初期化する
    標準偏差と偏差値の出し方は適当に調べればでるはず
    コメントで書くのだるい
*/

/*
    平方根を使うためにmathライブラリを入れる sqrt
    行は人、列は教科
    問題の表は10 5のmatrixだけど総合得点の計算をするために一列増やしてる
    6列目にはあとで５教科の合計点を入れる
    iは人、jは教科
    averageが平均、sdが標準偏差、subtotalが教科ごとの合計、sqtotalは標準偏差に必要
    標準偏差 = (得点-平均)の二乗の平均の平方根
    偏差値 = (得点-平均) / 標準偏差*10+50
*/

int main()
{
    int score[10][6] = {
        {55, 79, 83, 31, 98, 0},
        {99, 0, 48, 80, 100, 0},
        {78, 80, 75, 89, 30, 0},
        {4, 8, 9, 2, 100, 0},
        {22, 58, 34, 76, 65, 0},
        {56, 57, 76, 80, 90, 0},
        {30, 66, 92, 80, 53, 0},
        {0, 8, 39, 76, 89, 0},
        {38, 98, 25, 50, 90, 0},
        {85, 88, 69, 69, 69, 0}};

    double average[6], sd[6];
    int i, j;

    /*
      総合得点
      外側は行、内側は列
    */
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 5; j++)
        {
            score[i][5] = score[i][5] + score[i][j];
        }
    }

    /*
        標準偏差を出す
        列を一つずつ計算する
        総合得点も計算するから6列
        sqtotalは得点-平均の二乗を10人分足した合計

        標準偏差 = (score - average) * (score - average)
        sqrt(sq / 10)
    */
    for (j = 0; j < 6; j++)
    {
        double subtotal = 0, sqtotal = 0;
        for (i = 0; i < 10; i++)
        {
            subtotal = subtotal + score[i][j];
        }
        average[j] = subtotal / 10;
        for (i = 0; i < 10; i++)
        {
            sqtotal = sqtotal + (score[i][j] - average[j]) * (score[i][j] - average[j]);
        }
        sd[j] = sqrt(sqtotal / 10);
    }

    /*
        偏差値を出す
        %dだと文字コードがそのまま出るから%c
        %.1で小数点以下1桁まで表示させる
        fはdouble表示に必要
        偏差値 = (得点-平均) / 標準偏差*10+50
        偏差値 = (score - average) / sd * 10 + 50
    */
    for (i = 0; i < 10; i++)
    {
        printf("%c:", 'A' + i);
        for (j = 0; j < 6; j++)
        {
            printf(" %.1f", (score[i][j] - average[j]) / sd[j] * 10 + 50);
        }
        printf("\n");
    }

    return 0;
}