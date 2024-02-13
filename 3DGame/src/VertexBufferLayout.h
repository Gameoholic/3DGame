#pragma once

#include <vector>
#include <GL/glew.h>

struct VertexBufferElement
{
	unsigned int count;
	unsigned int type;
	bool normalized;
};

class VertexBufferLayout
{
private:
	std::vector<VertexBufferElement> m_Elements;
public:
	VertexBufferLayout();

	template<typename T>
	void Push(int count)
	{
		static_assert(false);
	}

	template<>
	void Push<float>(int count)
	{
		m_Elements.push_back({ GL_FLOAT, static_cast<unsigned int>(count), false });
	}

	template<>
	void Push<unsigned int>(int count)
	{	
		m_Elements.push_back({ GL_UNSIGNED_INT, static_cast<unsigned int>(count), false });
	}

	template<>
	void Push<unsigned char>(int count)
	{
		m_Elements.push_back({ GL_UNSIGNED_BYTE, static_cast<unsigned int>(count), true });
	}
};