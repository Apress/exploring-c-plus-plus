/** @file list5701.cpp */
/** Listing 57-1. Defining the list Class Template */
template<class T>
class list
{
public:
   list()
  : head_(0), tail_(0), size_(0)
  {}
  ~list() { clear(); }

  void clear();               ///< Erase all nodes in the list. Reset size to 0.
  void push_back(T const& x); ///< Add to tail.
  void pop_back();            ///< Erase from tail.
  // Other useful functions omitted for brevity...
private:
  class node
  {
  public:
    node(T const& key)
    : next_(0), prev_(0), value_(key)
    {}
    node* next_;
    node* prev_;
    T     value_;
  };

  node* head_;       ///< Start of the list
  node* tail_;       ///< End of the list
  std::size_t size_; ///< Number of nodes in the list
};
