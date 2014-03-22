#include <stdio.h>

class Aliens
{
    int maxLeft, maxRight, maxPeople;
    int rightSoFar, leftSoFar, peopleSoFar;
    int input[100000], n, peopleAlienCanSee;
    public:

    Aliens()
    {
        maxLeft = maxRight = maxPeople = rightSoFar = leftSoFar = peopleSoFar = 0;
        scanf("%d %d", &n, &peopleAlienCanSee);
        int i;
        for(i = 0; i < n; i++)
            scanf("%d", &input[i]);

        for(i = 0; i < n; i++)
        {
            maxTillNow(i);
            maxSoFar();
        }
        printf("%d %d\n", peopleSoFar, rightSoFar - leftSoFar);
    }

    void maxTillNow(int index)
    {
        int i;
        for(i = maxLeft; i < index; i++)
        {
            if(maxPeople + input[index] <= peopleAlienCanSee)
                break;
            maxLeft++;
            maxPeople -= input[i];
        }
        if(maxPeople == 0)
            maxLeft = maxRight = index;

        if(maxPeople + input[index] <= peopleAlienCanSee)
        {
            maxRight++;
            maxPeople += input[index];
        }
        else
            maxLeft = maxRight = index + 1;
    }

    void maxSoFar()
    {
        int x, y;
        x = maxRight - maxLeft;
        y = rightSoFar - leftSoFar;
        if(x > y)
        {
            rightSoFar = maxRight;
            leftSoFar = maxLeft;
            peopleSoFar = maxPeople;
        }
        else if(x == y && maxPeople < peopleSoFar )
            peopleSoFar = maxPeople;
    }
};

int main()
{
    int test, i;
    scanf("%d", &test);
    for(i = 0; i < test; i++)
        Aliens ob;
    return 0;
}
