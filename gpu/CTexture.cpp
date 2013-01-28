#include"CTexture.hpp"

CTexture::CTexture(){
	glGenTextures(1,&this->Name);//generate texture name
}

CTexture::~CTexture(){
	glDeleteTextures(1,&this->Name);//delete texture name
}
