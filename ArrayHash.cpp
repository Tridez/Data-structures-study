#include "ArrayHash.h"

void InitHash(ARRAYHASH &HT, int &n)
{
	for(int i=0; i<HASHSIZE; i++)
		HT[i]=NULLFLAG; //初始化空标志
	n=0;
}

//查找成功返回item的位置，查找失败返回-1
int HashSearch(ARRAYHASH &HT, DataType item, int n)
{
	if(n<=0)
		return -1; //表空，查找失败

    int hashaddress=H(item); //计算哈希地址
    int pos=hashaddress;
	int i=0;//记录查找次数
	//在当前位置pos非空 且 pos位置上元素不是待查元素 而且 查找次数小于表长的情况下探查下一个地址
    while(HT[pos]!=NULLFLAG && HT[pos]!=item  &&i<HASHSIZE)    
	{
        pos=Collision(pos);//处理冲突
		i++;
	}
	if(HT[pos]==item)	
		return pos;  //查找成功
	else
		return -1; //查找失败
}

//item已存在、不能插入则返回-1；item不存在则返回item的插入位置
int HashSearch(ARRAYHASH &HT, DataType item)
{
    int hashaddress=H(item); //计算哈希地址
    int pos=hashaddress;
	int i=0;//记录查找次数
	int deleted_pos=-1; //已删除的位置
    while(HT[pos]!=NULLFLAG && HT[pos]!=item  &&i<HASHSIZE)    
	{
		if(HT[pos]==DELETEFLAG && deleted_pos==-1)
			deleted_pos=pos;
        pos=Collision(pos);//处理冲突
		i++;
	}
	if(HT[pos]==item)	
		return -1;  //item已存在，无法插入
	if(deleted_pos!=-1)
		return deleted_pos; //将item插入在删除标志位置上
	else
		return pos; //将item插入在空标志位置上
}

bool HashInsert(ARRAYHASH &HT, DataType item, int &n)
{
	if(n>=HASHSIZE)
		return false; //表满，插入失败

    int pos=HashSearch(HT, item); //在哈希表中查找item的插入位置
	if(pos<0) return false; //找到，则不必插入item

	HT[pos]=item; //在空位置或已删除位置上插入item	
	n++; //记录个数增1
	return true; 
} 

bool HashDelete(ARRAYHASH &HT, DataType item, int &n)
{
    int pos=HashSearch(HT, item, n);//在哈希表中查找item
	if(pos<0) 
		return false; //item不存在，删除失败

	HT[pos]=DELETEFLAG;//找到，则设置删除标志
	n--; //记录个数减1
	return true;//删除成功
}

bool TraverseHash(ARRAYHASH &HT, int n)
{
	if(n<=0)
		return false; //表空，遍历失败

	for(int i=0;i<HASHSIZE;i++)
        cout<<i<<"_"<<HT[i]<<"  ";
	cout<<endl;
    return true;
} 
