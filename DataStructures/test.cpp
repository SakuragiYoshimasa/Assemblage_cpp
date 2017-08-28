#include<iostream>
#include<vector>

int main(){

  int N, L;
  std::vector<int> a_set;
  std::cin >> N >> L;

  for(int i = 1; i <= N; i++){
    int input;
    std::cin >> input;
    a_set.push_back(input);
  }

  int max_index = 0;
  int max = 0;

  for(int S = 1; S <= N - L + 1; S++){

    if(S == 1 || max_index < S ){

      max = a_set[S - 1];
      max_index = S - 1;
      for(int i = S; i <= S + L - 2; i++){
        if(max <= a_set[i]){
            max = a_set[i];
            max_index = i;
        }
      }

    }else{
      //conpare with new value
      //int prev_max = a_set[max_index];
      if(max <= a_set[S + L - 2]){
        max_index = S + L - 2;
        max = a_set[S + L - 2];
      }
    }

    std::cout << max << std::endl;
  }

  return 0;
}


int lower = 1, upper = n, mid;
while(lower < upper) {
    mid = lower + (upper - lower) / 2;
    if(!isBadVersion(mid)) lower = mid + 1;   /* Only one call to API */
    else upper = mid;
}
return lower;
