#include <stdio.h>
typedef int ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node;

typedef struct Node *LinkList;
int main()
{
    LinkList L;
    int i,x;
    char ch1, ch2, a;
    ch1 = 'y';
    while (ch1 == 'y' || ch1 == 'Y')
    {
        Menu();
        scanf("%c", &ch2);
        switch (ch2)
        {
        case '1':
            CreateHead(&L, 10);
            Print(L);
            break;
        case '2':
            printf("请输入要插入的元素的位置:");
            scanf("%d",&i);
            printf("请输入要插入的元素");
            scanf("%d",&x);
            if (Insert(&L,i,x))
            {
                printf("插入成功");
            }
            
            break;
        case '3':
            printf("请输入要删除的序号：\n");
            scanf("%d",&i);
            if (Delete(&L, i, &x))
            {
                printf("删除成功,该值为：%d", x);
            }

            break;
        case '4':
            printf("请输入要查找的序号：");
            scanf("%d",&i);
            if (GetElem(L,i,&x))
            {
               printf("您查找序号为%d的元素值为%d",i,x);
            }
            else
            {
                printf("请输入正确的序号");
            }
            
            break;
        case '5':
            printf("请输入要找的元素：");
            scanf("%d",&x);
            i = LocateElem(L,x);
            if (i)
            {
                printf("您查找元素的位置为%d",i);
            }
            else
            {
                printf("您要查找的元素不存在！");
            }
            
            break;
        case '6':
            printf("链表的长度为: %d", Length(L));
            break;
        case '7':
            Print(L);
            break;
        case '0':
            ch1 = 'n';
            break;
        default:
            // printf("输入有误，请输入0-8进行选择!");
            break;
        }
        if (ch2 != '0')
        {
            printf("\n按回车键继续，按任意键返回主菜单！\n");
            a = getchar();
            if (a != '\xA')
            {
                getchar();
                ch1 = 'n';
            }
        }
    }
    return 1;
}
void Menu()
{
    printf("\n=====================================================");
    printf("\n|              欢迎使用线性表的链式存储程序            |");
    printf("\n|              1. 建立链式表                         |");
    printf("\n|              2——头插法插入元素                      |");
    printf("\n|              3——删除元素                            |");
    printf("\n|              4——按位置查找元素                      |");
    printf("\n|              5——按元素值查找其在表中位置             |");
    printf("\n|              6——求链式表的长度                      |");
    printf("\n|              7——打印                               |");
    printf("\n|              0——返回                               |");
    printf("\n======================================================");
    printf("\n请输入菜单号（0-7）:");
}
int Length(LinkList head)
{
    int i = 0;
    LinkList p = head->next;
    while (p)
    {
        i++;
        p = p->next;
    }
    return i;
}

void Print(LinkList head)
{
    LinkList p = head->next;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int GetElem(LinkList head, int i, ElemType *e)
{
    int j;
    LinkList p;
    p = head->next;
    j = 1;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i)
    {
        return 0;
    }
    *e = p->data;
    return 1;
}

int LocateElem(LinkList L, ElemType e)
{
    int i = 0;
    LinkList p = L->next;
    while (p)
    {
        i++;
        if (p->data == e)
        {
            return i;
        }
        p = p->next;
    }
    return 0;
}

int Insert(LinkList *head, int i, ElemType e)
{
    int j;
    LinkList pre, s;
    pre = *head;
    j = 0;
    while (pre && j < i - 1)
    {
        pre = pre->next;
        j++;
    }
    if (!pre || j != i - 1)
    {
        printf("第%d个元素不存在\n",i);
        return 0;
    }
    s = (LinkList)malloc(sizeof(Node));
    s->data = e;
    s->next = pre->next;
    pre->next = s;
    return 1;
}

int Delete(LinkList *head, int i, ElemType *x)
{
    int j;
    LinkList pre, p;
    pre = *head;
    while (pre->next && j < i - 1)
    {
        pre = pre->next;
        j++;
    }
    if (!(pre->next) || j != i - 1)
    {
        printf("第%d个元素不存在\n",i);
        return 0;
    }
    p = pre->next;
    pre->next = p->next;
    *x = p->data;
    free(p);
}

void CreateHead(LinkList *head, int n)
{
    LinkList s;
    int i;
    srand(time(0));
    *head = (LinkList)malloc(sizeof(Node));
    (*head)->next = NULL;
    for (i = 0; i < n; i++)
    {
        s = (LinkList)malloc(sizeof(Node));
        s->data = rand() % 100 + 1;
        s->next = (*head)->next;
        (*head)->next = s;
    }
}

void CreateTail(LinkList *head, int n)
{
    LinkList p, s;
    int i;
    srand(time(0));
    *head = (LinkList)malloc(sizeof(Node));
    p = *head;
    for (i = 0; i < n; i++)
    {
        s = (LinkList)malloc(sizeof(Node));
        s->data = rand() % 100 + 1;
        p->next = s;
        s = p;
    }
    p->next = NULL;
}
