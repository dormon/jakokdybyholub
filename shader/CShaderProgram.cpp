#include"CShaderProgram.hpp"
void CShaderProgram::CreateShaderProgram_Prologue(){
	this->ShaderProgramID=glCreateProgram();//creates a shader program
	if(!this->ShaderProgramID)//something is wrong
		throw std::string("glCreateProgram failed"+GetGLError());//error message
}

void CShaderProgram::CreateShaderProgram_Epilogue(){
	glLinkProgram(this->ShaderProgramID);//link shader program
	//std::cout<<GetShaderInfo(this->ShaderProgramID);
	int Status;//status of linking
	glGetProgramiv(this->ShaderProgramID,GL_LINK_STATUS,&Status);//status
	if(Status==GL_FALSE)//something is wrong
		throw std::string("Shader linking failed"+GetGLError());//error message
	this->GetParameterList();//get list of shader program parameter
}

void CShaderProgram::GetParameterList(){
	void(*GetActive[2])(GLuint,GLuint,GLsizei,GLsizei*,GLint*,GLenum*,GLchar*)={
		glGetActiveAttrib,glGetActiveUniform};
	GLint(*GetLocation[2])(GLuint,const GLchar*)={
		glGetAttribLocation,glGetUniformLocation};
	GLenum Active[2]={
		GL_ACTIVE_ATTRIBUTES,GL_ACTIVE_UNIFORMS};
	GLenum MaxLenght[2]={
		GL_ACTIVE_ATTRIBUTE_MAX_LENGTH,GL_ACTIVE_UNIFORM_MAX_LENGTH};
	for(int t=0;t<2;++t){//loop over set of types {attribute,uniform}
		GLint Num;//number of active parameter
		glGetProgramiv(this->ShaderProgramID,Active[t],&Num);//number
		if(!Num)continue;//there are no active parameter
		GLint BufLen;//length of the longest attribute name
		glGetProgramiv(this->ShaderProgramID,MaxLenght[t],&BufLen);
		char*Buffer=new char[BufLen+1];//alocate buffer
		for(GLint i=0;i<Num;++i){//loop over active parameter
			GLenum Type;//type of parameter
			GLint Size;//size of parameter
			std::string Name;//name of parameter
			GLint Location;//location of parameter
			GetActive[t](this->ShaderProgramID,i,BufLen,NULL,&Size,&Type,Buffer);
			Location=GetLocation[t](this->ShaderProgramID,Buffer);//location
			Name=std::string(Buffer);//convert buffer to string
			CShaderParameter Param=CShaderParameter(Location,Type,Name,Size);//param
			this->ParameterList.insert(
					std::pair<std::string,CShaderParameter>(Name,Param));
		}
		delete[]Buffer;//free buffer
	}
}

CShaderProgram::CShaderProgram(unsigned Num,...){
	this->CreateShaderProgram_Prologue();//prologue of creating of shader prg.
	va_list args;//arguments
	va_start(args,Num);//start point of arguments
	for(size_t i=0;i<Num;++i){//loop over arguments
		GLuint ShaderID=((CShader*)va_arg(args,CShader*))->GetShaderID();//ID
		std::cerr<<ShaderID<<std::endl;
		glAttachShader(//attach shader object to shader program
				this->ShaderProgramID,//shader program
				ShaderID);//shader object id
		this->ShaderList.push_back(ShaderID);//insert shader object to list
	}
	va_end(args);//end point of arguments
	this->CreateShaderProgram_Epilogue();//epilogue of creating of shader prg.
}

CShaderProgram::CShaderProgram(CShader**Shader,unsigned Num){
	this->CreateShaderProgram_Prologue();//prologue of creating of shader prg.
	for(unsigned i=0;i<Num;++i){//loop over shaders
		GLuint ShaderID=Shader[i]->GetShaderID();//shader object ID
		glAttachShader(//attach shader object to shader program
				this->ShaderProgramID,//shader program
				ShaderID);//shader object
		this->ShaderList.push_back(ShaderID);//inser shdaer object to list
	}
	this->CreateShaderProgram_Epilogue();//epilogue of creating of shader prg.
}

CShaderProgram::~CShaderProgram(){
	for(int i=0;i<this->ShaderList.size();++i)//loop over shader objects
		glDetachShader(this->ShaderProgramID,this->ShaderList[i]);//detach shader
	glDeleteProgram(this->ShaderProgramID);//deletes shader program
	this->ShaderList.clear();//clear list of shader object
}

GLuint CShaderProgram::GetProgramID(){
	return this->ShaderProgramID;//returns shader program id
}

GLint CShaderProgram::operator[](std::string Name){
	return this->ParameterList[Name].Location;//uniform id
}

GLuint CShaderProgram::GetAttribute(std::string AttributeName){
	return glGetAttribLocation(this->ShaderProgramID,AttributeName.data());
}

GLuint CShaderProgram::GetUniform(std::string UniformName){
	return glGetUniformLocation(this->ShaderProgramID,UniformName.data());
}

