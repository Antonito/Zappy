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
    std::string msg = readQueue.front();
    readQueue.pop();
    if (msg == "ko\n")
    {
      nope::log::Log(Debug) << "(WARNING) Write Failed !";
      m_value = Value::NO;
    }

    m_cases.clear();
    std::string res(msg);
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

  std::pair<std::int32_t, std::int32_t> LookState::getDirection(std::int32_t pos) const
  {
    int32_t x = 0, y = 0, mid = 0;

    for (y = 0; pos > mid + y; ++y)
      {
	mid += 2 * y;
      }
    x = pos - mid;
    std::pair<std::int32_t, std::int32_t> res = {x, y};
    return (res);
  }

  std::int32_t LookState::findFood() const
  {
    for (std::size_t i = 0; i < m_cases.size(); ++i)
    {
      if (m_cases[i].at("food") != 0)
        return (static_cast<std::int32_t>(i));
    }
    return (-1);
  }

  std::int32_t LookState::findStone() const
  {
    for (std::size_t i = 0; i < m_cases.size(); ++i)
    {
      //TODO : set correct stone
      if (m_cases[i].at("sibur") != 0)
        return (static_cast<std::int32_t>(i));
    }
    return (-1);
  }
}

