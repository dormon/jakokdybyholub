#include "CShader.hpp"

CShader::CShader(GLenum type,std::string text){
	this->Text=text;//text
	this->Type=type;//type
	this->CompileShader();
}

CShader::CShader(std::string File){
	int length;//lenght of file in bytes
	char*Buffer=(char*)ReadWholeFile(&length,File);//read whole file
	this->Text=std::string((char*)Buffer,length);//convert to std::string
	switch(FileTypeSwitch(File,6,"vert","vp","frag","fp","geom","gp")){//type
		case 0:
		case 1:this->Type=GL_VERTEX_SHADER;break;//vertex shader
		case 2:
		case 3:this->Type=GL_FRAGMENT_SHADER;break;//fragment shader
		case 4:
		case 5:this->Type=GL_GEOMETRY_SHADER;break;//geometry shader
		default:throw std::string("Wrong file extension for shader");break;//unknown
	}
	delete[]Buffer;//free buffer data
	this->CompileShader();
}

CShader::~CShader(){
	glDeleteShader(this->ShaderID);//deletes a shader
}

void CShader::CompileShader(){
	this->ShaderID=glCreateShader(this->Type);//get shader id
	if(!this->ShaderID)//something is wrong
		throw std::string("glCreateShader failed"+GetGLError());//error message
	GLchar*ptr[1]={(GLchar*)this->Text.data()};//retype
	glShaderSource(this->ShaderID,1,(const GLchar**)ptr,NULL);//load shader text
	glCompileShader(this->ShaderID);//compile shader
	std::string Log=GetShaderInfo(this->ShaderID);
	if(!Log.empty())std::cout<<Log<<std::endl;//print out log
	GLint Status;//status of compilation
	glGetShaderiv(this->ShaderID,GL_COMPILE_STATUS,&Status);//get status
	if(Status==GL_FALSE)//something is wrong
		throw std::string("Shader compilation failed"+GetGLError());//error message
}

GLuint CShader::GetShaderID(){
	return this->ShaderID;//id of shader
}
