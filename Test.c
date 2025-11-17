#include <stdio.h>
#include <string.h>
#define MAX_LINE_LENGTH 170

void read_next_member(char *member, char *line)
{
        short int               i;
        static short int        j = 0;

        i = 0;
        if (j >= MAX_LINE_LENGTH)
                return ;
        while (i < 50)
        {
                member[i++] = '0';
        }
        i = 0;
        while (1)
        {
                if (line[j] == '\n')
                {
                        j++;
                        return ;
                }
                member[i++] = line[j++];
        }
}

int main()
{
        char    line[MAX_LINE_LENGTH] = "Esta linha é\ndo caraças";
        char    member[50];

        member[49] = '\0';

        printf("hello World\n");

        read_next_member(member, line);
        printf("***%s***\n", member);
        read_next_member(member, line);
        printf("***%s***\n", member);

        return 0;
}