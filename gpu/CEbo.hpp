#ifndef _CEBO_HPP_
#define _CEBO_HPP_

#include"CBufferObject.hpp"

/**
 * @brief This class represents element buffer object
 */
class CEbo: public CBufferObject
{
	private:
		GLenum Type;///type of elements
		unsigned NumberOfElements;///number of elements
	public:
		CEbo(unsigned NumberOfElements,GLenum Type,GLenum Usage);
		~CEbo();
};

#endif//_CEBO_HPP_
