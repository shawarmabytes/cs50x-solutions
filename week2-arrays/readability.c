#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string input_text = get_string("Text: ");

    int letters = count_letters(input_text);
    //printf("%i letters\n", letters); //prints letters(sanity check)

    int words = count_words(input_text);
    //printf("%i words\n", words); //prints words(sanity check)

    int sentences = count_sentences(input_text);
    //printf("%i sentences\n", sentences); //prints sentences(sanity check)

    //(float) to prevent truncation
    float L = (float) letters / words * 100;
    //printf("double L is %.5f \n", L); //prints L(sanity check)

    float S = (float) sentences / words * 100;
    //printf("double S is %.5f \n", S); //prints S(sanity check)

    float index = 0.0588 * L - 0.296 * S - 15.8;
    //printf("double index is %.5f \n", index); //prints index(sanity check)

    int final_index = round(index);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (final_index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", final_index);
    }

}


int count_letters(string text)
{
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (islower(text[i]) || isupper(text[i]))
        {
            letters++;
            //printf("letter from input_text[%i] is %c \n", i, text[i]); //for testing if the IF-BLOCK-COUNTER works
        }
    }
    return letters;
}

int count_words(string text)
{
    int words = 1;
    for (int j = 0; j < strlen(text); j++)
    {
        if (isspace(text[j]))
        {
            words++;
            //printf("there are %i spaces, and therefore %i words \n", words-1, words); //for sanity checking only
        }
    }
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;
    for (int k = 0; k < strlen(text); k++)
    {
        if (text[k] == '!' || text[k] == '?' || text[k] == '.') // "string char" vs 'string literal'
        {
            sentences++;
        }
    }
    return sentences;
}
