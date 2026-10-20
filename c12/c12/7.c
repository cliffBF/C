#include <stdio.h>

/*
    名前をローマ字で入力し、名前に含まれる母音の数を出力する
    gayなら 1
    niggerなら 2
*/

/*
    char name;だと1文字しか入らないから19文字入力できるように20
    最後の1つは\0(文字列終わりの意味)が埋まる
    iはfor文に使う
    scanfだと名前の間の空白で区切るからfgets
    countに母音の個数を加算していく
    条件式の!=の部分は、\0が来るまで続けさせる意味
*/

int main()
{
    char name[20];
    int i;
    int count = 0;

    printf("name? :");
    fgets(name, 20, stdin);

    for (i = 0; name[i] != '\0'; i++)
    {
        if (name[i] == 'a' || name[i] == 'i' || name[i] == 'u' ||
            name[i] == 'e' || name[i] == 'o')
        {
            count = count + 1;
        }
    }
    printf("%d\n", count);
    return 0;
}