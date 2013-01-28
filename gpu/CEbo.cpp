#include"CEbo.hpp"
#include<string.h>

CEbo::CEbo(
		unsigned NumberOfElements,
		GLenum Type,
		GLenum Usage):CBufferObject(Usage){
	this->Type=Type;//type of elements
	this->NumberOfElements=NumberOfElements;//number of elements
	if(this->Type==GL_UNSIGNED_BYTE)this->Size=sizeof(unsigned char);
	if(this->Type==GL_UNSIGNED_SHORT)this->Size=sizeof(unsigned short);
	if(this->Type==GL_UNSIGNED_INT)this->Size=sizeof(unsigned int);
	this->Size*=this->NumberOfElements;//size
	glBindBuffer(this->Name,GL_ELEMENT_ARRAY_BUFFER);//element buffer object
	glBufferData(this->Name,this->Size,NULL,this->Usage);//allocate buffer data
	this->Data=new unsigned char[this->Size];//allocate cpu data
	memset(this->Data,this->Size,0);//clear buffer
}

CEbo::~CEbo(){
	delete[](unsigned char*)this->Data;//delete buffer object cpu data
}
