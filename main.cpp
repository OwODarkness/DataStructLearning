#include <iostream>
#include "LinkList/LinkList.h"
int main(void)
{
  linklist::LinkList L = nullptr;
  linklist::Init(L);
  linklist::HeadInsert(L, 2);
  linklist::HeadInsert(L, 3);
  linklist::HeadInsert(L, 4);
  linklist::TailInsert(L, 4);
  linklist::SetElement(L, 1, 9);
  std::cout << L << std::endl;
  return 0;
}