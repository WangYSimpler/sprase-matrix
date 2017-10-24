//SeqMatrix.h:
#include<iostream>

#include<stdlib.h>

#include<stdio.h>

#include<string.h>

#include <fstream>

using namespace std;

#define MAXSIZE 12500

typedef struct{
	int row;//行下标 
	int line;//列下标 
	int e;
}Triple;

typedef struct{
	Triple data[MAXSIZE+1];//data[0]未用
	int row_num,line_num,r_num;//行数，列数和非零元个数 	
}TSMatrix;

bool CreateSMatrix(TSMatrix &t1,int flag);//创建稀疏矩阵t1 
  
bool AddSMatrix(TSMatrix t1,TSMatrix t2,TSMatrix &t3);//相加两个稀疏矩阵 
  
bool PrintSMatrix(TSMatrix t1);//输出稀疏矩阵 


bool CreateSMatrix(TSMatrix &t1,int flag)//创建稀疏矩阵t1 
{
	ifstream infile; 
	if(flag==1) 
    	infile.open("1.txt");
	else if(flag==2)
	    infile.open("2.txt");
			    
    if(!infile.is_open())  
    {  
        cout<<"Could Not Open File!!!";  
        exit(EXIT_FAILURE);  
    }
    
    int row_set,line_set;
	cout<<"the row is:";
	cin>>row_set;
	cout<<"the line is:";
	cin>>line_set;  
	//cout<<row_set<<" "<<line_set<<endl;
    int val; 
    int count = 0; 
    infile >> val;  
    int row1 = 1,line1 = 1;
    t1.row_num = row_set;
    t1.line_num = line_set;
	while(infile.good())  
    {  
        if(val!=0){
			++count;
			t1.data[count].e=val;
			t1.data[count].row=row1;
			t1.data[count].line=line1;
		} 
		if(line1==line_set){
			line1=1;
			++row1;
			if(row1==row_set+1){
				break;
			}
		}
		else{
			++line1;
		}
        //cout<<row1<<" "<<line1<<endl;
		infile >> val;  
    }  
    t1.r_num=count;
    
    if(infile.eof())  
        cout<<"End Of File!!";  
    cout<<"Count: "<<count<<endl<<endl;    
    infile.close();  
    return 0;  
	
}
  
bool AddSMatrix(TSMatrix t1,TSMatrix t2,TSMatrix &t3)//相加两个稀疏矩阵 
{
    int r=1,l=1;
    int i=1,j=1;
    int count=0;
 //   cout<<"t1.r_num="<<t1.r_num<<endl;
//    cout<<"t2.r_num="<<t2.r_num<<endl;
    if(t1.row_num!=t2.row_num||t1.line_num!=t2.line_num){
    	cout<<"两个矩阵不一样大"<<endl;
		getchar(); 
		return false;
    }
    else{
    	t3.row_num=t1.row_num;
    	t3.line_num=t1.line_num;
    }
    while(1){
    	if(i<=t1.r_num&&j<=t2.r_num){
	    	if(t1.data[i].row==t2.data[j].row){
		    	if(t1.data[i].line<t2.data[j].line){
		    		++count;
					t3.data[count].e=t1.data[i].e;
					t3.data[count].row=t1.data[i].row;
					t3.data[count].line=t1.data[i].line;
				    ++i;
				}
				else if(t1.data[i].line>t2.data[j].line){
		    		++count;
					t3.data[count].e=t2.data[j].e;
					t3.data[count].row=t2.data[j].row;
					t3.data[count].line=t2.data[j].line;
				    ++j;
				}
				else{
		    		t3.data[count].e=(t1.data[i].e+t2.data[j].e);
					t3.data[count].row=t1.data[i].row;
					t3.data[count].line=t1.data[i].line;
				    ++i;++j;
				}	
		    }
		    else if(t1.data[i].row<t2.data[j].row){
	    			++count;
					t3.data[count].e=t1.data[i].e;
					t3.data[count].row=t1.data[i].row;
					t3.data[count].line=t1.data[i].line;
				    ++i;
	    	}
	    	else{
		    		++count;
					t3.data[count].e=t2.data[j].e;
					t3.data[count].row=t2.data[j].row;
					t3.data[count].line=t2.data[j].line;
				    ++j;	    	
		    }
    	}
		else if(i>t1.r_num){
		    ++count;
			t3.data[count].e=t2.data[j].e;
			t3.data[count].row=t2.data[j].row;
			t3.data[count].line=t2.data[j].line;
			break;
		}	
		else if(j>t1.r_num){
			++count;
			t3.data[count].e=t1.data[i].e;
			t3.data[count].row=t1.data[i].row;
			t3.data[count].line=t1.data[i].line;
		    break;
		}
    }
    t3.r_num=count;
    //cout<<"count="<<count<<endl;
	
}
bool PrintSMatrix(TSMatrix t1)//输出稀疏矩阵
{
   cout<<"t1.r_num="<<t1.r_num<<endl;
   //int flag=1;
   int i=1;
   int r=1,l=1; 
   	    while(r!=t1.row_num+1){
    	   	if(t1.data[i].row!=r||t1.data[i].line!=l){
        		cout<<" 0 ";
        		//getchar();				
        	}
        	else if(t1.data[i].row==r&&t1.data[i].line==l){
        		cout<<" "<<t1.data[i].e<<" "; 
        		++i;
        	}
	        
			if(l==t1.line_num){
			   cout<<endl;
			   l=1;
               ++r;
			}
			else{
			   ++l;
			}
	 
        }
	    
   
} 
