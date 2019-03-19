/*

 ABOUT THIS FILE
 ---------------

 This code is the implementation (definitions) of all the functions
 listed in utils.h.

 THERE IS NO NEED TO READ ANY OF THIS. If anything is broken,
 you should let me know so I can fix it and publish an update
 for the enter class.

*/

#include "utils.h"
#include <cctype>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define Fail(x) { cerr << x << endl; exit(-1); }

string ConvertToLowercase(string s)
{
  string result = "";
  for (unsigned int i = 0; i < s.length(); i++)
    {
      result += tolower(s[i]);
    }
  return result;
}

string ConvertToString(int iNum)
{
  char buf[100];
  int result = sprintf(buf, "%i", iNum);
  if (result < 0)
    Fail("Could not convert " << iNum << " to a string.");

  return string(buf);
}

string ConvertToString(double dNum)
{
  char buf[100];

  int result = sprintf(buf, "%lf", dNum);
  if (result < 0)
    Fail("Could not convert " << dNum << " to a string.");

  result--;
  while (result > 0 && buf[result] == '0')
    buf[result--] = '\0';

  if (buf[result] == '.')
    buf[result + 1] = '0';
  return string(buf);
}


vector<string> DivideLineIntoWords(string line)
{
  size_t idx;
  vector<string> result;
  while (1)
  {
      idx = line.find(" ");
      if (idx < line.length())
      {
          result.push_back(line.substr(0, idx));
          line = line.substr(idx+1);
      }
      else
      {
          result.push_back(line);
          break;
      }
  }
  return result;
}

string WrappedString(string text, int maxWidth)
{
    string str=text;
    size_t pos = 0;
    size_t last = 0;
    while ((pos = str.find(" ", pos)) != string::npos)
    {
        if ((pos - last) > maxWidth)
        {
            str[pos] = '\n';
            last = pos;
        }
        pos++;
    }
    return str;
}

void UnAbbreviate(string & word)
{
  static string std_abbrevs[14] = { "n", "s", "e", "w", "ne", "nw", "se", "sw", "u", "d", "x", "l", "i", "q" };
  static string std_words[14] = { "north", "south", "east", "west", "northeast", "northwest", "southeast", "southwest", "up", "down", "examine", "look", "inventory", "quit" };

  for (int i = 0; i < 14; i++)
  {
    if (word == std_abbrevs[i])
    {
      word = std_words[i];
      return;
    }
  }
}
