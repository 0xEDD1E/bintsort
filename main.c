//
// Created by 0xEDD1E on 2016-03-30.
//

#include "bintsort.h"
void error(const char *);

int main(int argc, char *argv[])
{
    if (argc > 2)
        error("Too many arguments.\nUsage: bintsort [v]\n\tv: verbose sorting\n");

    int vrb = 0;
    if (argc == 2 && *(++argv)[0] == 'v')
        vrb = 1;

    int n;
    scanf("%d", &n);

    int a[n];
    int i;
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    bintsort(a, n, vrb);

    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

/*
    int tests = 1;
    int n = 0;
    while (tests < 100000) {
        n = rand() % 10 + 1;
        int a[n];
        int i;

        for (i = 0; i < n; i++)
            a[i] = rand() % 100 + 1;
        bintsort(a, n, 0);

        for(i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");

        tests++;
    }
*/

    return 0;
}

void error(const char *errstr)
{
    fprintf(stderr, "Error Occurred:\n\t*%s\n", errstr);
    exit(EXIT_FAILURE);
}