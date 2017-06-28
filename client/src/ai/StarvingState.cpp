#include "zappy_ai_stdafx.hpp"

namespace ai
{
  StarvingState::StarvingState(std::map<BasicState, IState *> &states) : AState(states)
  {
    nope::log::Log(Debug) << "Starving State init";
  }

  StarvingState::~StarvingState()
  {
  }

  void StarvingState::readState(std::queue<std::string> &readQueue)
  {
    nope::log::Log(Debug) << "Starving[READ]State";
    //call inventory state
    //or directly read in readQueue
  }

  void StarvingState::writeState(std::queue<std::string> &writeQueue)
  {
    nope::log::Log(Debug) << "Starving[WRITE]State";
    //call inventory state
    //or directly put 'Inventory\n' in writeQueue
  }

  void StarvingState::reset(Value value)
  {
    nope::log::Log(Debug) << "StarvingState reset";
  }

  Value StarvingState::getResponse() const
  {
    return (m_curValue);
  }
}
