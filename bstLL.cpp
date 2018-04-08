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
  struct binarysearchTree *left;
  struct binarysearchTree *right;
  struct binarysearchTree *p;
};

void insertElem(struct binarysearchTree *root, int num)
{
  if (root->data > num){
    if (root->left){
      insertElem(root->left, num);
    } else {
      struct binarysearchTree *newNode = new binarysearchTree();
      newNode->data = num;
      newNode->left = nullptr; newNode->right = nullptr;
      newNode->p = root;
      root->left = newNode;
    }
  } else {
    if (root->right){
      insertElem(root->right, num);
    } else {
      struct binarysearchTree *newNode = new binarysearchTree();
      newNode->data = num;
      newNode->left = nullptr; newNode->right = nullptr;
      newNode->p = root;
      root->right = newNode;
    }
  }
}

void displayArrInOrder(struct binarysearchTree *root)
{
  //cout << tree[indx].leftIndx;
  if (root->left){
    displayArrInOrder(root->left);
  }
  cout << root->data << " ";
  if (root->right){
    displayArrInOrder(root->right);
  }
}

struct binarysearchTree* searchBSTref(struct binarysearchTree *tree, int key)
{
  if (tree->data == key){
    cout << "found" << endl;
    return tree;
  } else if (tree->data > key && tree->left){
    //cout << "looking in left of " << indx << "in indx" << tree[indx].leftIndx<<endl;
    return searchBSTref(tree->left, key);
  } else if (tree->data < key && tree->right){
    //cout << "looking in left of " << indx << "in indx" << tree[indx].leftIndx<<endl;
    return searchBSTref(tree->right, key);
  } else {
    return nullptr;
  }
}

struct binarysearchTree* successor(struct binarysearchTree *node)
{
  //cout << (node->right)->data << endl;
  if (node->right != nullptr){
    node = node->right;
    while (node->left != nullptr){
      node = node->left;
    }
    return node;
  } else {
    struct binarysearchTree *prev = node->p;
    cout << prev->data<<endl;
    while (prev != nullptr && prev->right == node){
      node = prev; prev = prev->p;
      cout<< "tracing back "<<node->data<<endl;
    }
    return prev;
  }
}
int height(binarysearchTree *root){
  if (root->left == 0 && root->right == 0){
    return 1;
  } else {
    if (root->left && root->right){
      return 1 + std::max(height(root->left), height(root->right));
    } else {
      if (root->left)
        return 1 + height(root->left);
      else
        return 1 + height(root->right);
    }
  }
}

int numStree(binarysearchTree *root){
  if (root->left == NULL && root->right == NULL){
    return 1;
  } else if (root->left && !root->right){
    return 1 + numStree(root->left);
  } else if (!root->left && root->right){
    return 1 + numStree(root->right);
  } else {
    return 1 + numStree(root->left) + numStree(root->right);
  }
}

int kSmall(binarysearchTree *root, int k){
  int numLeft = 0;
  if (root->left){
   numLeft = numStree(root->left);
 } else {
   numLeft = 0;
 }
  int rr = numLeft + 1;
  cout << rr << " " << k << endl;
  if (k == rr){
    return root->data;
  }
  if (k > rr){
    root = root->right;

    return kSmall(root, k-rr);
  } else {
    root = root->left;
    if (rr == 2){
      cout<<root->data<<endl;
    }
    return kSmall(root, k);
  }

}
int main(int argc, char* argv[])
{
  int num; string line;
  struct binarysearchTree *root = new binarysearchTree();

  //memset(tree, 0, sizeof(tree));
  int start = 0;
  ifstream myfile(argv[1]);
  if (myfile.is_open()){
    while (getline(myfile, line, ',')){
      stringstream obj(line);
      obj >> num;
      if (start == 0){
        root->data = num; root->left = nullptr; root->right = nullptr;
        root->p = nullptr; start++;
      } else {
        insertElem(root, num);
      }
    }
  }
  cout<<endl;
  displayArrInOrder(root);
  cout<<endl; int key = 99;
  //cout << searchBSTref(root, key)->data << endl;
  int k = 88;
  cout << "successor of "<<key<<" is "<< successor(searchBSTref(root, key))->data << endl;
  cout << "Height = " << height(root) << endl;
  cout<< k << "th smallest value is " << kSmall(root, k) <<endl;
  return 0;
}
