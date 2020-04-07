#include "Dentro.h"
#include"Treenode.h"
#include<iostream>
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include <string>
#include <sys/ioctl.h>
#include <ctype.h>
#include <unistd.h>
#include <termios.h>
#define N 5
using namespace std;

Dentro:: Dentro() {
        root = new Treenode('?');
        root->father=NULL;
        teleutaioskomvos = NULL;
        // cout << "created a Tree" << endl;
        temp=root;
        temp2 = NULL;
        for(int i=0;i<18;i++)
            leksi[i]=0;
         }

Dentro::~Dentro()
{
    //dtor
}

void Dentro::add_a_node(char gramma) {
        int value=(int)gramma-(int)'a';
        if (value == 26) {
            cout << "oops" << endl;
            exit(-1);
        }

        if(temp->lexikon[value]==NULL) {
            temp->lexikon[value]=new Treenode(gramma);
            temp->lexikon[value]->father=temp;
            temp=temp->lexikon[value];
        } else {
            //cout<< "->"<< endl;
            temp= temp->lexikon[value]; //proxora ston epomeno!
        }
    }

   void Dentro::add_papaki(int f) {
        if (temp->lexikon[26] == NULL) {
            temp->lexikon[26] = new Treenode('@');
           // temp->lexikon[27]=teleutaioskomvos; //AXRISTO
            temp->lexikon[26]->father=temp; // kane ton komvo papaki na di3ei pisw sto temp
            temp->lexikon[26]->frequency = f;
        } else {
            temp->lexikon[26]->frequency++;
        }

        finishnodes(temp, temp->lexikon[26]); // kokkino velos di3e sto papaki
        temp=root; //ara meta kai tin teleutaia eisagwgi le3is to temp paei kai dixnei sto root pali

    }

       void Dentro::treeprint(Treenode *node) {
        if (node->lexikon[26] != NULL)
            print(node);
        for (int i=0; i<25; i++) {
            if (node->lexikon[i] != NULL)
                treeprint(node->lexikon[i]);
        }

    }

     void Dentro:: print(Treenode *node) {
        char word[30];
        int i=0;

          while (i < N)  { //prp na kanw gia to i sto velaki
            if(node->finish[i] != NULL)
            {getWord(node->finish[i]->father,word);
             i++;
            }
            else {
                  cout << "den uparxei tetoia le3i"<<endl;
                  return;
                 }
            }
            cout << "make your choice " <<endl;
            cin >> i;
            if(i>=0 && i<=N)
                {
                  getWord(node->finish[i]->father,word); // epilogi
                  return;
                  }
            else
                 cout << "choose a valid number :) " << endl;
          //sorting
    }
   void Dentro ::  printTemp() {
        print(temp);
    }
    void  Dentro ::  getWord(Treenode *node,char *word) {
        char tempword[25];
        int i=0,j=0;

        while (node->letter != '?') {

            tempword[i++] = node->letter;
            node = node->father;
        }
        while (i > 0) // print word backwards
            word[j++] = tempword[--i]; //fortwnw apo temp sto word
        word[j] = '\0';
       cout << word << endl;
       strcpy(leksi,word);

    }

       void Dentro:: finishnodes(Treenode *node, Treenode* papaki) { //fix finishnodes velakia  anadromika
        int min_frequency = papaki->frequency;
        int min_pos = -1;

        if (node == NULL) {
            return;
        }

        for (int i=0; i<N; i++) {
            if (node->finish[i] == papaki) { // an kapoiow dixnei sto papaki pare patera kai anadromi pali
                finishnodes(node->father, papaki);
                return;
            }
        }

        for (int i=0; i<N; i++) {
            if (node->finish[i] == NULL) { // an den uparxei parto kai pare ton patera atofion
                node->finish[i] = papaki;
                finishnodes(node->father, papaki);
                return;
            }
        }


        for (int i=0; i<N; i++) {
            if (node->finish[i]->frequency <= min_frequency) { //an to freq autou tou komvoy einai mikrotero i iso
                min_frequency = node->finish[i]->frequency ;
                min_pos = i;
            }
        }

        if (min_pos >= 0) {  // anvreis toulaxiston enan kovo pare to papaki
           node->finish[min_pos] = papaki;
        }
        finishnodes(node->father, papaki);
    }
    void Dentro:: deletetree (Treenode *node) { //rroot->lexikon[i]
        for (int i=0; i<27; i++) { //26 olus tus komvous ektos apo ta fila
            if (node->lexikon[i] != NULL)
                deletetree(node->lexikon[i]);

        }
        delete node;

}

void Dentro::fixfinishnode1(Treenode *node)
   {
     for (int i=0; i<26; i++) { //26 olus tus komvous ektos apo ta fila
            if (node->lexikon[i] != NULL)
               fixfinishnode1(node->lexikon[i]);//trexa olous tous komvous

        }
    int i=0;
    if( node->lexikon[26]!=NULL)
       {
         node->finish[i]=node->lexikon[26];
         i++;
       }
    for (int n=0;n<26;n++) // tou idiou pediou
     {
     if (node->lexikon[n] != NULL)
            {
             int j=0;
             while (i < N && node->lexikon[n]->finish[j] != NULL)
                     {
                       node->finish[i] = node->lexikon[n]->finish[j];
                       i++;//trexon komvou
                       j++; // tou kathe paidiu
                      }
             }
             }

}

    Treenode* Dentro:: getroot() { // epistrefw riza
        temp=root;
        return temp;
    }

