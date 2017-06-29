#include "zappy_ai_stdafx.hpp"

namespace ai
{
  LeftState::LeftState()
  {
  }

  LeftState::~LeftState()
  {
  }

  void LeftState::readState(std::queue<std::string> &readQueue)
  {
    if (readQueue.empty())
      return ;
    std::string res = readQueue.front();
    if (res != "ok\n")
    {
      nope::log::Log(Debug) << "(WARNING) Left Failed !";
    }
    readQueue.pop();
  }

  void LeftState::writeState(std::queue<std::string> &writeQueue)
  {
    std::string tmp = "Left\n";
    writeQueue.push(tmp);
  }

  void LeftState::reset(Value value)
  {
  }

  Value LeftState::getResponse() const
  {
  }
}
