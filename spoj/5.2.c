#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fp;
    fp = fopen("input.txt", "r");
    char buffer[10][10000] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}, ch;
    int i, j, k;
    int set = 0, len;
    while((ch = fgetc(fp))!=EOF)
    {
        if(ch==10)
        {
            set++;
            buffer[set%10][0] = '\0';
        }
        else
        {
            len = strlen(buffer[set%10]);
            buffer[set%10][len] = ch;
            buffer[set%10][len+1] = '\0';
        }
    }
    for(i = 0; i< 10; i++)
        printf("%d: %s\n", (i+set)%10, buffer[(i+set+1)%10]);

}
