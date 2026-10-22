#include <stdio.h>
#include <string.h>

void getNext(char* pattern, int* next)
{
    int m = strlen(pattern);
    int i = 0;
    int j = -1;
    next[0] = -1;
    while(i < m)
    {
        if (j == -1 || pattern[i] == pattern[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
}

int kmp(char* str, char* pattern)
{
    int i = 0;
    int j = 0;
    int next[100];
    getNext(pattern, next);
    int n = strlen(str);
    int m = strlen(pattern);

    while(i < n && j < m)
    {
        if (j == -1 || str[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }

    if (j == m)
    {
        return i - j;
    }
    else
    {
        return -1;
    }
}

int main()
{
    char* str = "abaabaabacacaabaabcc";
    char* pattern = "abaabc";
    printf("%d\n", kmp(str, pattern));
    return 0;
}