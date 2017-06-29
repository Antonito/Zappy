#include "zappy_ai_stdafx.hpp"

namespace ai
{
  EjectState::EjectState()
  {
  }

  EjectState::~EjectState()
  {
  }

  void EjectState::readState(std::queue<std::string> &readQueue)
  {
    if (readQueue.empty())
      return ;
    std::string res = readQueue.front();
    if (res != "ok\n")
    {
      nope::log::Log(Debug) << "(WARNING) Eject Failed !";
    }
    readQueue.pop();
  }

  void EjectState::writeState(std::queue<std::string> &writeQueue)
  {
    std::string tmp = "Eject\n";
    writeQueue.push(tmp);
  }

  void EjectState::reset(Value value)
  {
  }

  Value EjectState::getResponse() const
  {
  }
}
