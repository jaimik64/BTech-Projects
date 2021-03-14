/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    void count(char* str);
    char* str[1000];
    scanf("%s",&str);
    count(str);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
void count(char* str){
    int i, zero = 0, one = 0, two = 0, three = 0, four = 0, five = 0, six = 0, seven = 0,eight = 0, nine = 0;
    for(i = 0; str[i] != ' '; i++){
            switch(str[i]){
                case '1':
                    one += 1;
                    break;
                case '2':
                    two += 1;
                    break;
                case '3':
                    three += 1;
                    break;
                case '4':
                    four += 1;
                    break;
                case '5':
                    five += 1;
                    break;
                case '6':
                    six += 1;
                    break;
                case '7':
                    seven += 1;
                    break;
                case '8':
                    eight += 1;
                    break;
                case '9':
                    nine += 1;
                    break;
                case '0':
                    zero += 1;
                    break;
                default:
                    printf("");
            }
    }
    printf("%d %d %d %d %d %d %d %d %d %d",zero,one,two,three,four,five,six,seven,eight,nine);
}


