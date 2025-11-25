int seqList(SqList L, DataType x){
    int i = L.length;
    L.items[0].key = x.key;
    while(L.items[i].key != x.key) i--;
    return i;
}  

int i = 0;
while(L.items[i].key != x.key && i < L.length)
i++;