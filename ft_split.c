#include "push_swap.h"

static int countWords(char *str, char c) 
{
    int count = 0;
    int insideWord = 0;

    while (*str) 
	{
        insideWord = 0;
        while (*str == c)
            str++;
        while (*str != c && *str) 
		{
            if (!insideWord) {
                count++;
                insideWord = 1;
            }
            str++;
        }
    }
    return count;
}

static char *getNextWord(char *str, char c) {
    static int cursor = 0;
    char *nextWord;
    int length = 0;
    int i = 0;

    while (str[cursor] == c)
        ++cursor;
    while ((str[cursor + length] != c) && str[cursor + length])
        ++length;
    nextWord = malloc((size_t)length * sizeof(char) + 1);
    if (NULL == nextWord)
        return (NULL);
    while ((str[cursor] != c) && str[cursor])
        nextWord[i++] = str[cursor++];
    nextWord[i] = '\0';
    return nextWord;
}

char **ft_split(char *str, char c)
{
    int wordsCount;
    char **string;
    int i;

    i = 0;
    wordsCount = countWords(str, c);
    if (!wordsCount)
        exit(1);
    string = malloc(sizeof(char *) * (size_t)(wordsCount + 2));
    if (NULL == string)
        return (NULL);
    while (wordsCount-- >= 0) 
	{
        if (0 == i) 
		{
            string[i] = malloc(sizeof(char));
            if (NULL == string[i])
                return (NULL);
            string[i++][0] = '\0';
            continue;
        }
        string[i++] = getNextWord(str, c);
    }
    string[i] = NULL;
    return string;
} 
