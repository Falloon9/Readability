#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);

int main(void)
{
    string text = get_string("Text: ");

    int letters = 0;
    int Words = 1;
    int Sentences = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
        else if (text[i] == ' ')
        {
            Words++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            Sentences++;
        }
    }
    float L = letters / (float)Words * 100;
    float S = Sentences / (float)Words * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}
