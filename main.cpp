#include<iostream>
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include <string>
#include <sys/ioctl.h>
#include <ctype.h>
#include <unistd.h>
#include <termios.h>
#include "Treenode.h"
#include"Dentro.h"

#define N 5

class Treenode;


using namespace std;

#define LINESIZE 128
#define BACKSPACE 0x7f

int getchar_silent()
{
    int ch;
    struct termios oldt, newt;

    /* Retrieve old terminal settings */
    tcgetattr(STDIN_FILENO, &oldt);

    /* Disable canonical input mode, and input character echoing. */
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );

    /* Set new terminal settings */
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    /* Read next character, and then switch to old terminal settings. */
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}


void clearArray(char buf[],int len) //katharismos pinakwn
{

  for(int i=0;i<len;i++)
     buf[i]='\0';

}


int main (int argc,char*argv[]) {
    FILE *fp;
    char PATH[30];
    Dentro d;
    int linelength=128;
    char line[linelength]; // pinakas gia seira
    int countmisc=0; // metrima leksewn/kenwn ktl
    char c;
    int k=0;
    clearArray(line,linelength);
  /*
   fp = fopen("test1.txt","r");
    if(fp == NULL) {
        perror("Error in opening file");
        return(-1);
    }

    while((c=fgetc(fp)) != EOF) {
        if(c>=97 && c<=122) {
            d.add_a_node(c);
        }
        if(c=='\n') {

            d.add_papaki();

        }

    } */

     if (argc != 1 && argc != 3){                      // mono  dekta  osa ginontai enw ka8olou orismata kai -d PATH
        perror( " Wrong number of arguments! ");
        return -1;
    }
   if (argc == 1)                                     //default orisma sto PATH
        strcpy(PATH,"$HOME/.dict"); // boreis na peraseis kai to text1
    else{
        if (strcmp(argv[1],"-d") == 0)                //an to prwto orisma einai to -d tote proxwrame swsta sto path
            strcpy(PATH,argv[2]);
        else{
            cout << "Wrong arguments given" << endl;
            return -1;
        }
    }
     if((fp= fopen(PATH,"r+")) == NULL){            //Anoigei to arxeio kai elegxei an anoi3e swsta alliws emfanizei mhnyma la8ous
       perror("Error opening file");
       return -1;   }
         if(fp == NULL) {
        perror("Error in opening file");
        return(-1);
    }

    while((c=fgetc(fp)) != EOF) {
        if(c>=97 && c<=122) {
            d.add_a_node(c);
        }
        if(c=='\n') {

            d.add_papaki(0);

        }

    }
                                 //
 Treenode *riza1=d.getroot();
   d.fixfinishnode1(riza1);
    cout << "i loaded dictionary" << endl;

    char next;
    cout << "Press any word: \n\n";

    d.temp = d.getroot();
    while ((next = getchar_silent()) != VEOF) {
        putchar(next);
        if (isalpha(next)) {
            d.add_a_node(next);
            line[k++]=next;
            countmisc++;


        } else  if (next == '\t') {
            cout << endl << "Frequent words: " << endl;
            cout << endl;
            d.printTemp();
            cout << "End of frequent words" << endl;
            d.add_papaki(0);
           if(countmisc>=0)
            {


               for(int k=countmisc;k<18;k++)
                  d.leksi[k-countmisc]=d.leksi[k];
            } // shift left
            strcat(line,d.leksi);

            cout << ">"<<line << endl;
            k=0;
            countmisc=0;
           clearArray(line,linelength);

        }
        else if (next == '\n' ) {
            //line[k++];

            d.add_papaki(1); // add gia new word




        }
        else   if (next >= 'A' && next <= 'Z')
                {   next = next - ('A'-'a');
                    d.add_a_node(next);
                    line[k++]=next;
                    countmisc++;


                 }
         else if(next==' ')
           {
              line[k++]=' ';

              d.add_papaki(0); // afou ine space kataxoriseto os leksi
              countmisc=0;


           }
           else if(next == BACKSPACE){
                  printf("\b \b");
                  line[k]='\0';
                  line[k--];
                  countmisc--;
                 next= getchar_silent() ;
            }
    }



    Treenode *riza=d.getroot();
    d.deletetree(riza); // diagrafi dentrou

}
