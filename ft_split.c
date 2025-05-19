#include "push_swap.h"
/*
static int	count_words(char *str, char c)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*str)
	{
		inside_word = false;
		while (*str == c)
			++str;
		while (*str != c && *str)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++str;
		}
	}
	return (count);
}

static char	*get_next_word(char *str, char c)
{
	static int	cursor = 0;
	char		*next_str;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (str[cursor] == c)
		++cursor;
	while ((str[cursor + len] != c) && str[cursor + len])
		++len;
	next_str = malloc((size_t)len * sizeof(char) + 1);
	if (NULL == next_str)
		return (NULL);
	while ((str[cursor] != c) && str[cursor])
		next_str[i++] = str[cursor++];
	next_str[i] = '\0';
	return (next_str);
}

char	**ft_split(char *str, char c)
{
	int		words_number;
	char	**vector_strings;
	int		i;

	i = 0;
	words_number = count_words(str, c);
	if (!words_number)
		exit(1);
	vector_strings = malloc(sizeof(char *) * (size_t)(words_number + 2));
	if (NULL == vector_strings)
		return (NULL);
	while (words_number-- >= 0)
	{
		if (0 == i)
		{
			vector_strings[i] = malloc(sizeof(char));
			if (NULL == vector_strings[i])
				return (NULL);
			vector_strings[i++][0] = '\0';
			continue ;
		}
		vector_strings[i++] = get_next_word(str, c);
	}
	vector_strings[i] = NULL;
	return (vector_strings);
} */

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
/*
static long	ft_atol(const char *str)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * sign);
} */