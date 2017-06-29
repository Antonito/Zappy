#include "zappy_ai_stdafx.hpp"

namespace ai
{
  SetState::SetState()
  {
  }

  SetState::~SetState()
  {
  }

  void SetState::readState(std::queue<std::string> &readQueue)
  {
    if (readQueue.empty())
      return ;
    std::string res = readQueue.front();
    if (res != "ok\n")
    {
      nope::log::Log(Debug) << "(WARNING) Set Failed !";
    }
    readQueue.pop();
  }

  void SetState::writeState(std::queue<std::string> &writeQueue)
  {
    std::string tmp = "Set " + m_object + "\n";
    writeQueue.push(tmp);
  }

  void SetState::reset(Value value)
  {
  }

  Value SetState::getResponse() const
  {
  }

  void SetState::setObject(std::string const &str)
  {
    m_object = str;
  }
}
