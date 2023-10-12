#include<stdio.h>
#include<stdlib.h>
#define MaxSize 10
typedef struct{
	int data[MaxSize];
	int length;
}SqList;
bool ListInsert(SqList &L,int i,int e)  
{
	if(i<1||i>L.length+1) return false;    
	if(L.length>=MaxSize) return false;   
	for(int j=L.length;j>=i;j--)
	{
		L.data[j]=L.data[j-1];
	}
	L.data[i-1]=e;
	L.length++;
}
bool ListDelete(SqList &L,int i,int &e)
{
	if(i<1||i>L.length) return false;
	e=L.data[i-1];
	for(int j=i;j<L.length;j++)
	{
		L.data[j-1]=L.data[j];
	}
	L.length--;
	return true;
} 
int LocateElem(SqList L,int e)
{
	for(int i=1;i<=L.length;i++)
	{
		if(L.data[i-1]==e)
		{
			return i;
		}
	}
	return 0;
}
void PrintList(SqList L)
{
	for(int i=1;i<=L.length;i++)
	{
		printf("%d ",L.data[i-1]);

    }		
}
int main()
{
	SqList L;
	L.length=0; 
	int e;
	ListInsert(L,1,1); 
	ListInsert(L,2,2); 
	ListInsert(L,3,3);
	ListInsert(L,4,4);
	ListInsert(L,5,5);
	ListDelete(L,3,e);
	PrintList(L);
	printf("%d",LocateElem(L,2));
	return 0; 
}
