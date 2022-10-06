#include <stdio.h>;
#include <stdlib.h>;

typedef struct node{
    int data;
    struct node *next;
}node;

node *init_list(node *L){//做个有头结点的
    L=(node*)malloc(sizeof(node));
    if(L==NULL)
        return 0;
    L->next=NULL;
    return 1;
}

//1.将两个非递减的有序链表合为一个非递减的有序链表。（要求利用原来两个链表的存储空间，不另外占用其他空间，表中不允许有重复数据）
node *merge_nondecreasing(node *L1, node *L2){
    node *p1, *p2, *p, *L3;
    p1 = L1->next;
    p2 = L2->next;
    p->next = NULL; //p指当前结点
    L3 = p;
    while(p1!=NULL && p2!=NULL){
        if(p1->data < p2->data){
            p->next = p1;
            p1 = p1->next;
            p = p->next;
        }else if(p1->data > p2->data){
            p->next = p2;
            p2 = p2->next;
            p = p->next;
        }else{ //相同则跳过p2
            p->next = p1;
            p2 = p2->next;
        }
    }
    return L3;
}

//2.将两个非递减的有序链表合并为一个非递增的有序链表。（要求同上）
node *merge_nonincremental(node *L1, node *L2){
    node *p1, *p2, *p, *L3;
    p1 = L1->next;
    p2 = L2->next;
    p->next = NULL;
    L3 = p;
    while(p1!=NULL || p2!=NULL){
        if(p1->data < p2->data){
            p = p1;
            p1 = p1->next;
        }else if(p1->data > p2->data){
            p = p2;
            p2 = p2->next;
        }else if(p1==NULL){ //L1空了就倒置L2
            p = p2;
            p2 = p2->next;
        }else if(p2==NULL){
            p = p1;
            p1 = p1->next;
        }else{
            p1 = p1->next;
        }
        p->next = L3->next;
        L3->next = p; //参考建表的头插法写法
    }
    L3->next = p;
    return L3;
}

//3.设计算法，通过一趟遍历确定单链表中值最大的结点。
int max_node(node *L){
    if(L->next==NULL)
        return NULL;
    node *max, *p;//p指向遍历到的当前结点
    max=L->next;
    p=max;
    while(p!=NULL){
        if(max->data < p->data)
            max=p;
        p=p->next;
    }
    return max->data;
}

//4.设计算法，通过遍历一趟，将链表中所有结点的链接方向逆转（使用原表存储空间）
void inverse_list(node *L){
    node *p, *q; //p指当前结点，q指下一个
    p=L->next;
    L->next=NULL;
    while(p!=NULL){
        q=p->next;
        p->next=L->next; //p倒转到上一个结点
        L->next=p; //L指向上一个
        p=q; //下一个
    }
}

//5.设计一个算法，删除递增有序链表中值大于min(i)且小于max(k)的所有元素（i和k是给定的两个参数，其值可以和表中的元素相同，也可以不同）
void delete_rank(node *L, int i, int k){
    node *p=L->next, *pre, *del;
    while(p!=NULL && p->data <= i){//找到小于等于i的结点
        pre=p;
        p=p->next;
    }
    while(p!=NULL && p->data < k){//遍历删掉k之前的结点
        del=p;
        p=p->next;
        free(del);
    }
    pre->next=p;//连上表
}