#include <fstream>
#include <iostream>
using namespace std;
enum States //возможные состояния автомата
{
  state_start,
  state_slash,
  state_star,
  state_start_end
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
  cout << "Успешное открытоие файла!\n\n";

  char s;
  file.get(s);

  States state = state_start;

  while (s != '$') {
    switch (state) {
    case state_start:
      if (s == '/') {
        state = state_slash;
      } else {
        cout << s;
      }
      break;
    case state_slash:
      if (s == '*') {
        state = state_star;
      } else {
        state = state_start;
      }
      break;
    case state_star:
      if (s == '/') {
        state = state_slash;
      }
      break;
    }
    file.get(s);
  }
}
