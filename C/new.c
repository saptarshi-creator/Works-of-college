#include <stdio.h>

int main() {
    int x;

    printf("Enter a number:");
    fflush(stdout);

    int result = scanf("%d",&x);

    printf("\nInput status: %d\n",result);

    printf("You entered: %d\n",x);

   // printf("Hello, World!\n");
    return 0;
}
//if first written zig cc new.c then have to write ./a.exe 
//if first written zig cc new.c -o new.exe then have to write ./new.exe