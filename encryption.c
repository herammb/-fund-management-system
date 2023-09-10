/*for loop
take one char at a time
check alpha or other
if alpha add key to it
print it and go to next char*/

#include <stdio.h>
#include <ctype.h>

void encode();
void intro();
void decode();

int main()
{
    intro();
}

void intro()
{
    printf("1.Encode\n");
    printf("2.decode\n");
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        encode();
        break;
    case 2:
        decode();
        break;
    default:
        return 1;
    }
}


void encode() {
    char text[100];
    printf("Enter text to be encoded: ");
    scanf("%s", text);

    for (int i = 0; text[i] != '\0'; i++)
        {
            if (isalpha(text[i]))
            {
                if (isupper(text[i]))
                {
                    text[i] = ((text[i] - 'A') + 13) % 26 + 'A';
                    }
                     else if (islower(text[i]))
                        {
                            text[i] = ((text[i] - 'a') + 13) % 26 + 'a';
                        }
            }
        }

    printf("The encoded message is: %s\n", text);
}

void decode()
{
    char text[100];
    printf("Enter text to be decoded: ");
    scanf("%s", text);

    for (int i = 0; text[i] != '\0'; i++)
        {
            if (isalpha(text[i]))
            {
                if (isupper(text[i]))
                {
                    text[i] = ((text[i] - 'A' - 13 + 26) % 26) + 'A';
                    }
                     else if (islower(text[i]))
                        {
                            text[i] = ((text[i] - 'a' - 13 + 26) % 26) + 'a';
                        }
            }
        }

    printf("The decoded message is: %s\n", text);
}

