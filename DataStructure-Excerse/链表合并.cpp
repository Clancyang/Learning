
// 带头结点的链表L1 和L2的合并
// 函数结束后，L1 L2为空链表 
typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Merge( List L1, List L2 )
{
  List P1,P2,head,L;
  head=(List)malloc(sizeof(PtrToNode));
  L=head;
  P1=L1->Next;
  P2=L2->Next;
  while(P1!=NULL&&P2!=NULL) //判断都有的部分
  {
    if(P1->Data < P2->Data)
    {
        L->Next=P1; 
        P1=P1->Next; 
    }
    else
    {
        L->Next=P2; 
        P2=P2->Next; 
    }
    L=L->Next;
  }
  if(P1!=NULL)
  {
        L->Next=P1;
  }
  if(P2!=NULL)
  {
        L->Next=P2;
  }
   L1->Next=NULL;
   L2->Next=NULL;
  return head;

}