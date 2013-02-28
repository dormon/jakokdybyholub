#ifndef _CVERTEXATTRIBUTE_HPP_
#define _CVERTEXATTRIBUTE_HPP_

class CVertexAttribute
{
	private:
		GLuint Index;/// vertex attribute in shader program
		GLint Size;/// size of vertex attribute
		GLenum Type;/// type of vertex attribute
		GLboolean Normalized;/// normalized
		GLsizei Stride;/// stride in buffer object
		unsigned Offset;/// offset 
	public:
		
};

//Vertex Input "4FNS,O|4FNS,O"

#endif//_CVERTEXATTRIBUTE_HPP_
