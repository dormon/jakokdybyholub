#include"CBufferObject.hpp"

CBufferObject::CBufferObject(GLenum Usage){
	this->Usage=Usage;//usage of buffer
	this->Data=NULL;//buffer object cpu data
	glGenBuffers(1,&this->Name);//generate buffer object name
}

CBufferObject::~CBufferObject(){
	glDeleteBuffers(1,&this->Name);//delete buffer object
	this->Data=NULL;//buffer object cpu data
}
