#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int maxline);
void reverse(char str[]);

int main(int argc, char* argv[])
{
    char line[MAXLINE];

    printf("enter the line (enter 'x' to exit) : ");

    while (get_line(line, MAXLINE) > 0 && line[0]!='x') {
        reverse(line);
        printf("The reverse line: ");
        printf("%s\n", line);
        printf("\nenter the line (enter 'x' to exit) : ");
    }
    printf("exit program~~~~");
    return 0;
}

int get_line(char str[], int lim)
{
    int in, i, length;

    for (i = 0, length = 0; (in = getchar()) != EOF && in != '\n'; i++)
        if (i < lim - 1)
            str[length++] = in;
    if (in == '\n' && length < lim - 1)
        str[length++] = in;
    str[length] = '\0';

    return length;
}

void reverse(char str[])
{
    int a, b, temp;

    for (b = 0; str[b] != '\0'; b++);
    b--;
    if (str[b - 1] == '\n')
        b--;

    for (a = 0; a < b; a++, b--) {
        temp = str[a];
        str[a] = str[b];
        str[b] = temp;
    }
}