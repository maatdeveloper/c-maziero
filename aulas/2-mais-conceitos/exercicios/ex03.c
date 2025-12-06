#include <stdio.h>
#include <string.h>
// ex 3 -  i/o padrao

int main() {
    char nan = getchar();
    
    for (int i=0; i < sizeof nan; i++) {
        switch (nan)
        {
            case 32:
                putchar(' ');
                break;
            case 97:
                putchar('A');
                break;
            case 98:
                putchar('B');
                break;
            case 99:
                putchar('C');
                break;
            case 100:
                putchar('D');
                break;
            case 101:
                putchar('E');
                break;
            case 102:
                putchar('F');
                break;
            case 103:
                putchar('G');
                break;
            case 104:
                putchar('H');
                break;
            case 105:
                putchar('I');
                break;
            case 106:
                putchar('J');
                break;
            case 107:
                putchar('K');
                break;
            case 108:
                putchar('L');
                break;
            case 109:
                putchar('M');
                break;
            case 110:
                putchar('N');
                break;
            case 111:
                putchar('O');
                break;
            case 112:
                putchar('P');
                break;
            case 113:
                putchar('Q');
                break;
            case 114:
                putchar('R');
                break;
            case 115:
                putchar('S');
                break;
            case 116:
                putchar('T');
                break;
            case 117:
                putchar('U');
                break;
            case 118:
                putchar('V');
                break;
            case 119:
                putchar('W');
                break;
            case 120:
                putchar('X');
                break;
            case 121:
                putchar('Y');
                break;
            case 122:
                putchar('Z');
                break;
            default:
                break;
        }
    }
    puts("\n");

    return 0;
}