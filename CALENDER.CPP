/*
* Project Calendar: Help to see calendar of any year,
* using GUI programming to that provide Graphical user interface in
* command promt and Interupt programming to handle harware to make
* application user friendly.
*
*/
#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

/*
* Function: getkey()
* ------------------
* Help to handle keyboard of any computer or laptop
* Gives complete information about which key has been pressed and
* many more
*/
getkey()
{
    union REGS i, o;
    while (!kbhit())
        ;
    i.h.ah = 0;
    int86(22, &i, &o);
    return (o.h.ah);
}

int totalday(int, int);
int month(int, int);
int year(int);
/*
* Function: main()
* ----------------
* Initial Point of Project
*/
void main()
{
    int y, m, d, x, y1;
    /*To clear the console screen*/
    clrscr();
    printf("enter month");
    scanf("\n%d", &m);

    printf("\n enter year");
    scanf("%d\n", &y);

/*goto statement*/
himanshu:
    if (m >= 12) {
        m = 1;
    }
    printf(" dat: month  ");
    d = totalday(m, y);
    x = month(m, y);
    y1 = year(y);
    int him = 0;
    for (int i = 1; i <= d; i++) {
        him = (i % 7) + x + y1;
        him = him % 7;
        if (i % 2 != 0) {
            printf("\n");
        }
        printf(" %d : %d :  ", i, m);
        switch (him) {
        case 0: {
            printf("sun ");
            break;
        }
        case 1: {
            printf("mon ");
            break;
        }
        case 2: {
            printf("tues ");
            break;
        }
        case 3: {
            printf("wed ");
            break;
        }
        case 4: {
            printf("ther ");
            break;
        }
        case 5: {
            printf("fri ");
            break;
        }
        case 6: {
            printf("sat ");
            break;
        }
        }
    }
    int l = getkey();

    if (l == 72) {
        y++;
        clrscr();
        goto himanshu;
    }
    else if (l == 80) {
        y--;
        clrscr();
        goto himanshu;
    }
    else if (l == 77) {
        m++;
        clrscr();
        goto himanshu;
    }
    else if (l == 75) {
        m--;
        clrscr();
        goto himanshu;
    }
    else {
        printf("thankyou");
    }
    getch();
}
int month(int m, int y)
{
    int i, sum = 0;
    m -= 1;
    for (i = 1; i <= m; i++) {
        switch (i) {
        case 1: {
            sum = sum + 3;
            break;
        }
        case 2: {
            if ((y % 4) == 0) {
                sum = sum + 1;
                break;
            }
            else {
                break;
            }
        }
        case 3: {
            sum = sum + 3;
            break;
        }
        case 4: {
            sum = sum + 2;
            break;
        }
        case 5: {
            sum = sum + 3;
            break;
        }
        case 6: {
            sum = sum + 2;
            break;
        }
        case 7: {
            sum = sum + 3;
            break;
        }
        case 8: {
            sum = sum + 3;
            break;
        }
        case 9: {
            sum = sum + 2 break;
        }
        case 10: {
            sum = sum + 3;
            break;
        }
        case 11: {
            sum = sum + 2;
            break;
        }
        }

        sum = sum % 7;
        return (sum);
    }
    int year(int y)
    {
        int a, b, y1, y2, c, d, e, f;
        for (a = 1; (a * 400) < y; a++) {
            y1 = y - (a * 400);
        }
        for (b = 1; (b * 100) < y1; b++) {
            y2 = y1 - (b * 100);
        }
        b -= 1;
        c = b * 5;
        c = c % 7;

        y2 -= 1;
        d = y2 / 4;
        e = (y2 - d) % 7;
        d = (d * 2) % 7;
        f = (d + e) % 7;
        return (f + c);
    }
    int totalday(int m, int y)
    {
        int d;
        if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
            d = 31;
        else if (m == 4 || m == 6 || m == 9 || m == 11)
            d = 30;
        else if (m == 2 && (y % 4) == 0)
            d = 29;
        else
            d = 28;
        return (d);
    }
