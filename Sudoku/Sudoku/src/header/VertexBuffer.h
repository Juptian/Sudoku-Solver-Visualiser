#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "utils.h"

#define uint unsigned int

template <typename T>
class VertexBuffer
{
private:
	uint _buffer;
	GLenum _targetType;
	T* _data;
	int _dataLength;

public:
	VertexBuffer<T>(uint buffer, GLenum targetType, T data[], int dataLength);
	VertexBuffer<T>(uint buffer, GLenum targetType, T data[], int dataLength, int amount);
	void Bind();
	void Unbind();
};