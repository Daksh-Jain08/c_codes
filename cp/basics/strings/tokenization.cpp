#include <cstring>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

char *mystrtok(char *str, char delim) {
  static char *input = NULL;
  if (str != NULL)
    input = str;

  if (input == NULL)
    return NULL;

  char *token = new char[strlen(input) + 1];
  int i = 0;
  for (; input[i] != '\0'; i++) {

    if (input[i] != delim) {
      token[i] = input[i];
    } else {
      token[i] = '\0';
      input = input + i + 1;
      return token;
    }
  }
  token[i] = '\0';
  input = NULL;
  return token;
}

int main() {
  // using sstream (string stream)
  string s;
  getline(cin, s);

  // create a string stream object
  stringstream ss(s);

  // string stream supports << and >> operators, so getline(ss, token, ' ')
  // means take input from ss to token till ' '
  string token;
  vector<string> tokens;
  while (getline(ss, token, ' ')) {
    tokens.push_back(token);
  }

  // print all the tokens
  for (string token : tokens) {
    cout << token << ",";
  }
  cout << endl;

  // using the strtoken function
  char input[1000];
  cin.getline(input, 1000);

  // strtok() takes a char* and a delimiter. It returns the first token.
  // even if i call the function multiple times, i am going to get the first
  // token only.
  // cout << strtok(input, " ") << endl;
  // cout << strtok(input, " ") << endl;
  // cout << strtok(input, " ") << endl;
  // cout << endl;

  // to get all the tokens
  // we only pass the string pointer in the first call of the function then we
  // call the function with NULL
  char *token1 = strtok(input, " ");
  while (token1 != NULL) {
    cout << token1 << endl;
    // we make the call with NULL as the string, how does the function know what
    // the previous call's string was? it uses a static varible and keeps the
    // track of the last string passed as an argument
    token1 = strtok(NULL, " ");
  }

  char input1[1000];
  cin.getline(input1, 1000);
  // using own  tokenizer function
  char *token2 = mystrtok(input1, ' ');
  while (token2 != NULL) {
    cout << token2 << endl;
    token2 = mystrtok(NULL, ' ');
  }
  return 0;
}
