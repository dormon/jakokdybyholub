#include"CTextureUnit.hpp"

CTextureUnit::CTextureUnit(GLint Uniform,unsigned UnitNumber){
	this->Uniform=Uniform;//texture uniform in shader program
	this->UnitNumber=UnitNumber;//texture unit number
}

void CTextureUnit::SetTextureUnit(){
	glActiveTexture(GL_TEXTURE0+this->UnitNumber);//activate texture unit
	glUniform1i(this->Uniform,this->UnitNumber);//load texture unit number
}

