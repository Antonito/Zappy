#ifndef NOPE_OPTION_HPP_
#define NOPE_OPTION_HPP_

#include <string>

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif // !__clang__

namespace nope
{
  namespace option
  {
    class Option
    {
    public:
      Option() = delete;
      Option(Option const &);
      Option(Option &&);
      explicit Option(std::string const &shortName,
                      std::string const &fullName, bool enableOnly);
      explicit Option(std::string const &shortName,
                      std::string const &fullName,
                      const char *defaultValue);
      explicit Option(std::string const &shortName,
                      std::string const &fullName,
                      std::string const &defaultValue);
      ~Option();

      Option &operator=(Option const &);
      Option &operator=(Option &&);

      void setValue(std::string const &value);
      std::string const &getValue() const;

      std::string const &shortName() const;
      std::string const &fullName() const;

      void enable();
      bool isEnabled() const;

      bool isEnableOnly() const;
      void enableOnly(bool isEnableOnly);

    private:
      std::string m_shortName;
      std::string m_fullName;

      // TODO: Replace the value by a std::optionnal<std::string> in
      // c++17
      std::string m_value;
      bool        m_hasValue;

      bool m_isEnabled;
      bool m_isEnableOnly;
    };
  }
}

#if defined(__clang__)
#pragma clang diagnostic pop
#endif // !__clang__

#endif // !NOPE_OPTION_HPP_
