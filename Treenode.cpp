#include "Treenode.h"
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
Treenode::  Treenode(char gramma):letter(gramma) {
        for(int i=0; i<27; i++)
            lexikon[i]=NULL;
        for(int j=0; j<N; j++)
            finish[j]=NULL;
        father=NULL;
        frequency = 0;
    }

Treenode::~Treenode()
{
    //dtor
}
