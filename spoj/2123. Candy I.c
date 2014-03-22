#include <stdio.h>

int main()
{
    int n, numOfCandy[10000];
    int i, j, total, moveTotal;
    while(1)
    {
        scanf("%d", &n);
        if(n == -1)
            break;
        moveTotal = total = 0;
        for(i = 0; i < n; i++)
        {
            scanf("%d", &numOfCandy[i]);
            total += numOfCandy[i];
        }
        if(total % n != 0)
            printf("-1\n");
        else
        {
            for(i = 0; i < n; i++)
                if(numOfCandy[i] > total / n)
                    moveTotal += numOfCandy[i] - (total / n);
            printf("%d\n", moveTotal);
        }
    }
    return 0;
}
