#include <map>
#include <queue>
#include <string>
#include <vector>

#include <filesystem>
#include <fstream>
#include <iostream>

namespace AhoCorasick
{

namespace fs = std::filesystem;

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

  size_t MIN_FILE_LEN{1};

  void init();

public:
  void set_flen(size_t flen);
  void add_str(const std::string &str);
  void add_from_file(const fs::path &p);

  template <typename It> void search(It beg, It end)
  {
    cur_state_ = &root_;

    for (; beg != end; ++beg)
    {
      std::cout << *beg << ':' << std::endl;
      step(*beg);
      print_if_term();
    }
  }

private:
  void step(char c);
  void print_if_term() const;
  static void print_msg(const std::string &str);

  template <typename It> void add_str_noinit(It beg, It end, typename std::iterator_traits<It>::difference_type diff)
  {
    std::vector<TrieNode *> cur_nodes;

    size_t wnum = diff - MIN_FILE_LEN + 1;
    size_t cter = 0; // counter

    size_t counter = 0;
    for (; beg != end; ++beg, ++counter)
    {
      if (cter < wnum)
      {
        cur_nodes.push_back(&root_);
        cter++;
      }

      for (size_t i = 0, end = cur_nodes.size(); i < end; ++i)
      {
        auto child_node = cur_nodes[i]->get_link(*beg);
        if (!child_node)
        {
          child_node = new TrieNode(&root_);
          cur_nodes[i]->links_[*beg] = child_node;
        }
        cur_nodes[i] = child_node;

        if (counter - i + 1 >= MIN_FILE_LEN)
          cur_nodes[i]->out = words_.size();
      }
    }
  }
};
} // namespace AhoCorasick
