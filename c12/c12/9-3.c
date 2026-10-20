#include <stdio.h>

/*
    9-2で誕生日順にソートしたファイルを用いる
    誕生日を入力して氏名と学籍番号を2分探索法で検索するプログラム
*/

/*
    idは学籍番号、nameは名前、month dayが誕生日
    struct listは1人分のデータをまとめたもの、s[10]で10人分
    誕生日順で並んでないといけないから9-2で出したbirthday.txtを使う
    birthは誕生日を月*100+日したもの
    midbirthはs[mid]を月*100+日したもの
    low, highは左端と右端
    highの初期値が9なのはリストが10人だから
    midは基準値
    findは検索するものが見つかったら1にする
*/

int main()
{
    struct list
    {
        int id;
        char name[30];
        int month;
        int day;
    };

    struct list s[10];
    FILE *read;
    int i, low, high, mid, find, month, day, birth, midbirth;

    low = 0;
    high = 9;
    find = 0;

    read = fopen("birthday.txt", "r");
    for (i = 0; i < 10; i++)
    {
        fscanf(read, "%d %s %d %d", &s[i].id, s[i].name, &s[i].month, &s[i].day);
    }
    fclose(read);

    printf("month day: ");
    scanf("%d %d", &month, &day);
    birth = month * 100 + day;

    /*
        こっから二分探索
        基準値の誕生日問比べて同じならfindを1にするだけ
        基準値が小さければ low = mid + 1
        基準値が大きければ high = mid - 1
        low > highになったら終わり
    */

    while (low <= high)
    {
        mid = (low + high) / 2;
        midbirth = s[mid].month * 100 + s[mid].day;

        if (midbirth == birth)
        {
            printf("%s %d \n", s[mid].name, s[mid].id);
            find = 1;
            break;
        }
        else if (midbirth < birth)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (find == 0)
    {
        printf("not found\n");
    }

    return 0;
}