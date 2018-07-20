// Louisa Katlubeck
// Random test generator
// Sources: Initial code provided by CS362, https://stackoverflow.com/questions/17167949/how-to-use-timer-in-c/24383125,
// https://www.geeksforgeeks.org/how-to-measure-time-taken-by-a-program-in-c/, http://www.asciitable.com/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


char inputChar()
{
    // description: inputChar() picks and returns a random character from the pool of characters 
    // only target characters are used
    char charPool[] = {'[', '(', '{', ' ', 'a', 'x', '}', ')', ']'};

    // get a random number between 0 and 8 and select that character
    int r = rand() % 9;
    char result = charPool[r];

    // return the result
    return result;
}

char *inputString()
{
    // description: inputString returns a string of random characters
    // the string is 5 characters long and only target characters are used
    char stringPool[] = {'r', 'e', 's', 't'};
    char nextChar;
    char result[6];
    int i = 0;
    int r;

    // create the random string
    for (i = 0; i < 5; i++){
        // get a random number between 0 and 3 and select that character
        r = rand() % 4;
        nextChar = stringPool[r];
        result[i] = nextChar;
    }

    // add the trailing terminating character
    result[5] = '\0';

    // return the result
    return result;
}

void testme()
{
    // start the timer
    clock_t before = clock();

    int tcCount = 0;
    char *s;
    char c;
    int state = 0;
    while (1)
    {
        tcCount++;
        c = inputChar();
        s = inputString();
        printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

        if (c == '[' && state == 0)
            state = 1;
        if (c == '(' && state == 1)
            state = 2;
        if (c == '{' && state == 2)
            state = 3;
        if (c == ' ' && state == 3)
            state = 4;
        if (c == 'a' && state == 4)
            state = 5;
        if (c == 'x' && state == 5)
            state = 6;
        if (c == '}' && state == 6)
            state = 7;
        if (c == ')' && state == 7)
            state = 8;
        if (c == ']' && state == 8)
            state = 9;
        if (s[0] == 'r' && s[1] == 'e' && s[2] == 's' && s[3] == 'e' && s[4] == 't' && s[5] == '\0' && state == 9)
        {
            // stop the timer
            clock_t stop_time = clock() - before;

            double total_time = ((double)stop_time)/CLOCKS_PER_SEC;

            // print the time
            printf("The program took %f ns to run\n", 1000000.*total_time);

            printf("error ");
            exit(200);
        }
    }
}

int main(int argc, char *argv[])
{
    srand(time(NULL));

    // call the function
    testme();

    return 0;
}
