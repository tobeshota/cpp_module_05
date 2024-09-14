#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <sstream>
#define DEFAULT_NAME "default"
#define DEFAULT_GRADE 150
#define HIGHEST_POSSIBLE_GRADE 1
#define LOWEST_POSSIBLE_GRADE 150
#define GradeTooHighExceptionMSG "Grade Too High\n"
#define GradeTooLowExceptionMSG "Grade Too Low\n"

class Bureaucrat {
 private:
  const std::string _name;
  int _grade;

 public:
  Bureaucrat();
  Bureaucrat(const std::string name, int grade);
  Bureaucrat(const Bureaucrat& other);
  Bureaucrat& operator=(const Bureaucrat& other);
  ~Bureaucrat();
  const std::string getName() const;
  int getGrade() const;
  void setGradeSafely(int grade);
  void incrementGrade(void);
  void decrementGrade(void);

  // Execption
  class GradeTooHighException : public std::exception {
    /** exceptionクラスのwhat()をオーバーライドした
     * @brief
     * virtual: このメソッドは仮想関数であり、派生クラス(今回の例では
     * GradeTooHighException)でオーバーライド可能。 const char*:
     * 変更できない文字列（エラーメッセージ）へのポインタを返す。 const:
     * このメソッドはオブジェクトの状態を変更しない。 throw():
     * このメソッドは例外を投げないことを宣言（ただし、C++11以降ではnoexceptの使用が推奨される）。
     */
   public:
    virtual const char* what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
};

std::ostream& operator<<(std::ostream& os, Bureaucrat* b);
std::string intToString(const int num);

#endif
