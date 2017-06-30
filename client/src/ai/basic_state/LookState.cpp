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
    std::string iss = readQueue.front();
    readQueue.pop();
    if (iss == "ko\n")
    {
      nope::log::Log(Debug) << "(WARNING) Right Failed !";
    }

    std::stringstream ss;
    std::string trash;
    ss << iss;

    std::string res;

    while (res != "]")
    {
      if (res == ",")
      {
      }
      ss >> res;
    }
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


//TODO remove
//[ player mendiane mendiane,, food, food food linemate phiras
