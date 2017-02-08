#ifndef ARRAY_H
#define ARRAY_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MAXINT 2147483646

void printarr(int*a,int n);
//打印数组
void FillArray(int a[],int n);
//生成数组的样本数据
void Config();
//配置系统参数：数组元素个数、一行打印元素个数、每个元素的打印宽度等
void Reverse(int a[],int n);
//逆置数组
void insert(int a[],int n,int pos,int val);
//在数组中 pos下标处插入新元素
void Delete(int a[],int n,int id);
//删除指定下标的元素
void DeleteRange(int a[],int n,int s,int t);
//删除 s..t下标区间的元素
int Search(int a[],int n,int val);
//查找值为 val的元素，找到返回其下标，找不到返回-1
int isAsc(int a[],int n);
//判断数组是否升序排列
int isDesc(int a[],int n);
//判断数组是否降序排列
int isEqual(int a[],int n);
//判断数组是否全相等
int max(int a[],int n);
//返回数组最大值的下标
int min(int a[],int n);
//返回数组最小值的下标
float average(int a[],int n);
//计算数组的平均值
void OrderInsert(int a[],int n,int val);
//在有序数组中插入新元素保持有序性
void BubbleSort(int a[],int n,int (*comp)(int a,int b));
//冒泡排序
void SelectSort(int a[],int n,int (*comp)(int a,int b));
//选择排序
void ExchangeSort(int a[],int n,int (*comp)(int a,int b));
//交换排序
int BiSearch(int a[],int n,int val,int (*comp)(int a,int b));
//二分查找
void LeftRotate(int a[],int n,int m);
//左旋 m位
void RightRotate(int a[],int n,int m);
//右旋 m位
#endif
