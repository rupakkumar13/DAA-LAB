#include <stdio.h>
#include <math.h>

void moveDisk(char from, char to, int disk) {
    printf("Move disk %d from %c to %c\n", disk, from, to);
}

void towerOfHanoiIterative(int n, char from, char to, char aux) {
    int totalMoves = pow(2, n) - 1;
    char A = from, B = aux, C = to;

    if (n % 2 == 0) {
        char temp = B;
        B = C;
        C = temp;
    }

    for (int i = 1; i <= totalMoves; i++) {
        int disk;
        if (i % 3 == 1) {
            disk = (i & -i) % (2 * n);
            moveDisk(A, C, disk);
        } 
        else if (i % 3 == 2) {
            disk = (i & -i) % (2 * n);
            moveDisk(A, B, disk);
        } 
        else if (i % 3 == 0) {
            disk = (i & -i) % (2 * n);
            moveDisk(B, C, disk);
        }
    }
}

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);

    towerOfHanoiIterative(n, 'A', 'C', 'B');

    return 0;
}
