/******************************************************************************

The following RDP is for the grammer given below. 

@auther="Chetan Panchal"

E -> TE'
E' -> +TE' | ε
T -> FT'
T' -> *FT' | ε
F -> (E) | id

*******************************************************************************/

#include<stdio.h>
#include<string.h>
#include<ctype.h>
 
char input[10];
int i,error;
void E();
void T();
void Eprime();
void Tprime();
void F(); 
          
int main()
    {
        i=0;
        error=0;
        printf("Enter an arithmetic expression   :  "); // Eg: a+a*a
        gets(input);
        E();
        if(strlen(input)==i&&error==0)
        printf("\nIt is valid input. \n");
                else printf("\nIt is not valid String\n");
    }
         
         
void E()
{
     T();
     Eprime();
}

void Eprime()
{
     if(input[i]=='+')
     {
         i++;
         T();
        Eprime();
     }
}

void T()
{
     F();
     Tprime();
}

void Tprime()
{
    if(input[i]=='*')
    {
        i++;
        F();
        Tprime();
    }
}

void F()
    {
        if(isalnum(input[i]))
        {
            i++;
        }
        else if(input[i]=='(')
        {
            i++;
            E();
            if(input[i]==')')
            {
                i++;
            }
            else
            {
                error=1;
            }
        }
        else
        {
            error=1;
        }
    }
