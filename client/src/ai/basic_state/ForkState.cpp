#include "zappy_ai_stdafx.hpp"

namespace ai
{
  ForkState::ForkState()
  {
  }

  ForkState::~ForkState()
  {
  }

  void ForkState::readState(std::queue<std::string> &readQueue)
  {
    if (readQueue.empty())
      return ;
    std::string res = readQueue.front();
    if (res != "ok\n")
    {
      nope::log::Log(Debug) << "(WARNING) Fork Failed !";
    }
    readQueue.pop();
  }

  void ForkState::writeState(std::queue<std::string> &writeQueue)
  {
    std::string tmp = "Fork\n";
    writeQueue.push(tmp);
  }

  void ForkState::reset(Value value)
  {
  }

  Value ForkState::getResponse() const
  {
  }
}
