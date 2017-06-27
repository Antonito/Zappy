#include "zappy_ai_stdafx.hpp"

namespace zappy
{
  Model::Model(IndicesElement<glm::vec3> const &vertices,
               IndicesElement<glm::vec2> const &uv,
               IndicesElement<glm::vec3> const &normals)
      : m_vertices(vertices), m_uv(uv), m_normals(normals), m_vao(),
        m_buffersId()
  {
    this->init();
  }

  Model::Model(IndicesElement<glm::vec3> &&vertices,
               IndicesElement<glm::vec2> &&uv,
               IndicesElement<glm::vec3> &&normals)
      : m_vertices(std::move(vertices)), m_uv(std::move(uv)),
        m_normals(std::move(normals)), m_vao(), m_buffersId()
  {
    nope::log::Log(Debug) << "Debug #5";
    this->init();
  }

  Model::Model(Model const &that)
      : m_vertices(that.m_vertices), m_uv(that.m_uv),
        m_normals(that.m_normals), m_vao(), m_buffersId()
  {
    this->init();
  }

  Model::Model(Model &&that)
      : m_vertices(std::move(that.m_vertices)), m_uv(std::move(that.m_uv)),
        m_normals(std::move(that.m_normals)), m_vao(std::move(that.m_vao)),
        m_buffersId(std::move(that.m_buffersId))
  {
    m_vao = 0;
    for (std::size_t i = 0; i < NB_BUFFER; ++i)
      {
	m_buffersId[i] = 0;
      }
  }

  Model::~Model()
  {
  }

  Model &Model::operator=(Model const &that)
  {
    if (this == &that)
      return (*this);
    m_vertices = that.m_vertices;
    m_uv = that.m_uv;
    m_normals = that.m_normals;
    this->init();
    return (*this);
  }

  Model &Model::operator=(Model &&that)
  {
    if (this == &that)
      return (*this);
    m_vertices = std::move(that.m_vertices);
    m_uv = std::move(that.m_uv);
    m_normals = std::move(that.m_normals);
    m_vao = std::move(that.m_vao);
    m_buffersId = std::move(that.m_buffersId);

    that.m_vao = 0;
    for (std::size_t i = 0; i < NB_BUFFER; ++i)
      {
	that.m_buffersId[i] = 0;
      }
    return (*this);
  }

  Model Model::fromObj(std::string const &path)
  {
    IndicesElement<glm::vec3> vertices;
    IndicesElement<glm::vec2> uvs;
    IndicesElement<glm::vec3> normals;

    std::size_t   lineCount = 1;
    std::string   line;
    std::ifstream fs(path.c_str());

    if (fs.is_open() == false)
      {
	throw std::exception();
	// throw std::system_error((std::string("Failed to open obj file: ") +
	//                         path).c_str());
      }

    while (std::getline(fs, line))
      {
	line = line.substr(0, line.find_last_of("\n"));

	std::istringstream is(line);
	std::string        firstWord;

	is >> firstWord;

	while (is.peek() == ' ')
	  {
	    is.get();
	  }

	// It's a vertex
	if (firstWord == "v")
	  {
	    glm::vec3 vertex;

	    int res = std::sscanf(is.str().c_str(), "v %f %f %f", &vertex.x,
	                          &vertex.y, &vertex.z);

	    if (res == 3)
	      {
		vertices.elements.push_back(vertex);
	      }
	    else
	      {
		nope::log::Log(Error)
		    << "Invalid vertex in " << path << ':' << lineCount;
	      }
	  }
	// It's a uv
	else if (firstWord == "vt")
	  {
	    glm::vec2 uv;

	    int res = std::sscanf(is.str().c_str(), "vt %f %f", &uv.x, &uv.y);

	    if (res == 2)
	      {
		uvs.elements.push_back(uv);
	      }
	    else
	      {
		nope::log::Log(Error)
		    << "Invalid uv in " << path << ':' << lineCount;
	      }
	  }
	// It's a normal
	else if (firstWord == "vn")
	  {
	    glm::vec3 normal;

	    int res = std::sscanf(is.str().c_str(), "vn %f %f %f", &normal.x,
	                          &normal.y, &normal.z);

	    if (res == 3)
	      {
		normals.elements.push_back(normal);
	      }
	    else
	      {
		nope::log::Log(Error)
		    << "Invalid normal in " << path << ':' << lineCount;
	      }
	  }
	// It's a face
	else if (firstWord == "f")
	  {
	    std::uint32_t vertex[3];
	    std::uint32_t uv[3];
	    std::uint32_t normal[3];

	    int res =
	        sscanf(is.str().c_str(), "f %u/%u/%u %u/%u/%u %u/%u/%u",
	               &vertex[0], &uv[0], &normal[0], &vertex[1], &uv[1],
	               &normal[1], &vertex[2], &uv[2], &normal[2]);

	    if (res == 9)
	      {
		vertices.indices.push_back(vertex[0]);
		vertices.indices.push_back(vertex[1]);
		vertices.indices.push_back(vertex[2]);
		uvs.indices.push_back(uv[0]);
		uvs.indices.push_back(uv[1]);
		uvs.indices.push_back(uv[2]);
		normals.indices.push_back(normal[0]);
		normals.indices.push_back(normal[1]);
		normals.indices.push_back(normal[2]);
	      }
	    else
	      {
		nope::log::Log(Error)
		    << "Invalid face in " << path << ':' << lineCount;
	      }
	  }
	else if (std::all_of(firstWord.begin(), firstWord.end(), isspace) ==
	         false)
	  {
	    nope::log::Log(Warning)
	        << "Unknown line in " << path << ':' << lineCount;
	  }
	++lineCount;
      }

    return (Model(std::move(vertices), std::move(uvs), std::move(normals)));
  }

  IndicesElement<glm::vec3> const &Model::vertices() const
  {
    return (m_vertices);
  }

  IndicesElement<glm::vec2> const &Model::uv() const
  {
    return (m_uv);
  }

  IndicesElement<glm::vec3> const &Model::normals() const
  {
    return (m_normals);
  }

  void Model::init()
  {
    nope::log::Log(Debug) << "Debug #1";
    // Generate and bind the vao
    glGenVertexArrays(1, &m_vao);
    nope::log::Log(Debug) << "Debug #2";
    glBindVertexArray(m_vao);
    nope::log::Log(Debug) << "Debug #3";

    //
    // Vertex
    //
    glGenBuffers(NB_BUFFER, m_buffersId.data());
    glBindBuffer(GL_ARRAY_BUFFER, m_buffersId[VERTEX]);
    glBufferData(GL_ARRAY_BUFFER,
                 m_vertices.elements.size() * sizeof(m_vertices.elements[0]),
                 &m_vertices.elements[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    // Vertex indices
    glBindBuffer(GL_ARRAY_BUFFER, m_buffersId[VERTEX_IDX]);
    glBufferData(GL_ARRAY_BUFFER,
                 m_vertices.indices.size() * sizeof(m_vertices.indices[0]),
                 &m_vertices.indices[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_UNSIGNED_INT, GL_FALSE, 0, 0);

    //
    // UV
    //
    glBindBuffer(GL_ARRAY_BUFFER, m_buffersId[UV]);
    glBufferData(GL_ARRAY_BUFFER,
                 m_uv.elements.size() * sizeof(m_uv.elements[0]),
                 &m_uv.elements[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, 0);

    // UV indices
    glBindBuffer(GL_ARRAY_BUFFER, m_buffersId[UV_IDX]);
    glBufferData(GL_ARRAY_BUFFER,
                 m_uv.indices.size() * sizeof(m_uv.indices[0]),
                 &m_uv.indices[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 3, GL_UNSIGNED_INT, GL_FALSE, 0, 0);

    //
    // Normals
    //
    glBindBuffer(GL_ARRAY_BUFFER, m_buffersId[NORMAL]);
    glBufferData(GL_ARRAY_BUFFER,
                 m_normals.elements.size() * sizeof(m_normals.elements[0]),
                 &m_normals.elements[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(4);
    glVertexAttribPointer(4, 3, GL_UNSIGNED_INT, GL_FALSE, 0, 0);

    // Normals indices
    glBindBuffer(GL_ARRAY_BUFFER, m_buffersId[NORMAL_IDX]);
    glBufferData(GL_ARRAY_BUFFER,
                 m_normals.indices.size() * sizeof(m_normals.indices[0]),
                 &m_normals.indices[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(5);
    glVertexAttribPointer(5, 3, GL_UNSIGNED_INT, GL_FALSE, 0, 0);

    // Unbind the vao
    glBindVertexArray(0);
  }
}
