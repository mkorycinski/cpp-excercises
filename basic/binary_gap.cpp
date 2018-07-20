#include <iostream>
#include <bitset>

using namespace std;

string strip_string(string str){
    int index = 0;
    for (unsigned int i=0; i<str.length();i++ ){
      if (str[i] == '1'){
          index = i;
          break;
      };
    };
    return str.substr(index);
}

int solution(int N){
  bitset<32> binary_rep(N);
  string binary_rep_str = binary_rep.to_string();

  string z = strip_string(binary_rep_str);
  int longest_gap = 0;
  int curr_gap = 0;

  for (unsigned int i=0;i<z.length();i++){
    if (z[i] == '0'){
      curr_gap += 1;
    } else {
      if (curr_gap > longest_gap){
        longest_gap = curr_gap;
      };
      curr_gap = 0;
    };
  };
  return longest_gap;
}

int main(int argc, char** argv){
  // string::size_type sz;
  // int N = stoi(argv[0])
  int longest_gap = solution(stoi(argv[1]));
  cout << "Longest gap is: " << longest_gap << endl;
  return 0;
}
