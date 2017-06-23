#include "zappy_ai_stdafx.hpp"

int main(int ac, char **av, char **env)
{
  // Check the env
  if (!env || !*env)
    {
      std::cerr << "Invalid environment" << std::endl;
      return (EXIT_FAILURE);
    }

  // Launch the logger
  try
    {
#if defined(DEBUG)
      nope::log::Logger::start("zappy_ai.log");
#else
      // Disable standard output
      nope::log::Logger::start("zappy_ai.log", false);
#endif // !DEBUG
    }
  catch (std::exception const &e)
    {
      std::cerr << "Fatal error while initializing the logger: " << e.what()
                << std::endl;
      return (EXIT_FAILURE);
    }

  // Create the option parser
  nope::option::OptionParser opt;

  // Parse the options
  try
    {
      opt.parse(ac, av);
    }
  catch (nope::option::OptionException const &e)
    {
      std::cerr << "Invalid option:" << e.what() << std::endl;
      return (EXIT_FAILURE);
    }
  catch (std::exception const &e)
    {
      std::cerr << "Fatal error while parsing options: " << e.what()
                << std::endl;
      return (EXIT_FAILURE);
    }

  // Get the args from the parser
  try
    {
    }
  catch (nope::option::OptionException const &e)
    {
      std::cerr << "Error while getting arguments: " << e.what();
      return (EXIT_FAILURE);
    }
  catch (std::exception const &e)
    {
      std::cerr << "Fatal error: " << e.what();
      return (EXIT_FAILURE);
    }

  // Launch the client
  try
    {
    }
  catch (std::exception const &e)
    {
      std::cerr << "Fatal error: " << e.what() << std::endl;
      return (EXIT_FAILURE);
    }

  return (EXIT_SUCCESS);
}
