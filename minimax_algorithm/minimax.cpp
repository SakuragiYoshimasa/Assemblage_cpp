#include<iostream>
using namespace std;

#ifndef MAX_N
#define MAX_N 15
#endif

int gain[MAX_N + 1];


//チェックした頂点の再利用 実行時間　Time:8.4e-05sec.
int callNGameWithMiniMax(int M, int N){


  //-----------------------
  //initialize
  //-----------------------
  gain[N] = N % 2 == 0 ? 1 : -1; //1カウントずつ想定

  //-----------------------
  //Bottom up
  //-----------------------
  for (int n = N - 1; n >= 0; n--) {

    gain[n] = n % 2 == 0 ? -100 : 100;
    for (int i = 1; i <= M; i++) {
      if (n + i > N) continue;

      int coefficient = 1 - 2 * ((n + i) % 2 != (n + 1) % 2);

      if(n % 2 == 0){ //最大化
        gain[n] = max(gain[n], coefficient * gain[n + i]);
      }else{ //最小化
        gain[n] = min(gain[n], coefficient * gain[n + i]);
      }
    }
  }
  return gain[0];
}

int main(int argc, char const *argv[]) {
  int start = clock();
  int M = 4;
  for (int N = 9; N <= 15; N++) {
    cout << N << ":" << (callNGameWithMiniMax(M, N) > 0 ? "先手必勝" : "後手必勝") << endl;
  }

  int end = clock();    // 終了時間
  cout << "Time:" << (double)(end - start) / CLOCKS_PER_SEC << "sec.\n";

  return 0;
}
