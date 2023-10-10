#include <fstream>
#include <iostream>
using namespace std;
enum States //возможные состояния автомата
{
  state_start,
  state_escape_comment,
  state_star_comment,
  state_one_line_comment,
  state_end_line_comment,
  state_string_literal,
  state_char_literal
};

int main() {
  // корректное отображение Кириллицы
  setlocale(LC_ALL, "rus");
  //открыли поток из файла на чтение
  ifstream file("example.c", ios::in);
  if (!file) {
    //если файл не открылся прекращаем работу программы
    cout << "Файл не открыт\n\n";
    return 0;
  }
  cout << "Успешное открытие файла!\n\n";

  char s;
  file.get(s);

  States state = state_start;

  while (!file.eof()) {

    switch (state) {

    case state_start:
      if (s == '/') {
        state = state_escape_comment;
      } else if (s == '"') {
        cout << s;
        state = state_string_literal;
      } else if (s == '\'') {
        cout << s;
        state = state_char_literal;
      } else {
        cout << s;
      }
      break;
    case state_char_literal:
      if (s == '\'') {
        state = state_start;
      }
      cout << s;
      break;
    case state_string_literal:
      if (s == '"') {
        state = state_start;
      }
      cout << s;
      break;
    case state_escape_comment:
      if (s == '*') {
        state = state_star_comment;
      } else if (s == '/') {
        state = state_one_line_comment;
      } else {
        state = state_start;
      }
      break;

    case state_one_line_comment:
      if (s == '\n') {
        state = state_start;
      }
      break;

    case state_star_comment:
      if (s == '/') {
        state = state_escape_comment;
      }
      break;
    }
    file.get(s);
  }
}
