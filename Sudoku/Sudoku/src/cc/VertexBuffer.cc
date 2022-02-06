#include "../header/VertexBuffer.h"
#define get_template template <typename T>

get_template
VertexBuffer<T>::VertexBuffer(uint buffer, GLenum targetType, T data[], int dataLength)
	: VertexBuffer(buffer, targetType, data, dataLength, 1)
{}

get_template
VertexBuffer<T>::VertexBuffer(uint buffer, GLenum targetType, T data[], int dataLength, int amount)
	: _buffer(buffer), _targetType(targetType), _data(data), _dataLength(dataLength)
{
	glGenBuffers(amount, &_buffer);
	glBindBuffer(_targetType, _buffer);
	glBufferData(_targetType, _dataLength * sizeof(_data[0]), _data, GL_STATIC_DRAW);
	glBindBuffer(_targetType, 0);
}


get_template
void VertexBuffer<T>::Unbind();