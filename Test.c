#include <stdio.h>
#include <string.h>
#define MAX_LINE_LENGTH 170
#define MAX_MEMBER_LENGTH 50

void read_next_member(char *member, char *line)
{
        short int               i;
        static short int        j = 0;

        i = 0;
        if (j >= MAX_LINE_LENGTH)
        {
                j = 0;
        }
        while (i < 50)
        {            
                member[i++] = '\0';
        }
        i = 0;
        while (1)
        {
                if (line[j] == '\n' || line[j] == EOF || line[j] == '\0' || line[j] == ';')
                {
                        j++;
                        return ;
                }
                //printf("valor de indice j:%d vai para membro indice i:%d\n", j ,i);
                member[i++] = line[j++];
        }
}

int main()
{
        FILE    *db_text;
        char    line[50];
        char    member[50];

        member[49] = '\0';
        db_text = fopen("./db.txt", "r");
        printf("hello World\n");

        fgets(line, MAX_MEMBER_LENGTH, db_text);
        read_next_member(member, line);
        printf("***%s***\n", member);
        read_next_member(member, line);
        printf("***%s***\n", member);

        return 0;
}