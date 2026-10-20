#include <stdio.h>
#include <stdlib.h>

/*
    ラインエディタを作る
    メモリの動的確保と双方向リストを使う

    ラインエディタの機能は下記の通り

    ・ファイル読み込み
    ・データ表示
    ・行入れ換え
    ・行削除
    ・行挿入
    ・ファイルへ上書き保存
*/

/*
    mallocとfreeを使うためにstdlibが必要
    1行ずつstruct listにする
    箱同士は双方向リストでつないで、backが前の行、goが後ろの行のアドレス

    headはダミー行、最後の行のgoをheadに戻してつなげる
    先頭、最後、空の時で処理を分けなくていい
    mallocは動的メモリを確保するのに必要
*/

struct list
{
    char *text;
    struct list *back;
    struct list *go;
};

/*
    文字列の長さを変える
    文字列の最後は\0だからそこが来るまでiを増やすと、\0の手前の文字数になる
    \0は数に入らないからmallocで確保するときは+1して\0の分も確保する
    add関数でtextの領域を文字数分のみ確保するために使う
*/
int length(char *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

/*
    文字列をコピーするのに必要
    toはコピー先でfromはコピー元
    配列はイコールで代入できないから文字ごとにコピーする
    文字列の最後は\0だからそこが来るまでループしてto[i]に\0をいれて最後尾にする
*/

void copy(char *to, char *from)
{
    int i;

    for (i = 0; from[i] != '\0'; i++)
    {
        to[i] = from[i];
    }
    to[i] = '\0';
}

/*
    新しい行をつなぐ
    beforeは追加する行の一つ前
    mallocで1行とってcopyでstrをtextにコピーする
    mallocが必要なのは、普通の変数だと関数が終わったときに消えるから
    add変数には新しい箱のアドレスが入ってる

    sizeofの中でstruct listだけ書いておけばいいのは1行分のサイズを入れるだけだから
    mallocは確保する容量を数字で受け取るが、箱の中身を変えた時いちいちこっちも変えなくていいように
    数字で指定せずに箱の大きさだけ確保すると命令すればいい
    a- -x- -b -の数分操作が必要
    データ構造とアルゴリズムの授業でやった連結リストみたいなもの
*/

void add(struct list *before, char *str)
{
    struct list *add;

    add = malloc(sizeof(struct list));
    add->text = malloc(length(str) + 1);
    copy(add->text, str);

    add->back = before;
    add->go = before->go;
    before->go->back = add;
    before->go = add;
}

/*
    number行目の箱のアドレスを探す
    箱のアドレスを返すから戻り値に*がついてる
    アドレスを返さないとコピーが渡されて実際に行はかわらない
    headから始めてgoまでをnumber回たどるとnumber行目で止まる
    headに中身はないから0行目として考えて良い
    行数+1すると一蹴した後headに戻ってくる
    存在しない行番号を入れたらプログラムを終了させる
    return 0だと今の関数を終わらせて呼び出し元に戻るだけ
    exit(1)はプログラム全体をその場で終わらせる
    return 0で実行するとmain関数が勝手に進んでおかしくなる
*/

struct list *search(struct list *head, int number)
{
    struct list *p;
    int i;

    if (number < 1)
    {
        printf("no line\n");
        exit(1);
    }

    p = head;
    for (i = 0; i < number; i++)
    {
        p = p->go;
        if (p == head)
        {
            printf("no line\n");
            exit(1);
        }
    }
    return p;
}

/*
    headは中身無しだが、全体をつなげるときに必要
    lineは今の行、line1,2は入れ替える行のアドレス
    swapはswapするときに使うだけ
    menuは選んだ操作の番号、number1,2は行の番号、ountは表示するときの行番号
    行を削除するときはfreeでメモリを解放させてる
*/

int main()
{
    struct list head;
    struct list *line, *line1, *line2;
    char str[256];
    char *swap;
    FILE *read;
    FILE *write;
    int menu, number1, number2, count;

    // headは0行目だからhead自身を指す
    head.back = &head;
    head.go = &head;

    read = fopen("data.txt", "r");
    while (fgets(str, 256, read) != NULL)
    {
        add(head.back, str);
    }
    fclose(read);

    while (1)
    {
        printf("\n1:show 2:swap 3:delete 4:add 5:save 0:end > ");
        scanf("%d", &menu);

        if (menu == 0)
        {
            break;
        }

        // 1週回ってheadに戻るまでの行をすべて表示させる
        else if (menu == 1)
        {
            count = 1;
            for (line = head.go; line != &head; line = line->go)
            {
                printf("%d: %s", count, line->text);
                count = count + 1;
            }
        }
        else if (menu == 2)
        {
            printf("line line: ");
            scanf("%d %d", &number1, &number2);
            line1 = search(&head, number1);
            line2 = search(&head, number2);
            swap = line1->text;
            line1->text = line2->text;
            line2->text = swap;
        }
        else if (menu == 3)
        {
            printf("line: ");
            scanf("%d", &number1);
            line = search(&head, number1);
            line->back->go = line->go;
            line->go->back = line->back;
            free(line->text);
            free(line);
        }
        else if (menu == 4)
        {
            printf("line: ");
            scanf("%d", &number1);
            getchar();
            printf("text: ");
            fgets(str, 256, stdin);
            line = search(&head, number1);
            add(line->back, str);
        }
        else if (menu == 5)
        {
            write = fopen("data.txt", "w");
            for (line = head.go; line != &head; line = line->go)
            {
                fprintf(write, "%s", line->text);
            }
            fclose(write);
        }
    }

    return 0;
}