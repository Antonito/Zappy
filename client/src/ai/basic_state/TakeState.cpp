#include "zappy_ai_stdafx.hpp"

namespace ai
{
  TakeState::TakeState()
  {
  }

  TakeState::~TakeState()
  {
  }

  void TakeState::readState(std::queue<std::string> &readQueue)
  {
    if (readQueue.empty())
      return ;
    std::string res = readQueue.front();
    if (res != "ok\n")
    {
      nope::log::Log(Debug) << "(WARNING) Take Failed !";
    }
    readQueue.pop();
  }

  void TakeState::writeState(std::queue<std::string> &writeQueue)
  {
    std::string tmp = "Take " + m_object + "\n";
    writeQueue.push(tmp);
  }

  void TakeState::reset(Value value)
  {
  }

  Value TakeState::getResponse() const
  {
    //TODO set return here and all IState *
    //
    //return (m_value);
  }

  void TakeState::setObject(std::string const &str)
  {
    m_object = str;
  }
}
