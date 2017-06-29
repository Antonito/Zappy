#include "zappy_ai_stdafx.hpp"

namespace ai
{
  MissingPlayerState::MissingPlayerState(
      std::map<BasicState, std::unique_ptr<IState>> &states)
      : AState(states)
  {
  }

  MissingPlayerState::~MissingPlayerState()
  {
  }

  void MissingPlayerState::readState(std::queue<std::string> &readQueue)
  {
  }

  void MissingPlayerState::writeState(std::queue<std::string> &writeQueue)
  {
  }

  void MissingPlayerState::reset(Value value)
  {
  }

  Value MissingPlayerState::getResponse() const
  {
    return (m_curValue);
  }
}
