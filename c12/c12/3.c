#include <stdio.h>

/*
    1からnまで足し算して初めて100を超えた時の値とその時のnを出す
*/

/*
    totalは合計、iはtotal加算用
    100超えたら終了でいいからwhile
    printの時i - 1してるのは、100超えて止まる前にwhileの最後、i + 1してるから
*/

int main()
{
    int total, i;
    total = 0;
    i = 1;
    while (total < 100)
    {
        total = total + i;
        i = i + 1;
    }

    printf("%d \n", total);
    printf("%d", i - 1);
    return 0;
}