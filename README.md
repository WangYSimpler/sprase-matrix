# -
稀疏矩阵，三元组

一.实验目的和要求
1．了解稀疏矩阵的三元组线性表存储方法。
2．掌握稀疏矩阵采用顺序存储结构时基本操作的实现。

二. 实验内容
1．编写稀疏矩阵采用顺序存储结构--三元组顺序表时基本操作的实现函数。基本操作包括：①创建稀疏矩阵CreateSMatrix；②稀疏矩阵相加运算AddSMatrix；③输出稀疏矩阵PrintSMatrix 等。要求把稀疏矩阵的存储结构定义及基本操作实现函数存放在头文件SeqMatrix.h中，主函数main() 存放在主文件test2.cpp中，在主函数中通过调用SeqMatrix.h中的函数进行测试。
2．填写实验报告，实验报告文件取名为report2.doc。
3．上传实验报告文件report2.doc与源程序文件SeqMatrix.h及test2.cpp。

三. 函数的功能说明及算法思路
    包括每个函数的功能说明，及一些重要函数的算法实现思路
  CreateSMatrix(t1,1);
  	从txt文件中读取矩阵数据到顺序结构当中，1表示读取1.txt
  	2表示读取2.txt   通过给定行数和列数来读取相应数量的数字，遇到0跳	过，遇到非零保存行号，列号和数字并且存入结构data

  AddSMatrix(t1,t2,t3);
  	将t1和t2相加，将结构存到t3，如果t1和t2总行数或者总列数不相同，则二者大小不一，则不做操作。
    通过遍历两个三元表，获得列号更小（列号相同时，行号更小）的三元组元素并存入t3。如果同一行同一列都有非零的元素，那么二者相加。当基数达到t1,t2存储的最大值时，比较最后两个三元元素的前后关系并且依次存入t3。这样t3就或者了二者相加的结果。
  PrintSMatrix(t1);
