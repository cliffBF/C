#include <stdio.h>

/*
    フォルダにあるdata.txtを読み込み、学籍番号順にソートするプログラムを作る
    ただし構造体を用いる
    結果はファイルに出力する
*/

/*
    idは学籍番号、nameは名前、month dayが誕生日, ijはfor文用
    UTF8で日本語は一文字3byteあるからちょっと余裕持たせた方がいい
    struct listは1人分のデータをまとめたもの
    s[10]で十人分
    FILE *write,readはファイルを扱うために必要
    writeが書き込み用、readは読み込み用
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
    FILE *write;
    FILE *read;
    int i, j;

    /*
        配列には&を付けないからnameだけ先頭はs
        配列名を式の中で使ったとき、勝手に先頭の要素のアドレスに代わるから&はいらない
    */
    read = fopen("data.txt", "r");
    for (i = 0; i < 10; i++)
    {
        fscanf(read, "%d %s %d %d", &s[i].id, s[i].name, &s[i].month, &s[i].day);
    }
    fclose(read);

    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            if (s[j].id > s[j + 1].id)
            {
                struct list swap;
                swap = s[j];
                s[j] = s[j + 1];
                s[j + 1] = swap;
            }
        }
    }

    write = fopen("id.txt", "w");
    for (i = 0; i < 10; i++)
    {
        fprintf(write, "%d %s %d %d\n", s[i].id, s[i].name, s[i].month, s[i].day);
    }
    fclose(write);

    return 0;
}