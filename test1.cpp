//Test1.cpp：
#include<iostream>

#include<stdlib.h>

#include<stdio.h>

#include<string.h>

using namespace std;

#define MAXSIZE 12500

#include "SeqMatrix.h"

int main()
{
   
  TSMatrix t1,t2,t3;//定义稀疏矩阵t1，t2 
  CreateSMatrix(t1,1);//创建稀疏矩阵t1 
  CreateSMatrix(t2,2);//创建稀疏矩阵t2 
  cout<<"以下为t1:"<<endl; 
  PrintSMatrix(t1);//输出稀疏矩阵 
  cout<<"以下为t2:"<<endl; 
  PrintSMatrix(t2);//输出稀疏矩阵 
  //cout<<"3wer23"<<endl;
  getchar();
  AddSMatrix(t1,t2,t3);//相加两个稀疏矩阵 

  cout<<"以下为t3:"<<endl;
  PrintSMatrix(t3);//输出稀疏矩阵 
  return 0;
}
