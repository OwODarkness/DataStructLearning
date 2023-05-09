/**
 * @file LinkList.h
 * @author your name (you@domain.com)
 * @brief 单链表
 * @version 0.1
 * @date 2023-04-25
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef LINKLIST_H
#define LINKLIST_H

#include <malloc.h>
#include <iostream>
namespace linklist
{
  typedef double ElementType;
  typedef uint32_t INDEX;

  typedef struct Node
  {
    ElementType data;
    struct Node *next;
  } LinkNode, *LinkList;

  //初始化
  void Init(LinkList &L)
  {
    L = (LinkList)malloc(sizeof(LinkNode));
    L->next = nullptr;
  }

  //头插法
  bool HeadInsert(LinkList &L, ElementType e)
  {
    if (L == nullptr)
    {
      return false;
    }
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = e;
    s->next = L->next;
    L->next = s;
    return true;
  }

  //尾插法
  bool TailInsert(LinkList &L, ElementType e)
  {
    if (L == nullptr)
    {
      return false;
    }
    LinkNode *temp = L;
    while (temp->next)
    {
      temp = temp->next;
    }
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = e;
    temp->next = s;
    s->next = nullptr;
    return true;
  }
  //通过头插法创建单链表
  void CreateWithHeadInsert(LinkList L)
  {
    INDEX n = 0;
    std::cout << "please input the number of the original linklist elements" << std::endl;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
      int x;
      std::cin >> x;
      LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
      s->data = x;
      s->next = L->next;
      L->next = s;
    }
  }
  //通过尾插法创建单链表
  void CreateWithTailInsert(LinkList L)
  {
    INDEX n = 0;
    std::cout << "please input the number of the original linklist elements" << std::endl;
    std::cin >> n;
    LinkList p = L;
    for (int i = 0; i < n; i++)
    {
      int x;
      std::cin >> x;
      LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
      s->data = x;
      s->next = p->next;
      p->next = s;
      p = p->next;
    }
  }

  //根据元素获取索引
  bool GetIndexByElement(LinkList L, ElementType Target, INDEX &index)
  {
    LinkNode *s = L->next;
    INDEX count = 0;
    while (s)
    {
      if (s->data = Target)
      {
        index = count;
        return true;
      }
      count++;
      s = s->next;
    }
    return false;
  }
  //根据索引获取元素
  bool GetElementByIndex(LinkList L, INDEX index, ElementType &Target)
  {
    LinkNode *s = L->next;
    INDEX count = 0;
    while (s)
    {
      if (count == index)
      {
        Target = s->data;
        return true;
      }
      s = s->next;
      count++;
    }
    std::cout << "could not find it" << std::endl;
    return false;
  }

  //根据索引获取节点
  bool GetLinkNodeByIndex(LinkList L, INDEX index, LinkNode *&Node)
  {
    LinkNode *s = L->next;
    INDEX count = 0;
    while (s)
    {
      if (count == index)
      {
        Node = s;
        return true;
      }
      s = s->next;
      count++;
    }
    Node = nullptr;
    std::cout << "could not find it" << std::endl;
    return false;
  }

  //设置节点元素值
  bool SetElement(LinkList &L, INDEX index, ElementType Value)
  {
    LinkNode *N = nullptr;
    if (!GetLinkNodeByIndex(L, index, N))
    {
      return false;
    }
    else
    {
      N->data = Value;
      return true;
    }
  }

  //删除节点
  void Delete(LinkList &L, INDEX index)
  {

    LinkNode *pre = L;
    if (!pre)
    {
      return;
    }
    LinkNode *s = L->next;
    INDEX count = 0;
    while (s)
    {
      if (count == index)
      {
        pre->next = s->next;
        free(s);
        return;
      }
      count++;
      s = s->next;
    }
  }
  //单链表转置
  void Reverse(LinkList &L)
  {
    LinkList res = nullptr;
    LinkNode *temp = L->next;
    while (temp)
    {
      LinkNode *n = temp->next;
      temp->next = res;
      res = temp;
      temp = n;
    }
    L->next = res;
  }

  //显示单链表
  void Display(LinkList L)
  {
    if (L == nullptr)
    {
      return;
    }
    LinkNode *temp = L->next;
    while (temp)
    {
      std::cout << temp->data << " ";
      temp = temp->next;
    }
    std::cout << std::endl;
  }
  //单链表长度
  int Length(LinkList L)
  {
    int res = 0;
    LinkNode *T = L->next;
    while (T)
    {
      T = T->next;
      res++;
    }
    return res;
  }

  //单链表合并保持相对有序
  LinkList merge(LinkList L1, LinkList L2)
  {
    LinkList L;
    Init(L);
    LinkNode *Temp = L;
    LinkNode *H1 = L1->next;
    LinkNode *H2 = L2->next;
    while (H1 && H2)
    {
      LinkNode *s;
      s = (LinkNode *)malloc(sizeof(LinkNode));
      if (H1 >= H2)
      {
        s->data = H2->data;
        H2 = H2->next;
      }
      else
      {
        s->data = H1->data;
        H1 = H1->next;
      }
      s->next = Temp->next;
      Temp->next = s->next;
      Temp = s;
    }
    LinkNode *E = H1 == nullptr ? H2 : H1;
    Temp->next = E;
    return L;
  }

  std::ostream &operator<<(std::ostream &out, LinkList L)
  {
    LinkNode *temp = L->next;
    while (temp)
    {
      out << temp->data << " ";
      temp = temp->next;
    }
    return out;
  }
};

#endif