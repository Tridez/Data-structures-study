#include "BiTree.h"

//初始化空二叉树
void TreeInit(BTNode* &root)
{
	root=NULL;
}

//从二叉排序树中查找元素item，返回item所在结点的地址
BTNode *BSTSearch(BTNode *root,DataType item)
{
    BTNode *p=root;
    if(root==NULL)
        return NULL;//空树查找失败
    cout<<"开始查找"<<item<<endl;
    while(p)
    {
        cout<<p->data<<"->";
        if(p->data==item){
            cout<<"查找成功"<<endl;
            return p;
        }
        else if(p->data>item)
            p=p->left;
        else
            p=p->right;
    }
    cout<<"查找失败"<<endl;
    return NULL;
}

//向二叉排序树中插入item
int BSTInsert(BTNode *&root,DataType item)
{
	BTNode *p=root,*q=NULL; //q指向p的双亲
	while(p!=NULL)
	{ 
		q=p;		
		if(item==p->data) return 0; //item已存在不必插入
		if(item<p->data) p=p->left; //在左子树中查找
		else	p=p->right; //在右子树中查找
	}
	//查找失败，则进行插入操作
	p=new BTNode;
	p->data=item;  p->left=NULL;  p->right=NULL;
	if(q==NULL)//空树，item成为根
	{
		root=p;
		return 1;
	}	
	if(item<q->data) 
		q->left=p; //item作为叶子q的左孩子
	else 	
		q->right=p; //item作为叶子q的右孩子
    return 1;//插入成功 
}

int recursionBSInsert(BTNode*& root, DataType item)
{
    if (!root) {
		root = new BTNode;
		root->data = item;  root->left = NULL;  root->right = NULL;
		return 1;
	}
	if (root->data == item) return 0;
	if (root->data < item)
		return  recursionBSInsert(root->right, item);
	else
		return recursionBSInsert(root->left, item);

}


//查找二叉排序树中最大结点并删除它在二叉树中的链接关系
//最大结点：最右结点
//返回最大结点的地址
BTNode *BSTMaxNode(BTNode *&root)
{
	BTNode *max=NULL;
	BTNode *parent=NULL;//max结点的双亲结点

	if(root==NULL)//空树，直接返回
		return NULL;
	max=root;
	while(max!=NULL)
	{
		if(max->right==NULL)
			break;
		else
		{
			parent=max;
			max=max->right;//寻找最右结点
		}
	}
	if(parent==NULL)//root无右分支
		root=root->left;
	else
		parent->right=max->left;//删除单分支结点max(max->left分支可能有也可能无)

	return max;
}

//删除二叉排序树中与指定的数据相同的结点
int BSTDelete(BTNode *&root,DataType item)
{
	BTNode *p=root;
	BTNode *parent=NULL;//指定结点p的双亲结点
	//查找与item相等的结点p
	while(p!=NULL)
	{
		if(p->data==item)
			break;
		else if(p->data > item)
		{
			parent=p;
			p=p->left;//到左子树查找
		}
		else
		{
			parent=p;
			p=p->right;//到右子树查找
		}
	}
	//与item相同的结点不存在
	if(p==NULL)
		return 0;//删除失败
	
	//删除结点，需要调整二叉树
	//p是叶子结点
	if(p->left ==NULL && p->right==NULL)
	{
		if(parent->left==p)//p是其双亲结点的左子结点
			parent->left=NULL;
		else
			parent->right=NULL;
	}
	//p是单支结点
	else if(p->left==NULL ||p->right==NULL)
	{

		BTNode * son=NULL;//sun指向p的孩子结点
		
		if(p->left==NULL)
			son=p->right;
		else
			son=p->left;

		if(parent->left==p)//p是其双亲结点的左子结点
			parent->left=son;
		else
			parent->right=son;
	}
	//p是双支结点
	else 
	{
		BTNode * new_p=NULL;
		
		new_p=BSTMaxNode(p->left);//用p的中序前驱结点取代p结点
		p->data=new_p->data;
	                 p=new_p;
	}

	//删除结点并释放内存
	delete p;
	return 1;
}

//中序遍历二叉树
void InOrder(BTNode *root)
{
	if(root!=NULL)
	{	   
	    InOrder( root->left ); 	//前序遍历左子树 
		cout<<root->data<<" ";  //访问根
	    InOrder( root->right );     //前序遍历右子树
   	} 
}

//释放二叉树中所有结点
void ClearBTree(BTNode* &root)
{
    if(root!=NULL)
    {
        ClearBTree( root->left );
        ClearBTree( root->right );
        delete root;
        root=NULL;
    }
}
