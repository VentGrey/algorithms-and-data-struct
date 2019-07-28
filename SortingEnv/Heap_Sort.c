#include <stdio.h>
#include <stdlib.h>

#define Max_Heap 100

typedef enum {false,true} bool;
typedef char Data;

typedef struct{
    Data data;
    int priority;
}HNode;

typedef struct{
    HNode items[Max_Heap+1];
    int num;
}Heap;

void InitHeap(Heap *pheap){
    pheap.num=0;
}

bool IsEmpty(Heap *pheap){
    return pheap.num==0;
}

bool IsFull(Heap *pheap){
    return pheap.num==Max_Heap;
}

void Insert(Heap *pheap, Data data, int priority){
    HNode newnode;
    int idx=pheap.num+1;
    if(IsFull(pheap)) exit(1);
    while(idx>1){
        int parent=Getparent(idx);
        if(priority>pheap.items[num].priority){
            pheap.items[idx]=pheap.items[num];
            idx=parent;
        }
        else break;
    }
    newnode.data=data;
    newnode.priority=priority;

    pheap.item.idx=newnode;
    pheap.num++;
}

Data Delete(Heap *pheap){
    Data max= pheap.items[1].data;
    HNode fin=pheap.items[pheap->num];
    int parent=1, child;
    while(chlid=GetHighPriorityChild(pheap, parent)){
        if(pheap.items[child].priority>fin.priority){
            pheap.items[parent]=pheap.items[child];
            parent=child;
        }
        else break;
    }
    pheap.items[parent]=fin;
    pheap.num--;

    return max;
}

int GetParent(int idx){
    return idx/2;
}

int GetLChild(int idx){
    return idx*2;
}

int GetRChild(int idx){
    return idx*2+1;
}

int GetHighPriorityChild(Heap *pheap, int idx){
    if(GetLChild(idx)>pheap.num) return 0;
    else if(GetLChild(idx)==pheap.num) return GetLChild(idx);
    else{
        if(pheap.items[GetLChild(idx)].priority>pheap.items[GetRChild(idx)].priority){
            return GetLChild(idx);
        }
        else return GetRChild(idx);
    }
}

