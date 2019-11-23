#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int p;
void style1()
{
    printf("Word\t\tMeaning\n");
    for(p=0;p<30;p++)
    {
        printf("=");
    }
    printf("\n");
}
void style2()
{
    for(p=0;p<30;p++)
    {
        printf("-");
    }
    printf("\n");
}
struct vocab
{
    char word[20];
    char meaning[5][20];
};

void main()
{
    int i=0,j,k,l, count=0, length, user;
    char word[20], meaning[20], choice, choice1,choice2, search[20];
    struct vocab words[100];


    do
    {
        printf("\t\tDictionary\n\n");
        printf("\t\t1. Add Word.\n");
        printf("\t\t2. Search Word.\n");
        printf("\t\t3. Show Dictionary.\n");
        printf("\t\t4. Exit.\n\n");
        printf("\t\tYour Choice: ");
        fflush(stdin);
        scanf("%d", &user);
        if(user==1 || user==2 || user==3 || user==4)
        {
            switch(user)
            {
            case 1:
                do
                {
                    printf("Enter a word: ");
                    fflush(stdin);
                    gets(word);

                    length=strlen(word);
                    for(j=0;j<i;j++)
                    {
                        for(k=0;k<length;k++)
                        {
                            if(length==strlen(words[j].word))
                            {
                                if(word[k]==words[j].word[k])
                                {
                                    count++;
                                }
                            }
                        }
                        if(count==length)
                        {
                            printf("The word you entered is already in the dictionary.\nYou want to see that? y/n: ");
                            scanf("%c", &choice2);
                            if(choice2=='y')
                            {
                                style1();
                                printf("%s", words[j].word);
                                for(k=0;k<5;k++)
                                {
                                    if(*words[j].meaning[k]==0)
                                        break;
                                    printf("\t\t%s\n", words[j].meaning[k]);
                                }
                                style2();
                                break;
                            }
                            else
                                break;
                        }
                    }
                    if(count!=length)
                        {
                            strcpy(words[i].word, word);
                            printf("You can Enter 5 meanings to each word.\n");
                            for(j=0;j<5;j++)
                            {
                                printf("Enter meaning(s): ");
                                fflush(stdin);
                                gets(meaning);
                                strcpy(words[i].meaning[j], meaning);
                                if(j==4)
                                {
                                    continue;
                                }
                                printf("You want to add another meaning? y/n: ");
                                scanf("%c", &choice);
                                if(choice!='y')
                                {
                                    break;
                                }
                            }
                            i++;
                        }
                    count=0;
                    printf("You want to add another word? y/n: ");
                    fflush(stdin);
                    scanf("%c", &choice1);
                } while(choice1=='y');
                system("cls");
                break;
            case 2:
                printf("Type in the word you want to search: ");
                scanf("%s", &search);
                length=strlen(search);
                for(j=0;j<i;j++)
                {
                    for(k=0;k<length;k++)
                    {
                        if(length==strlen(words[j].word))
                        {
                            if(search[k]==words[j].word[k])
                            {
                                count++;
                            }
                        }
                    }
                    if(count==length)
                    {
                        style1();
                        printf("%s", words[j].word);
                        for(k=0;k<5;k++)
                        {
                            if(*words[j].meaning[k]==0)
                                break;
                            printf("\t\t%s\n", words[j].meaning[k]);
                        }
                        style2();
                        break;
                    }
                }
                if(count!=length)
                    printf("Word not found!\n");
                count=0;
                system("pause");
                system("cls");
                break;
            case 3:
                if(*words[0].word==NULL)
                {
                    printf("No words have been added yet!\n");
                }
                else
                {
                    style1();
                    for(j=0;j<i;j++)
                    {
                        printf("%s", words[j].word);
                        for(k=0;k<5;k++)
                        {
                            if(*words[j].meaning[k]==0)
                                break;
                            printf("\t\t%s\n", words[j].meaning[k]);
                        }
                        style2();
                    }
                }
                system("pause");
                system("cls");
                break;
            }
        }
        else
        {
            printf("Please Enter correct value!(between 1-4)\n\n");
            system("pause");
            system("cls");
        }
        //user=0;
    } while(user!=4);
    if(user==4)
        {
            printf("Thank you!\n");
            system("pause");
        }
    printf("\n");
}
