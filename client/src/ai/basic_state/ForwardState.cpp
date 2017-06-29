#include "zappy_ai_stdafx.hpp"

namespace ai
{
  ForwardState::ForwardState()
  {
  }

  ForwardState::~ForwardState()
  {
  }

  void ForwardState::readState(std::queue<std::string> &readQueue)
  {
    if (readQueue.empty())
      return ;
    std::string res = readQueue.front();
    if (res != "ok\n")
    {
      nope::log::Log(Debug) << "(WARNING) Forward Failed !";
    }
    readQueue.pop();
  }

  void ForwardState::writeState(std::queue<std::string> &writeQueue)
  {
    std::string tmp = "Forward\n";
    writeQueue.push(tmp);
  }

  void ForwardState::reset(Value value)
  {
  }

  Value ForwardState::getResponse() const
  {
  }
}
