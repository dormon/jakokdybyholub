#ifndef _CBUFFEROBJECT_HPP_
#define _CBUFFEROBJECT_HPP_

#include<GL/glew.h>

class CBufferObject
{
	protected:
		GLuint Name;///buffer object name
		GLsizeiptr Size;///buffer object size
		GLenum Usage;///buffer object usage
		void*Data;///buffer object data
	public:
		CBufferObject(GLenum Usage);
		~CBufferObject();
};

#endif//_CBUFFEROBJECT_HPP_
