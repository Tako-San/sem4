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

  void add_str_noinit(const std::string &str);
  void init();

public:
  void add_str(const std::string &str);
  void add_from_file(const fs::path &p);
  void step(char c);
  void print_if_term() const;
  void search(const std::string &str);
  static void print_msg(const std::string &str);
};
} // namespace AC
