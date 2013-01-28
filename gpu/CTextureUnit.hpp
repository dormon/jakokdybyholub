#ifndef _CTEXTUREUNIT_HPP_
#define _CTEXTUREUNIT_HPP_

#include"GL/glew.h"

/**
 * @brief This class represents texture unit
 */
class CTextureUnit
{
	private:
		unsigned UnitNumber;/// number of texture unit
		GLint Uniform;/// texture uniform in shader program
	public:
		CTextureUnit(GLint Uniform,unsigned UnitNumber);
		void SetTextureUnit();
};

#endif//_CTEXTUREUNIT_HPP_
