#ifndef NOPE_OPTIONPARSER_HPP_
#define NOPE_OPTIONPARSER_HPP_

#include <string>
#include <vector>

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif // !__clang__

namespace nope
{
  namespace option
  {
    class Option;

    class OptionParser
    {
    public:
      OptionParser();
      OptionParser(OptionParser const &);
      OptionParser(OptionParser &&);
      ~OptionParser();

      OptionParser &operator=(OptionParser const &);
      OptionParser &operator=(OptionParser &&);

      void setOptionName(std::string const &shortName,
                         std::string const &fullName, bool enableOnly = false);
      void setOptionName(std::string const &shortName,
                         std::string const &fullName,
                         const char *defaultValue);
      void setOptionName(std::string const &shortName,
                         std::string const &fullName,
                         std::string const &defaultValue);
      void setHelpOption(std::string const &shortVersion,
                         std::string const &longVersion);

      void parse(int numberOfArgs, char **args);

      bool isHelp() const;

      std::string const &getArg(std::string const &arg) const;

      bool isEnabled(std::string const &opt) const;

    private:
      bool parseShort(std::size_t &index);
      bool parseLong(std::size_t &index);

      std::vector<std::string> m_args;
      std::vector<Option>      m_options;
      std::pair<std::string, std::string> m_help;
      bool m_isHelp;
    };
  }
}

#if defined(__clang__)
#pragma clang diagnostic pop
#endif // !__clang__

#endif // !NOPE_OPTIONPARSER_HPP_
