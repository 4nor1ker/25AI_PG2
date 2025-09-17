#include <stdio.h>
#include <Windows.h>

void moveCursor(int x, int y) {
    printf("\x1b[%d;%dH", y, x);
}

void printBomb(int isExploded) {
    if (isExploded) {
        printf("\x1b[A^^^^^^^");
        printf("\x1b[B\x1b[7D!!BAM!!");
        printf("\x1b[B\x1b[7D^^^^^^^");
    }
    else {
        printf("(  b  )");
    }
}

void rotate90(int* dx, int* dy) {
    int tx = *dy;
    int ty = -(*dx);
    *dx = tx;
    *dy = ty;
}

int main() {
    int startX = 14, startY = 9;
    int x = startX, y = startY;

    int dx = 0, dy = 1;
    int len = 2, stepCount = 0;

    int bombX = 0, bombY = 3;
    moveCursor(bombX, bombY);
    printBomb(0);

    // 1단계: 나선형 # 그리기
    while (len <= 12) {
        for (int i = 0; i < len; i++) {
            x += dx; y += dy;
            moveCursor(x, y);
            printf("#");
        }
        rotate90(&dx, &dy);
        if (++stepCount % 2 == 0) len += 2;
    }

    // 2단계: * 이동
    x = startX; y = startY;
    dx = 0; dy = 1;
    len = 2; stepCount = 0;

    int prevX = x, prevY = y;
    moveCursor(x, y); printf("*");
    Sleep(200);

    while (len <= 12) {
        for (int i = 0; i < len; i++) {
            prevX = x; prevY = y;        // 이전 좌표 저장
            x += dx; y += dy;            // 새 좌표 이동

            moveCursor(prevX, prevY);
            printf(" ");

            moveCursor(x, y);
            printf("*");

            Sleep(200);
        }
        rotate90(&dx, &dy);
        if (++stepCount % 2 == 0) len += 2;
    }

    moveCursor(x, y);
    printf(" ");

    moveCursor(bombX, bombY);
    printBomb(1);
    moveCursor(10, 20);
    return 0;
}