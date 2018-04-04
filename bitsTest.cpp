#include <bits/stdc++.h>
using namespace std;

#define M 32

int main()
{
  bitset<M> bset1;
  bitset<M> bset2(20);
  bitset<M> bset3(string("1100"));

  cout<< bset3 << endl;

  bitset<8> bset4;
  bset4[1] = 1;
  bset4[4] = bset4[1];
  cout<< bset4 <<endl;

  int numberof1 = bset4.count();
  cout<< numberof1 <<endl;

  int numberof0 = bset4.size()-bset4.count();
  cout<< "Unset bits = " << numberof0 <<endl;

  cout<< "bool representation of "<< bset4 << ":";
  int i = 0;
  for (i = 0; i < bset4.size(); i++){
    cout << bset4.test(i) << " ";
  }
  cout << endl;

  if (bset4.any()){
    cout << "bset4 has at least one bit set" << endl;
  }

  if (bset1.none()){
    cout << "bset1 has no bits set" << endl;
  }

  int num = 50;
  cout << "Decimal number: " << num << endl;
  cout << "Binary equivalent: " << bitset<8>(num) <<endl;

  bitset<4> b1(9);
  bitset<4> b2(3);

  cout << b1 <<"\t" << b2 <<endl;

  cout << (b1 != b2) <<endl;

  cout << (~b1) <<endl;
  return 0;
}
