#include "zappy_ai_stdafx.hpp"

int main(int ac, char **av, char **env)
{
  //
  // Check the env
  //
  if (!env || !*env)
    {
      std::cerr << "Invalid environment" << std::endl;
      return (EXIT_FAILURE);
    }

  //
  // Launch the logger
  //
  try
    {
#if defined(DEBUG)
      nope::log::Logger::start("zappy_ai.log");
#else
      // Disable standard output
      nope::log::Logger::start("zappy_ai.log", false);
#endif // !DEBUG
      nope::log::Logger::logLevel = nope::log::LogLevel::LOG_INFO;

      nope::log::Log(Info) << "Logger started";
    }
  catch (std::exception const &e)
    {
      std::cerr << "Fatal error while initializing the logger: " << e.what()
                << std::endl;
      return (EXIT_FAILURE);
    }

  //
  // Parse the options
  //

  // Create the option parser
  nope::option::OptionParser opt;

  try
    {
      opt.setOptionName("-p", "--port");
      opt.setOptionName("-n", "--name");
      opt.setOptionName("-h", "--machine", "localhost");
      opt.setOptionName("-help", "--help", true);

      nope::log::Log(Info) << "Parsing the options";

      opt.parse(ac, av);
    }
  catch (nope::option::OptionException const &e)
    {
      nope::log::Log(Error) << "Invalid option:" << e.what() << std::endl;
      return (EXIT_FAILURE);
    }
  catch (std::exception const &e)
    {
      nope::log::Log(Error)
          << "Fatal error while parsing options: " << e.what() << std::endl;
      return (EXIT_FAILURE);
    }

  std::uint16_t port;
  std::string   name;
  std::string   machine;

  // Get the args from the parser
  try
    {
      // Check if it help
      if (opt.isEnabled("-help"))
	{
	  nope::log::Log(Info) << "Displaying the help";
	  std::cout
	      << "USAGE: ./zappy_ai -p port -n name -h machine\n"
	         "\tport\tis the port number\n"
	         "\tname\tis the name of the team\n"
	         "\tmachine\tis the name of the machine; localhost by default"
	      << std::endl;
	  return (EXIT_SUCCESS);
	}

      // Get the string value of the port
      std::string  portStr = opt.getArg("-p");
      std::int32_t portValue = std::stoi(portStr);

      // Check the port value
      if (portStr.length() > 5 || portValue < 0 || portValue > 0xFFFF)
	{
	  nope::log::Log(Error) << "Error: \"" << portStr
	                        << "\" is an invalid port value" << std::endl;
	  return (EXIT_FAILURE);
	}
      port = static_cast<std::int16_t>(portValue);

      name = opt.getArg("-n");
      machine = opt.getArg("-h");
    }
  catch (nope::option::OptionException const &e)
    {
      nope::log::Log(Error)
          << "Error while getting arguments: " << e.what() << std::endl;
      return (EXIT_FAILURE);
    }
  catch (std::exception const &e)
    {
      nope::log::Log(Error) << "Fatal error: " << e.what() << std::endl;
      return (EXIT_FAILURE);
    }

  //
  // Launch the client
  //
  try
    {
      nope::log::Log(Info) << "Launching with the following parameters:";
      nope::log::Log(Info) << "\tport\t" << port;
      nope::log::Log(Info) << "\tname\t" << name;
      nope::log::Log(Info) << "\tmachine\t" << machine;
    }
  catch (std::exception const &e)
    {
      nope::log::Log(Error) << "Fatal error: " << e.what() << std::endl;
      return (EXIT_FAILURE);
    }

  return (EXIT_SUCCESS);
}
