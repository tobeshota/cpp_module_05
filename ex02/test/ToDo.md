# CPP MODULE 05 EX02 TEST

### BureaucratTest
- [x] Bureaucratが_nameを持つ
- [x] Bureaucratが_gradeを持つ
- [x] Bureaucratが_nameのゲッターgetName()を持つ
- [x] Bureaucratが_gradeのゲッターgetGrade()を持つ
- [x] _gradeが150より大きくなると例外が飛ぶ
- [x] _gradeが1より小さくなると例外が飛ぶ
- [x] _gradeが1~150の範囲内のとき例外が飛ばない
- [x] std::cout << bureaucraft
- [x] BureaucratがsignAForm()を持つ
- [ ] BureaucratがexecuteForm(Form const & form)を持つ．

### AFormTest
- [x] AFormが_nameを持つ
- [x] AFormが_isSignedを持つ
- [x] AFormが_gradeToSignを持つ
- [x] AFormが_gradeToExecを持つ
- [x] AFormが_nameのゲッターgetName()を持つ
- [x] AFormが_isSignedのゲッターgetIsSigned()を持つ
- [x] AFormが_gradeToSignのゲッターgetGradeToSign()を持つ
- [x] AFormが_gradeToExecのゲッターgetGradeToExec()を持つ
- [x] _gradeToSignが150より大きくなると例外が飛ぶ
- [x] _gradeToSignが1より小さくなると例外が飛ぶ
- [x] _gradeToSignが1~150の範囲内のとき例外が飛ばない
- [x] _gradeToExecが150より大きくなると例外が飛ぶ
- [x] _gradeToExecが1より小さくなると例外が飛ぶ
- [x] _gradeToExecが1~150の範囲内のとき例外が飛ばない
- [x] std::cout << form
- [x] AFormがbeSigined()を持つ
- [x] FormをAFormにする
- [x] AFormがvirtual void execute(Bureaucrat const & executor) const = 0 純粋仮想関数を持つ

### ShrubberyCreationFormTest
- [x] AFormクラスを継承するShrubberyCreationFormクラスが存在する
- [x] ShrubberyCreationFormクラスが_targetを持つ
- [x] std::string targetを引数に持つコンストラクタがある
- [x] ShrubberyCreationFormクラスがvoid execute(Bureaucrat const & executor) const仮想関数を持つ
- [x] std::cout << scform

### RobotomyRequestFormTest
- [x] AFormクラスを継承するRobotomyRequestFormクラスが存在する
- [x] std::string targetを引数に持つコンストラクタがある
- [x] RobotomyRequestFormクラスがvoid execute(Bureaucrat const & executor) const仮想関数を持つ
- [ ] std::cout << rrform

### PresidentialPardonFormTest
- [ ] AFormクラスを継承するPresidentialPardonFormクラスが存在する
- [ ] std::string targetを引数に持つコンストラクタがある
- [ ] PresidentialPardonFormクラスがvoid execute(Bureaucrat const & executor) const仮想関数を持つ
- [ ] std::cout << ppform
