#include "option_stdafx.hpp"

namespace nope
{
  namespace option
  {
    OptionException::OptionException() noexcept : m_msg("")
    {
    }

    OptionException::OptionException(std::string const &msg) noexcept
        : m_msg(msg)
    {
    }

    OptionException::OptionException(OptionException const &that) noexcept
        : m_msg(that.m_msg)
    {
    }

    OptionException::OptionException(OptionException &&that) noexcept
        : m_msg(std::move(that.m_msg))
    {
    }

    OptionException::~OptionException()
    {
    }

    OptionException &OptionException::operator=(OptionException const &that)
    {
      if (this == &that)
	return (*this);
      m_msg = that.m_msg;
      return (*this);
    }

    OptionException &OptionException::operator=(OptionException &&that)
    {
      if (this == &that)
	return (*this);
      m_msg = std::move(that.m_msg);
      return (*this);
    }

    const char *OptionException::what() const noexcept
    {
      return (m_msg.c_str());
    }
  }
}
