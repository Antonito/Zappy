#ifndef NOPE_OPTIONEXCEPTION_HPP_
#define NOPE_OPTIONEXCEPTION_HPP_

#include <exception>
#include <string>

namespace nope
{
  namespace option
  {
    class OptionException : public std::exception
    {
    public:
      OptionException() noexcept;
      OptionException(std::string const &message) noexcept;
      OptionException(OptionException const &) noexcept;
      OptionException(OptionException &&) noexcept;
      virtual ~OptionException();

      OptionException &operator=(OptionException const &);
      OptionException &operator=(OptionException &&);

      virtual const char *what() const noexcept;

    private:
      std::string m_msg;
    };
  }
}

#endif // !NOPE_OPTIONEXCEPTION_HPP_
