#include "zappy_ai_stdafx.hpp"

namespace ai
{
  LookState::LookState()
  {
  }

  LookState::~LookState()
  {
  }

  void LookState::readState(std::queue<std::string> &readQueue)
  {
    if (readQueue.empty())
      return ;
    std::string res = readQueue.front();
    if (res == "ko\n")
    {
      nope::log::Log(Debug) << "(WARNING) Right Failed !";
    }
    readQueue.pop();
  }

  void LookState::writeState(std::queue<std::string> &writeQueue)
  {
    std::string tmp = "Look\n";
    writeQueue.push(tmp);
  }

  void LookState::reset(Value value)
  {
  }

  Value LookState::getResponse() const
  {
  }
}
