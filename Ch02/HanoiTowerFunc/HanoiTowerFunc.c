#include <stdio.h>

void HanoiTowerMove(int n, char from, char by, char to)
{
    if(n == 1){
        printf("move %dth disk from %c to %c \n", n, from, to);
    } else {
        HanoiTowerMove(n - 1, from, to, by);
        printf("move %dth disk from %c to %c \n", n, from, to);
        HanoiTowerMove(n - 1, by, from, to);
    }
}

int main(void)
{
    HanoiTowerMove(5, 'A', 'B', 'C');
    return 0;
}




