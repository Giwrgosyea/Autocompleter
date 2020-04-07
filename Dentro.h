#ifndef DENTRO_H
#define DENTRO_H
#include"Treenode.h"
#include"Dentro.h"
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
class Dentro
{
    public:
        Dentro();
        ~Dentro();
    Treenode*root;
    Treenode *teleutaioskomvos; // di3e sto teleutaio gramma
    Treenode *temp,*temp2;
    char leksi[18]; // 18 megethos le3is :) !
    void add_a_node(char);
    void add_papaki(int);
    void treeprint(Treenode *);
    void print(Treenode *);
    void printTemp();
    void getWord(Treenode *,char *);
    void finishnodes(Treenode *, Treenode* );
    void deletetree (Treenode *);
    void fixfinishnode1(Treenode *);
    Treenode* getroot();
};

#endif // DENTRO_H
