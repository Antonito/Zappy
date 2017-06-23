#include "option_stdafx.hpp"

namespace nope
{
  namespace option
  {
    OptionParser::OptionParser()
        : m_args(), m_options()
    {
    }

    OptionParser::OptionParser(OptionParser const &that)
        : m_args(), m_options(that.m_options)
    {
    }

    OptionParser::OptionParser(OptionParser &&that)
        : m_args(), m_options(std::move(that.m_options))
    {
    }

    OptionParser::~OptionParser()
    {
    }

    OptionParser &OptionParser::operator=(OptionParser const &that)
    {
      if (this == &that)
	return (*this);
      m_args = that.m_args;
      m_options = that.m_options;
      return (*this);
    }

    OptionParser &OptionParser::operator=(OptionParser &&that)
    {
      if (this == &that)
	return (*this);
      m_args = std::move(that.m_args);
      m_options = std::move(that.m_options);
      return (*this);
    }

    void OptionParser::setOptionName(std::string const &shortName,
                                     std::string const &fullName,
                                     bool               enableOnly)
    {
      m_options.emplace_back(shortName, fullName, enableOnly);
    }

    void OptionParser::setOptionName(std::string const &shortName,
                                     std::string const &fullName,
                                     const char *       defaultValue)
    {
      m_options.emplace_back(shortName, fullName, defaultValue);
    }

    void OptionParser::setOptionName(std::string const &shortName,
                                     std::string const &fullName,
                                     std::string const &defaultValue)
    {
      m_options.emplace_back(shortName, fullName, defaultValue);
    }

    void OptionParser::parse(int numberOfArgs, char **args)
    {
      if (numberOfArgs < 0)
	{
	  throw OptionException("Invalid number of argument (negative)");
	}

      m_args.resize(static_cast<std::size_t>(numberOfArgs));
      for (std::size_t i = 0; i < static_cast<std::size_t>(numberOfArgs); ++i)
	{
	  if (args[i] == nullptr)
	    {
	      throw OptionException("Null argument");
	    }
	  m_args[i] = args[i];
	}

      if (m_args.size() < 1)
	{
	  throw OptionException("There is no argument");
	}

      std::size_t index = 1;

      while (index < static_cast<std::size_t>(numberOfArgs))
	{
	  if (!parseShort(index) && !parseLong(index))
	    {
	      throw OptionException(std::string("Unknown argument: ") +
	                            m_args[index]);
	    }
	}
    }

    std::string const &OptionParser::getArg(std::string const &arg) const
    {
      for (Option const &opt : m_options)
	{
	  if (opt.shortName() == arg || opt.fullName() == arg)
	    {
	      return (opt.getValue());
	    }
	}
      throw OptionException(std::string("Option '") + arg + "' not found");
    }

    bool OptionParser::isEnabled(std::string const &opt) const
    {
      for (Option const &option : m_options)
	{
	  if (opt == option.shortName() || opt == option.fullName())
	    {
	      return (option.isEnabled());
	    }
	}
      throw OptionException(std::string("Option '") + opt + "' not found");
    }

    bool OptionParser::parseShort(std::size_t &index)
    {
      for (Option &opt : m_options)
	{
	  if (m_args[index] == opt.shortName())
	    {
	      ++index;
	      if (opt.isEnableOnly())
		{
		  opt.enable();
		}
	      else
		{
		  if (static_cast<std::size_t>(index) == m_args.size())
		    {
		      throw OptionException(
		          std::string("Missing argument for option ") +
		          opt.shortName());
		    }
		  opt.setValue(m_args[index]);
		  ++index;
		}
	      return (true);
	    }
	}
      return (false);
    }

    bool OptionParser::parseLong(std::size_t &index)
    {
      for (Option &opt : m_options)
	{
	  std::string const &name = opt.fullName();
	  std::size_t        len = name.length();

	  if (std::strncmp(m_args[index].c_str(), name.c_str(), len) == 0)
	    {
	      if (opt.isEnableOnly())
		{
		  if (m_args[index].length() != len)
		    {
		      continue;
		    }
		  opt.enable();
		  ++index;
		}
	      else
		{
		  if (m_args[index].length() < len + 1 ||
		      m_args[index][len] != '=')
		    {
		      continue;
		    }
		  else if (m_args[index].length() == len + 1)
		    {
		      throw OptionException(
		          std::string("Missing argument for option ") + name);
		    }
		  opt.setValue(m_args[index].substr(len + 1));
		  ++index;
		}
	      return (true);
	    }
	}
      return (false);
    }
  }
}
