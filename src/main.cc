#include <iostream>
#include <string>
#include <sstream>

std::string to_string(int x);

std::string make_table(int &from_what, int &to_what);

int main(void)
{
  setlocale(LC_ALL, "Turkish");

  std::ostringstream temp;
  int to_what, from_what;
  
  std::cout << "(First is begin of multiplication, second is stop point of multiplications.)\n";
  std::cout << "Please give three number to create multiplication table: ";
  std::cin >> from_what >> to_what;

  std::string table = make_table(from_what, to_what, &temp);

  std::cout << table << "\n";
  std::cout << "table created 1 to " << to_what << ".\n";
  return 0;
}

std::string make_table(int &from_what, int &to_what, std::ostringstream &temp)
{
  std::string result;

  for (int i = from_what; i <= to_what; i++)
  {
    for (int j = 0; j <= 10; j++)
    {
      temp << i << " x " << j << " = " << i*j;
    }
  }

  result = temp.str();
  free(&temp);
  return result;
}