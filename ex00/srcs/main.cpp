#include "Bureaucrat.hpp"

int main(void) {
  try {
    Bureaucrat* taro = new Bureaucrat("taro", 151);
    delete taro;
  } catch (std::exception& e) {
    std::cerr << e.what();
  }
}
