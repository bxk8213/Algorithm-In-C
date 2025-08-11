#include <stdio.h>

void duplicateStringBitwise(char *str)
{
    int H = 0;
    int x;

    for(int i = 0; str[i] != '\0'; i++)
    {
        x = 1;
        x = x << (str[i]-97);

        if((x & H) > 0)
        {
            printf("%c ", str[i]);
        }
        else
        {
            H = x | H;
        }

    }
    printf("\n");
}

void anagram(char *str1, char *str2)
{
    int H[26] = {0};
    int i;

    for(i = 0; str1[i] != '\0'; i++)
    {
        H[str1[i]-97]++;
    }

    for(i = 0; str2[i] != '\0'; i++)
    {
        H[str2[i]-97
        ]--;
    }

    for(i = 0; i < 26 && H[i] == 0; i++);

    if(i >= 26)
    {
        printf("Anagram\n");
    }
    else
    {
        printf("Not Anagram\n");
    }

}

void permutation(char *str, int k)
{
    static int flag[10] = {0};
    static char res[10];
    int i = 0;
    static int count = 1;

    if(str[k] == '\0')
    {
        res[k] = '\0';
        printf("%d. %s\n", count, res);
        count++;
    }
    else
    {
        for(i = 0; str[i] != '\0'; i++)
        {
            if(flag[i] == 0)
            {
                res[k] = str[i];
                flag[i] = 1;
                permutation(str, k + 1);
                flag[i] = 0;
            }
        }
    }

    
}