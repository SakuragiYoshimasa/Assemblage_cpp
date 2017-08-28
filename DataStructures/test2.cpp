#include<vector>
#include<iostream>
#include<string>
using namespace std;


int main(){

  int N, K, M;
  cin >> N >> K >> M;

  for(int i = 0; i < N; i++){
    string input;
    cin >> input;

    if( i / K == M - 1){
      cout << input << endl;
    }
  }

  return 0;
}
