#include "zappy_ai_stdafx.hpp"

namespace ai
{
  LookState::LookState() : m_value(Value::NO)
  {
  }

  LookState::~LookState()
  {
  }

  void LookState::readState(std::queue<std::string> &readQueue)
  {
    nope::log::Log(Debug) << "Look[READ]BasicState";
    if (readQueue.empty())
    {
      return ;
    }
    std::string iss = readQueue.front();
    readQueue.pop();
    if (iss == "ko\n")
    {
      nope::log::Log(Debug) << "(WARNING) Write Failed !";
      m_value = Value::NO;
    }

    m_cases.clear();
    std::string res(iss);
    std::cout << res << std::endl;
    std::replace(res.begin(), res.end(), '[', ',');
    std::replace(res.begin(), res.end(), ']', ',');
    std::stringstream ss;
    ss << res;
    std::string toto;
    std::istringstream split(res);
    std::vector<std::string> tokens;
    std::vector<std::map<std::string, std::int32_t> > cases;
    for (std::string each; std::getline(split, each, ','); tokens.push_back(each));
    for (std::size_t i = 0; i < tokens.size(); ++i)
    {
      if (i == 0)
        continue;
      std::map<std::string, std::int32_t> mapTemp;
      mapTemp["player"] = 0;
      mapTemp["food"] = 0;
      mapTemp["linemate"] = 0;
      mapTemp["deraumere"] = 0;
      mapTemp["sibur"] = 0;
      mapTemp["mendiane"] = 0;
      mapTemp["phiras"] = 0;
      mapTemp["thystame"] = 0;
      std::stringstream iss(tokens[i]);
      std::string resource;
      while (iss >> resource)
      {
        mapTemp[resource] += 1;
      }
      m_cases.push_back(std::move(mapTemp));
    }
    m_value = Value::YES;
  }

  void LookState::writeState(std::queue<std::string> &writeQueue)
  {
    nope::log::Log(Debug) << "Look[WRITE]BasicState";
    std::string tmp = "Look\n";
    writeQueue.push(tmp);
  }

  void LookState::reset(Value value)
  {
    m_value = value;
  }

  Value LookState::getResponse() const
  {
    return (m_value);
  }
}


//TODO remove
//[ player mendiane mendiane,, food, food food linemate phiras
