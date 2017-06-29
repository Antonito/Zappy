#include "zappy_ai_stdafx.hpp"

namespace ai
{
  RightState::RightState()
  {
  }

  RightState::~RightState()
  {
  }

  void RightState::readState(std::queue<std::string> &readQueue)
  {
    if (readQueue.empty())
      return ;
    std::string res = readQueue.front();
    if (res != "ok\n")
    {
      nope::log::Log(Debug) << "(WARNING) Right Failed !";
    }
    readQueue.pop();
  }

  void RightState::writeState(std::queue<std::string> &writeQueue)
  {
    std::string tmp = "Right\n";
    writeQueue.push(tmp);
  }

  void RightState::reset(Value value)
  {
  }

  Value RightState::getResponse() const
  {
  }
}
