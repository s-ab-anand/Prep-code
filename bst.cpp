#include <iostream>
#include <fstream>
#include <new>
#include <cstdlib>
#include <string>
#include <sstream>
#include <climits>
#include <vector>
#include <cstring>

using namespace std;

struct binarysearchTree{
  int data;
  int pIndx;
  int leftIndx;
  int rightIndx;
};

void makeNode(struct binarysearchTree *tree, int indx, int num){
  tree[indx].data = num;
  tree[indx].leftIndx = -1; tree[indx].rightIndx = -1; tree[indx].pIndx = -1;
}

void insertElem(struct binarysearchTree *tree, int indx, int num)
{
  if (tree[indx].data >= num){
    if (tree[indx].leftIndx == -1){
      cout << "Inserting in left of "<< indx << "at "<< 2*indx + 1 <<endl;
      tree[indx].leftIndx = 2*indx + 1;
      //cout << tree[indx].leftIndx << endl;
      makeNode(tree, tree[indx].leftIndx, num);
      tree[tree[indx].leftIndx].pIndx = indx;
    } else {
      insertElem(tree, tree[indx].leftIndx, num);
    }
  } else {
    if (tree[indx].rightIndx == -1){
      cout << "Inserting in right of "<< indx << "at "<< 2*indx + 2 <<endl;
      tree[indx].rightIndx = 2*indx + 2;
      //cout << tree[indx].leftIndx << endl;
      makeNode(tree, tree[indx].rightIndx, num);
      tree[tree[indx].rightIndx].pIndx = indx;
    } else {
      insertElem(tree, tree[indx].rightIndx, num);
    }
  }
}

void displayArrInOrder(struct binarysearchTree *tree, int indx)
{
  //cout << tree[indx].leftIndx;
  if (tree[indx].leftIndx != -1){
    displayArrInOrder(tree, tree[indx].leftIndx);
  }
  cout << tree[indx].data << " ";
  if (tree[indx].rightIndx != -1){
    displayArrInOrder(tree, tree[indx].rightIndx);
  }
}

void displayArrPreOrder(struct binarysearchTree *tree, int indx)
{
  cout << tree[indx].data << " ";
  if (tree[indx].leftIndx != -1){
    displayArrPreOrder(tree, tree[indx].leftIndx);
  }
  if (tree[indx].rightIndx != -1){
    displayArrPreOrder(tree, tree[indx].rightIndx);
  }
}

void displayArrPostOrder(struct binarysearchTree *tree, int indx)
{
  if (tree[indx].leftIndx != -1){
    displayArrPostOrder(tree, tree[indx].leftIndx);
  }
  if (tree[indx].rightIndx != -1){
    displayArrPostOrder(tree, tree[indx].rightIndx);
  }
  cout << tree[indx].data << " ";
}

int searchBST(struct binarysearchTree *tree, int indx, int key)
{
  if (tree[indx].data == key){
    return 1;
  } else if (tree[indx].data > key && tree[indx].leftIndx != -1){
    return searchBST(tree, tree[indx].leftIndx, key);
  } else if (tree[indx].data < key && tree[indx].rightIndx != -1){
    return searchBST(tree, tree[indx].rightIndx, key);
  } else {
    return 0;
  }
}

int searchBSTIndx(struct binarysearchTree *tree, int indx, int key)
{
  if (tree[indx].data == key){
    cout << "found" << endl;
    return indx;
  } else if (tree[indx].data > key && tree[indx].leftIndx != -1){
    cout << "looking in left of " << indx << "in indx" << tree[indx].leftIndx<<endl;
    return searchBST(tree, tree[indx].leftIndx, key);
  } else if (tree[indx].data < key && tree[indx].rightIndx != -1){
    cout << "looking in right of " << indx << "in indx" << tree[indx].rightIndx<<endl;
    return searchBST(tree, tree[indx].rightIndx, key);
  } else {
    return -1;
  }
}

int successor (struct binarysearchTree *tree, int indx)
{
  if (indx != -1){
    if (tree[indx].rightIndx == -1){
      int prev = tree[indx].pIndx;
      while (prev != -1 && tree[prev].rightIndx == indx){
        indx = prev; prev = tree[prev].pIndx;
      }
      return tree[prev].data;
    } else {
      int i = tree[indx].rightIndx;
      while (tree[i].leftIndx != -1){
        i = tree[i].leftIndx;
      }
      return tree[i].data;
    }
  }
  return -1;
}

int main(int argc, char* argv[])
{
  int num; string line;
  struct binarysearchTree tree[100];

  //memset(tree, 0, sizeof(tree));
  int start = 0;
  ifstream myfile(argv[1]);
  if (myfile.is_open()){
    while (getline(myfile, line, ',')){
      stringstream obj(line);
      obj >> num;
      if (start == 0){
        makeNode(tree, 0, num);
        displayArrInOrder(tree, 0);
        cout << endl;
        start++;
        //    cout << start;
      } else {
        insertElem(tree, 0, num);
        displayArrInOrder(tree, 0);
        cout << endl;
        //cout << "Inserted "<< num << "at " << start<<endl;
        start++;
      }
    }
  }
  cout << start << endl;
  cout << tree[0].leftIndx << " " << tree[0].rightIndx << endl;
  //cout << "finished creating" << endl;
  displayArrInOrder(tree, 0);
  cout << endl;
  displayArrPreOrder(tree, 0);
  cout << endl;
  //displayArrPostOrder(tree, 0);
  //cout << endl;
  //cout << searchBST(tree, 0, 101) << endl;
  int key = 34;
  int treeIndx = searchBSTIndx(tree, 0, key);
  cout << treeIndx << endl;
  cout << "Successor of node " << key << " is : " << successor(tree, treeIndx)<< endl;

  return 0;
}
