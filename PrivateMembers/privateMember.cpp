#include <iostream>
#include <string>

class A{
  public:
  explicit A():_index{0}, _data{0} {}
  explicit A(int index, std::string data): _index{index}, _data {data} {}
  explicit A(const A &rhs):_index{rhs._index}, _data{rhs._data} {}

  void display(){
    std::cout << "Index: " << _index << "\n";
    std::cout << "Data: " << _data << "\n";
  }

  private:
  int _index;
  std::string _data;
};


int main(){
  A first{10, "Aron"};
  A second{first};

  first.display();
  second.display();

  return 0;
}