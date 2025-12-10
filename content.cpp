#include "ArrayHash.h"
#include "LinkHash.h"

int main(void)
{
//开放定址法处理冲突
	int Array[]={23,13,45,15,16,26,18,20,31};
	ARRAYHASH my_hash1;
	int n;
	InitHash(my_hash1,n);
	for(int i=0;i<9;i++)//建立散列表
		HashInsert(my_hash1, Array[i],n);
	cout<<"下划线_前面的数字代表存储位置，下划线_后面是关键字，-1是空标志，-2是删除标志"<<endl;
	TraverseHash(my_hash1,n);

	int x=45;
	cout<<endl<<x<<"在"<<HashSearch(my_hash1, x,n)<<"号位"<<endl;

	x=5;
	cout<<endl<<"插入"<<x<<"的结果："<<endl;
	HashInsert(my_hash1, x, n);
	TraverseHash(my_hash1, n);

	x=26;
	cout<<endl<<"删除"<<x<<"的结果："<<endl;
	HashDelete(my_hash1, x, n);
	TraverseHash(my_hash1, n);

	x=5;
	cout<<endl<<"删除"<<x<<"的结果："<<endl;
	HashDelete(my_hash1, x, n);
	TraverseHash(my_hash1, n);

	x=10;
	cout<<endl<<"插入"<<x<<"的结果："<<endl;
	HashInsert(my_hash1, x, n);
	TraverseHash(my_hash1, n);

	x=27;
	cout<<endl<<x<<"在"<<HashSearch(my_hash1, x,n)<<"号位"<<endl;
	cout<<endl<<"插入"<<x<<"的结果："<<endl;
	HashInsert(my_hash1, x, n);
	TraverseHash(my_hash1, n);

//链地址法处理冲突
	LINKHASH my_hash2;
	InitHash(my_hash2);
	for(int i=0;i<9;i++)
		HashInsert(my_hash2, Array[i]);
	HashSearch(my_hash2, x);
	HashInsert(my_hash2, x);
	HashDelete(my_hash2, x);
	ClearHash(my_hash2);
	return 1;
}

