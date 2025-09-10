#include <stdio.h>
#include <time.h>
#include <windows.h>

void gotoXY(int x, int y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main() {
    int x = 0;
    int y = 0;
    while (1) {

        gotoXY(x, y);
        printf("*");

        if (x == 0 && y == 1) {
            break;
        }
        else if (y == 0 && x <= 3) {
            x++;
        }
        else if (x == 4 && y <= 3) {
            y++;
        }
        else if (y == 4 && x <= 4 && x >= 1) {
            x--;
        }
        else if (x == 0 && y <= 4) {
            y--;
        }
    }
    gotoXY(6, 6);


}