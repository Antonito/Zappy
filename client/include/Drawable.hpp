#ifndef ZAPPY_DRAWBLE_HPP_
#define ZAPPY_DRAWBLE_HPP_

#include "Mesh.hpp"

namespace zappy
{
  class Drawable
  {
  public:
    Drawable();
    Drawable(Drawable const &);
    Drawable(Drawable &&);
    virtual ~Drawable();

    Drawable(Drawable const &);
    Drawable(Drawable &&);

  private:
    Mesh m_mesh;
  };
}

#endif // !ZAPPY_DRAWBLE_HPP_