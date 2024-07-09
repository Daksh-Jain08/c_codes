#include <bits/stdc++.h>
#include <cstring>
using namespace std;

// Given a string, write a function to replace all spaces in a sting with '%20'.
// It is given that the string has sufficient space at the end to hold the
// additional characters.

void replace_space(char *s) {
  int space_count = 0;
  for (int i = 0; s[i] != '\0'; i++) {
    if (s[i] == ' ')
      space_count++;
  }

  int index = strlen(s) + 2 * space_count;
  s[index] = '\0';

  int i = strlen(s);
  while (space_count != 0) {
    int index = i + space_count * 2;

    if (s[i] != ' ') {
      s[index] = s[i];
    } else {
      s[index - 2] = '%';
      s[index - 1] = '2';
      s[index] = '0';
      space_count--;
    }
    i--;
  }

  return;
}

int main() {
  char s[1000];
  cin.getline(s,1000);
  cout << s << endl;
  replace_space(s);
  cout << s << endl;
  return 0;
}
