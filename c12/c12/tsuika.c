#include <stdio.h>

/*
    時刻h時m分(ただし24時間制でmは整数)において、
    時計の長針と短針のなす角theta(0 <= theta <= 180)を計算する
*/

/*
    hは短針、mは長針
    hangleが長針の角度、mangleが短針の角度
    12時を0度とする
    thetaは0.5も扱うからdouble
    scanfでスペース開けても普通に動くが、格納先が一つだとスペースで区切られてしまう(問題7のように)
    今回は2つだから問題なし

    長針は1分で6度進むから*6する
    短針は1時間で30度進むから12でわってから*30する
    角度がマイナスになると計算が狂うから符号を反転させて+で計算する
    180度を超えた場合は360-thetaする
*/

int main()
{
    int h, m;
    double hangle, mangle, theta;

    printf("h m: ");
    scanf("%d %d", &h, &m);

    hangle = m * 6;
    mangle = (h % 12) * 30 + m * 0.5;

    theta = hangle - mangle;
    if (theta < 0)
    {
        theta = -theta;
    }
    if (theta > 180)
    {
        theta = 360 - theta;
    }

    printf("%.1f\n", theta);
    return 0;
}