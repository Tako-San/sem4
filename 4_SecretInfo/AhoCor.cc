#include "AhoCor.hh"

namespace AC
{

Automaton::TrieNode::TrieNode(TrieNode *fail /*= nullptr*/) : fail_(fail), term_(nullptr), out(-1)
{
}

Automaton::TrieNode::~TrieNode()
{
  for (auto &tn : links_)
    delete tn.second;
}

Automaton::TrieNode *Automaton::TrieNode::get_link(char c) const
{
  auto found_it = links_.find(c);

  if (found_it == links_.cend())
    return nullptr;

  return found_it->second;
}

bool Automaton::TrieNode::is_term() const
{
  return (out >= 0);
}

void Automaton::add_str(const std::string &str)
{
  auto cur_node = &root_;
  for (auto c : str)
  {
    auto child_node = cur_node->get_link(c);
    if (!child_node)
    {
      child_node = new TrieNode(&root_);
      cur_node->links_[c] = child_node;
    }
    cur_node = child_node;
  }
  cur_node->out = words_.size();
  words_.push_back(str);

  init();
}

void Automaton::init()
{
  std::queue<TrieNode *> q;
  q.push(&root_);

  while (!q.empty())
  {
    auto cur_node = q.front();
    q.pop();

    for (auto &cur_link : cur_node->links_)
    {
      auto symbol = cur_link.first;
      auto child = cur_link.second;

      // Defining .fail for the childnode
      auto temp_node = cur_node->fail_;
      while (temp_node != nullptr)
      {
        auto fail_candidate = temp_node->get_link(symbol);
        if (fail_candidate != nullptr)
        {
          child->fail_ = fail_candidate;
          break;
        }
        temp_node = temp_node->fail_;
      }

      // Defining .term_ for the childnode using .term_ of current node
      if (child->fail_->is_term())
        child->term_ = child->fail_;
      else
        child->term_ = child->fail_->term_;
      q.push(child);
    }
  }
}

void Automaton::step(char c)
{
  while (cur_state_ != nullptr)
  {
    auto candidate = cur_state_->get_link(c);
    if (candidate != nullptr)
    {
      cur_state_ = candidate;
      return;
    }
    cur_state_ = cur_state_->fail_;
  }
  cur_state_ = &root_;
}

void Automaton::print_if_term() const
{
  if (cur_state_->is_term())
    print_msg(words_[cur_state_->out].c_str());

  auto temp_node = cur_state_->term_;
  while (temp_node)
  {
    print_msg(words_[temp_node->out].c_str());
    temp_node = temp_node->term_;
  }
}

void Automaton::search(const std::string &str)
{
  cur_state_ = &root_;

  for (auto c : str)
  {
    // cout << c << ':' << endl;
    step(c);
    print_if_term();
  }
}

void Automaton::print_msg(const std::string &str)
{
  std::cout << "found substring " << str << "\n";
}

} // namespace AC