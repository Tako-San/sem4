#include <map>
#include <queue>
#include <string>
#include <vector>

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Automaton
{
  struct TrieNode;
  using LinksMap = std::map<const char, TrieNode *>;

  struct TrieNode
  {
    LinksMap links_;
    TrieNode *fail_;
    TrieNode *term_;
    int out;

    TrieNode(TrieNode *fail = nullptr);
    ~TrieNode();

    TrieNode *get_link(char c) const;
    bool is_term() const;
  };

private:
  typedef void (*Callback)(const char *substr);
  TrieNode root_;
  TrieNode *cur_state_;
  std::vector<std::string> words_;

public:
  void add_str(const std::string &str);
  void init();
  void step(char c);
  void print_if_term() const;
  void search(const std::string &str);
  static void print_msg(const std::string &str);
};
