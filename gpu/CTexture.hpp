#ifndef _CTEXTURE_HPP_
#define _CTEXTURE_HPP_

#include"GL/glew.h"

/**
 * @brief This class represents texture object
 */
class CTexture
{
	private:
		GLuint Name;/// texture name
		GLenum Target;/// texture target
		int DataChanged;/// data of texture changed
	public:
		CTexture();
		~CTexture();
};

#endif//_CTEXTURE_HPP_
