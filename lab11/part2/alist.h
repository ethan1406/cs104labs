#ifndef ALIST_H
#define ALIST_H
#include <string>


class OutOfBounds : public std::exception {
  private:
    int index;
  public:
    OutOfBounds(int i) {
      index = i;
    }
    std::string what() {
      std::string message = "OutOfBounds:"
      "There is no index " +
        std::to_string(index);
      return message;
    }
};




class AList {
 public:
  AList();
  ~AList();

  /**
   * Returns the current number of items in the list 
   */
  int size() const;
  
  /**
   * Returns true if the list is empty, false otherwise
   */
  bool empty() const;

  /**
   * Inserts val so it appears at index, pos
   */
  void insert (const std::string val);

  /**
   * Returns the value at index, pos
   */
  std::string& get (int position) ;
  
 private:
  /**
   * Should double the size of the list maintaining its contents
   */
  void resize(); 
  int _size;
  int _cap;
  std::string* _data;
  
  
};

#endif
