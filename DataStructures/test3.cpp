#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;

int main(){

  unordered_set<int> rooms;

  int N;
  short M;
  cin >> N >> M;

  int a, b;
  short i;
  for(i = 1; i <= M; i++){
    int a, b;
    cin >> a >> b;
    for(int j = a; j <= b; j++){
      rooms.insert(j);
    }
  }//M * N

  int c, d;
  short Q;

  bool flag = false; // false is can use
  cin >> Q;
  for(int i = 1; i <= Q; i++){

    cin >> c >> d;
    flag = false;
    for(int j = c; j <= d; j++){
      if(rooms.find(j) != rooms.end()){
        flag = true;
        break;
      }
    }//Q * N

    if(flag){
      cout << "NG" << endl;
    }else{
      cout << "OK" << endl;
      for(int j = c; j <= d; j++){
        rooms.insert(j);
      }
    }//N
  }

  //O((M + Q) * N) about O(N * sqrt(N))

  return 0;
}
