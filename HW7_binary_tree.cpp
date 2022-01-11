#include <iostream>
#include <queue>
using namespace std;

struct node
{
  node *leftchild;
  node *rightchild;
  int value;
  int level;
};

int main()
{
  int height = 1;
  int leavesNum = 0;
  int templeft, tempright, tempvalue;
  queue<node *> leaves;

  if (cin >> tempvalue) //若有則讀入第一個值
  {
    node *root = new node{NULL, NULL, tempvalue, 1};
    leaves.push(root);
  }
  else //若無，則空樹
  {
    cout << "Tree is empty" << endl;
    return 0;
  }

  do //讀入
  {
    cin >> templeft;
    cin >> tempright;

    while (leaves.front()->value != tempvalue) //queue存放所有葉子，檢查新增的點是否為葉子，若否則結束
    {
      leaves.pop();
      leavesNum++; //若被pop掉則代表沒有child，為leaf
      if (leaves.empty())
      {
        cout << "Invalid tree" << endl;
        return 0;
      }
    }
    if (templeft != 0)
    {
      node *newnode = new node{NULL, NULL, templeft, leaves.front()->level + 1};
      height = newnode->level;
      leaves.push(newnode);
      leaves.front()->leftchild = newnode;
    }

    if (tempright != 0)
    {
      node *newnode = new node{NULL, NULL, tempright, leaves.front()->level + 1};
      height = newnode->level;
      leaves.push(newnode);
      leaves.front()->rightchild = newnode;
    }
    leaves.pop();
  } while (cin >> tempvalue);

  leavesNum += leaves.size();
  cout << height << endl;
  cout << leavesNum << endl;

  return 0;
}