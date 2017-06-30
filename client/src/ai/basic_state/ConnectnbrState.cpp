#include "zappy_ai_stdafx.hpp"

namespace ai
{
  ConnectnbrState::ConnectnbrState()
  {
  }

  ConnectnbrState::~ConnectnbrState()
  {
  }

  void ConnectnbrState::readState(std::queue<std::string> &readQueue)
  {
    nope::log::Log(Debug) << "Connectnbr[READ]BasicState";
    m_value = Value::YES;
  }

  void ConnectnbrState::writeState(std::queue<std::string> &writeQueue)
  {
    nope::log::Log(Debug) << "Connectnbr[WRITE]BasicState";
  }

  void ConnectnbrState::reset(Value value)
  {
    m_value = value;
  }

  Value ConnectnbrState::getResponse() const
  {
    return (m_value);
  }
}
