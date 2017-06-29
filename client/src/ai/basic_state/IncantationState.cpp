#include "zappy_ai_stdafx.hpp"

namespace ai
{
  IncantationState::IncantationState()
  {
  }

  IncantationState::~IncantationState()
  {
  }

  void IncantationState::readState(std::queue<std::string> &readQueue)
  {
    if (readQueue.empty())
      return ;
    std::string res = readQueue.front();
    if (res == "ko\n")
    {
      nope::log::Log(Debug) << "(WARNING) Incantation Failed !";
    }
    readQueue.pop();
  }

  void IncantationState::writeState(std::queue<std::string> &writeQueue)
  {
    std::string tmp = "Incantation\n";
    writeQueue.push(tmp);
  }

  void IncantationState::reset(Value value)
  {
  }

  Value IncantationState::getResponse() const
  {
  }
}
