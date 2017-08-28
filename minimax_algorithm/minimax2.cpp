#include<iostream>
using namespace std;

#ifndef MAX_N
#define MAX_N 15
#endif

int gain[MAX_N + 1];

int miniMax_max(int v, int depth, int M, int N);
int miniMax_min(int v, int depth, int M, int N);

int miniMax_max(int v, int depth, int M, int N){
  if(v == N) return 1 - 2 * (depth % 2);
  int gain = -100;
  for(int i = 1; i <= M; i++){
    if(i + v > N) continue;
    gain = max(gain, miniMax_min(v + i, depth + 1, M, N));
  }
  return gain;
}

int miniMax_min(int v, int depth, int M, int N){
  if(v == N) return 1 - 2 * (depth % 2);
  int gain = 100;
  for(int i = 1; i <= M; i++){
    if(i + v > N) continue;
    gain = min(gain, miniMax_max(v + i, depth + 1, M, N));
  }
  return gain;
}

//実行時間 Time:0.000968sec.
int main(int argc, char const *argv[]) {
  int start = clock();
  int M = 4;
  for (int N = 9; N <= 15; N++) {
    cout << N << ":" << (miniMax_max(0, 0, M, N) > 0 ? "先手必勝" : "後手必勝") << endl;
  }

  int end = clock();    // 終了時間
  cout << "Time:" << (double)(end - start) / CLOCKS_PER_SEC << "sec.\n";

  return 0;
}
