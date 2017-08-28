#include<iostream>
char rev(char c){
  if(c=='H'){
    return 'D';
  }else{
    return 'H';
  }
}

int main() {
  char a, b;
  std::cin >> a >> b;

  if(a=='H'){
    std::cout << b;
  }else{
    std::cout << rev(b);
  }

  return 0;
}

#include<iostream>
int main() {
  int W, a, b;
  std::cin >> W >> a >> b;

  int bigger = a >= b ? a : b;
  int smaller = a > b ? b : a;

  if(bigger - (smaller + W) <= 0){
    std::cout << 0;
  }else{
    std::cout << bigger - (smaller + W);
  }
  return 0;
}

#include <iostream>
#include<math.h>

long long fact(long long n){
  if(n==0)return 1;
  return n * fact(n - 1) % 1000000007;
}

int main() {
  long long N;
  std::cin >> N;
  long long power = 1;
  for(long long i = 1; i <= N; i++){
    power = (power * i) % 1000000007;
  }

  std::cout << power;
  return 0;
}



#include <iostream>

int main() {

  long N, M;
  long result;
  std::cin >> N >> M;
  if(N >= M / 2){
    result = M / 2;
  }else{
    result = N + (M - N * 2) / 4;
  }
  std::cout << result;
  return 0;
}

public int removeDuplicates(int[] nums) {
    if (nums.length == 0) return 0;
    int i = 0;
    for (int j = 1; j < nums.length; j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}


#include <unordered_map>

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        std::unordered_map<int, int> removed_duplicate_map;

        for(int i = 0; i < nums.size(); i++){

            if(removed_duplicate_map.find(nums.at(i)) == removed_duplicate_map.end()){
                removed_duplicate_map[nums.at(i)] = nums.at(i);
            }else{
                nums.erase(nums.begin() + i);
                i--;
            }
        }
        return nums.size();
    }
};

#include<unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        std::unordered_map<int, int> umap;
        vector<int> result;
        for(int i = 0; i < numbers.size(); i++){
            if(umap.find(target - numbers[i]) == umap.end()){
                umap[numbers[i]] = i;
            }else{
                result.push_back(umap[target - numbers[i]] + 1);
                result.push_back(i + 1);

                break;
            }
        }
        return result;
    }
};

private static void printFreq(char[] str) {
    Map<Character, Integer> freq = new HashMap<>();
    for (int i = 0; i < str.length; i++) {
        if (freq.containsKey(str[i])) {
            freq.put(str[i], freq.get(str[i]) + 1);
        } else {
            freq.put(str[i], 1);
        }
    }
    for (Map.Entry<Character, Integer> entry : freq.entrySet()) {
        System.out.println("[" + (char)(entry.getKey()) + "] = " + entry.getValue());
    }
}

public static void main(String[] args) {
    char[] str = "◣⚽◢⚡◣⚾⚡◢".toCharArray();
    printFreq(str);
}


#include<unordered_map>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int longest = 0;
        int start_index = 0;
        char last_char;
        std::unordered_map<char, int> umap;

        for(int i = 0; i < s.size(); i++){

            if(umap.find(s[i]) != umap.end() && umap[s[i]] >= start_index){
                start_index = umap[s[i]] + 1; //2
            }else{
                if(i - start_index + 1 > longest){
                    longest = i - start_index + 1;
                }
            }
            umap[s[i]] = i;
        }

        if(longest == 0){
            longest = s.size();
        }

        return longest;
    }
};


#include<math.h>
class Solution {
public:
    int myAtoi(string str) {

        long result = 0;
        int length = str.size();

        std::map<char, int> char_to_int;

        for(int i = 0; i <= 9; i++){
            char_to_int['0' + i] = i;
        }

        //reshape
        string reshaped_str;
        int sgn = 1;
        bool start_int = false;

        for(int i = 0; i < length; i++){
            if(char_to_int.find(str[i]) != char_to_int.end()){
                reshaped_str += str[i];
                start_int = true;
            }else if(!start_int && (str[i] == '+' || str[i] == '-')){
                sgn = str[i] == '+' ? 1 : -1;
                start_int = true;
            }else if(str[i] == ' '){
                if(start_int) break;
            }else{
                break;
            }
        }

        length = reshaped_str.size();
        if(length >= 11){

            if(sgn == 1) result = 2147483647;
            if(sgn == -1) result = 2147483648;

            return result * sgn;
        }

        for(int i = 0; i < length; i++){
            result += char_to_int[reshaped_str[i]] * pow(10, length - i - 1);
        }

        if(result >= 2147483647 && sgn == 1) result = 2147483647;
        if(result >= 2147483648 && sgn == -1) result = 2147483648;

        return result * sgn;
    }
};
