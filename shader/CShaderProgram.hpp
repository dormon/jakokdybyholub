#ifndef _CSHADERPROGRAM_HPP_
#define _CSHADERPROGRAM_HPP_

#include<GL/glew.h>
#include<stdarg.h>
#include<vector>
#include<map>
#include"CShader.hpp"
#include"ShaderInfo.hpp"
#include"CShaderParameter.hpp"

/**
 * @brief This class represents shader program
 */
class CShaderProgram
{
	private:
		std::vector<GLuint>ShaderList;///list of shader object
		std::map<std::string,CShaderParameter>ParameterList;///list of parameters
		GLuint ShaderProgramID;///id of shader program
		void CreateShaderProgram_Prologue();//prologue of creating of shader prg.
		void CreateShaderProgram_Epilogue();//epilogue of creating of shader prg.
		void GetParameterList();
	public:
		/**
		 * Constructor
		 * @param Shader list of shaders
		 * @param Num number of shaders
		 */
		CShaderProgram(CShader**Shader,unsigned Num);
		/**
		 * Constructor
		 * @param Num number of shaders
		 */
		CShaderProgram(unsigned Num,...);
		/**
		 * @brief Destructor
		 */
		~CShaderProgram();
		/**
		 * @brief This method return ID of linked shader program
		 *
		 * @return ID of linked shader program
		 */
		GLuint GetProgramID();
		/**
		 * @brief Return shader program uniform location
		 *
		 * @param Name name of uniform
		 *
		 * @return returns parameter ID
		 */
		GLint operator[](std::string Name);
		/**
		 * Ziska identifikator atributu
		 * @param AttributeName jmeno atributu
		 * @retunr vracu identifikator atributu
		 */
		GLuint GetAttribute(std::string AttributeName);
		/**
		 * Ziska identifikator uniformni promenne
		 * @param UniformName jmeno uniformni promenne
		 * @retunr vracu identifikator uniformni promenne
		 */
		GLuint GetUniform(std::string UniformName);
};

#endif//_CSHADERPROGRAM_HPP_
