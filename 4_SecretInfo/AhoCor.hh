#include <map>
#include <queue>
#include <string>
#include <vector>

#include <filesystem>
#include <fstream>
#include <iostream>

namespace AC // Aho-Corasick
{

namespace fs = std::filesystem;
constexpr size_t MIN_FILE_LEN = 1 /*4*1024*/;

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
  TrieNode root_;
  TrieNode *cur_state_;
  std::vector<std::string> words_;

  void init();

public:
  void add_str(const std::string &str);
  void add_from_file(const fs::path &p);
  void step(char c);
  void print_if_term() const;
  static void print_msg(const std::string &str);

  template <typename It> void search(It beg, It end)
  {
    cur_state_ = &root_;

    for (; beg != end; ++beg)
    {
      // cout << c << ':' << endl;
      step(*beg);
      print_if_term();
    }
  }

private:
  template <typename It> void add_str_noinit(It beg, It end)
  {
    auto cur_node = &root_;

    for (; beg != end; ++beg)
    {
      auto child_node = cur_node->get_link(*beg);
      if (!child_node)
      {
        child_node = new TrieNode(&root_);
        cur_node->links_[*beg] = child_node;
      }
      cur_node = child_node;
    }
    cur_node->out = words_.size();
  }
};
} // namespace AC
