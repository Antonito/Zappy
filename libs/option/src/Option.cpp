#include "option_stdafx.hpp"

namespace nope
{
  namespace option
  {
    Option::Option(Option const &that)
        : m_shortName(that.m_shortName), m_fullName(that.m_fullName),
          m_value(that.m_value), m_hasValue(that.m_hasValue),
          m_isEnabled(that.m_isEnabled), m_isEnableOnly(that.m_isEnableOnly)
    {
    }

    Option::Option(Option &&that)
        : m_shortName(std::move(that.m_shortName)),
          m_fullName(std::move(that.m_fullName)),
          m_value(std::move(that.m_value)),
          m_hasValue(std::move(that.m_hasValue)),
          m_isEnabled(std::move(that.m_isEnabled)),
          m_isEnableOnly(std::move(that.m_isEnableOnly))
    {
    }

    Option::Option(std::string const &shortName, std::string const &fullName,
                   bool isEnableOnly)
        : m_shortName(shortName), m_fullName(fullName), m_value(""),
          m_hasValue(false), m_isEnabled(false), m_isEnableOnly(isEnableOnly)
    {
    }

    Option::Option(std::string const &shortName, std::string const &fullName,
                   const char *defaultValue)
        : m_shortName(shortName), m_fullName(fullName), m_value(std::string(defaultValue)),
          m_hasValue(true), m_isEnabled(false), m_isEnableOnly(false)
    {
    }

    Option::Option(std::string const &shortName, std::string const &fullName,
                   std::string const &defaultValue)
        : m_shortName(shortName), m_fullName(fullName), m_value(defaultValue),
          m_hasValue(true), m_isEnabled(false), m_isEnableOnly(false)
    {
    }

    Option::~Option()
    {
    }

    Option &Option::operator=(Option const &that)
    {
      if (this == &that)
	return (*this);
      m_shortName = that.m_shortName;
      m_fullName = that.m_fullName;
      m_value = that.m_value;
      m_hasValue = that.m_hasValue;
      m_isEnabled = that.m_isEnabled;
      m_isEnableOnly = that.m_isEnableOnly;
      return (*this);
    }

    Option &Option::operator=(Option &&that)
    {
      if (this == &that)
	return (*this);
      m_shortName = std::move(that.m_shortName);
      m_fullName = std::move(that.m_fullName);
      m_value = std::move(that.m_value);
      m_hasValue = std::move(that.m_hasValue);
      m_isEnabled = std::move(that.m_isEnabled);
      m_isEnableOnly = std::move(that.m_isEnableOnly);
      return (*this);
    }

    void Option::setValue(std::string const &value)
    {
      m_value = value;
      if (!m_hasValue)
	{
	  m_hasValue = true;
	}
      if (!m_isEnabled)
	{
	  m_isEnabled = true;
	}
    }

    std::string const &Option::getValue() const
    {
      if (!m_hasValue)
	{
	  throw OptionException(std::string("The option ") + m_shortName +
	                        " (or " + m_fullName + ") has no value");
	}
      return (m_value);
    }

    std::string const &Option::shortName() const
    {
      return (m_shortName);
    }

    std::string const &Option::fullName() const
    {
      return (m_fullName);
    }

    void Option::enable()
    {
      m_isEnabled = true;
    }

    bool Option::isEnabled() const
    {
      return (m_isEnabled);
    }

    bool Option::isEnableOnly() const
    {
      return (m_isEnableOnly);
    }

    void Option::enableOnly(bool isEnableOnly)
    {
      m_isEnableOnly = isEnableOnly;
    }
  }
}
