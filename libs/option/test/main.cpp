#include <iostream>
#include "OptionParser.hpp"

int main(int ac, char **av)
{
  nope::option::OptionParser opt;

  opt.setOptionName("-a", "--all", true);
  opt.setOptionName("-f", "--file");
  opt.setOptionName("-o", "--out", "outputFile");

  try
    {
      opt.parse(ac, av);

      bool all = opt.isEnabled("-a");
      std::string file = opt.getArg("-f");
      std::string out = opt.getArg("-o");

      std::cout << "-a " << all << '\n';
      std::cout << "-f " << file << '\n';
      std::cout << "-o " << out << '\n';
    }
  catch (std::exception const &e)
    {
      std::cerr << e.what() << std::endl;
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}