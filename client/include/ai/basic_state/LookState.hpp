#ifndef LOOKSTATE_HPP_
#define LOOKSTATE_HPP_

#include <iostream>
#include <vector>
#include "ai/IState.hpp"

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

namespace ai
{
  class LookState final : public IState
  {
  public:
    LookState();
    LookState(LookState const &) = delete;
    LookState(LookState &&) = delete;
    virtual ~LookState();

    LookState &operator=(LookState const &) = delete;
    LookState &operator=(LookState &&) = delete;

    virtual void readState(std::queue<std::string> &readQueue);
    virtual void writeState(std::queue<std::string> &writeQueue);
    virtual void reset(Value value);
    virtual Value getResponse() const;

    std::pair<std::int32_t, std::int32_t> getDirection(std::int32_t) const;
    std::int32_t findFood() const;
    std::int32_t findStone() const;
    std::int32_t getNbPlayer() const;

    // std::vetor<std::map<std::string, std::int32_t>> &getCases() const;

  private:
    Value m_value;
    std::vector<std::map<std::string, std::int32_t>> m_cases;
  };
}

#if defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif // !LOOKSTATE_HPP_
