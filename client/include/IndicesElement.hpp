#ifndef ZAPPY_INDICESELEMENT_HPP_
#define ZAPPY_INDICESELEMENT_HPP_

#include <cstdint>
#include <vector>

namespace zappy
{
  template <typename T, typename IndexType = std::uint32_t>
  struct IndicesElement
  {
    IndicesElement() : elements(), indices()
    {
    }

    IndicesElement(IndicesElement const &that)
        : elements(that.elements), indices(that.indices)
    {
    }

    IndicesElement(IndicesElement &&that)
        : elements(std::move(that.elements)), indices(std::move(that.indices))
    {
    }

    IndicesElement(std::vector<T> const &e, std::vector<IndexType> const &i)
        : elements(e), indices(i)
    {
    }

    IndicesElement(std::vector<T> &&e, std::vector<IndexType> &&i)
        : elements(std::move(e)), indices(std::move(i))
    {
    }

    ~IndicesElement()
    {
    }

    IndicesElement &operator=(IndicesElement const &that)
    {
      if (this == &that)
	return (*this);
      elements = that.elements;
      indices = that.indices;
      return (*this);
    }

    IndicesElement &operator=(IndicesElement &&that)
    {
      if (this == &that)
	return (*this);
      elements = std::move(that.elements);
      indices = std::move(that.indices);
      return (*this);
    }

    std::vector<T>         elements;
    std::vector<IndexType> indices;
  };
}

#endif // !ZAPPY_INDICEELEMENT_HPP_
