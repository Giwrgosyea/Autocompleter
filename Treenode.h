#ifndef TREENODE_H
#define TREENODE_H
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

class Treenode
{
    public:
    char letter;
    int frequency;
    Treenode *father;
    Treenode *finish[N];
    Treenode *lexikon[27];
    Treenode(char);
    ~Treenode();


};

#endif // TREENODE_H
