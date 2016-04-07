#include <GL/glew.h>
#include <SDL.h>

#include <Fragment/Graphics/Shader.h>
#include <Fragment/Graphics/ShaderProgram.h>
#include <Fragment/Graphics/VAO.h>
#include <Fragment/Graphics/VBO.h>
#include <Fragment/Window.h>
#include <iostream>

using Fragment::Graphics::Shader;
using Fragment::Graphics::ShaderProgram;
using Fragment::Graphics::VAO;
using Fragment::Graphics::VBO;
using Fragment::Window;

template<size_t SIZE, class T> inline size_t array_size(T(&arr)[SIZE])
{
	return SIZE;
}

static const GLfloat g_screen_vertex_buffer_data[] = {
	-1.0f,  1.0f, 0.0f,
	-1.0f, -1.0f, 0.0f,
	 1.0f, -1.0f, 0.0f,

	-1.0f,  1.0f, 0.0f,
	 1.0f,  1.0f, 0.0f,
	 1.0f, -1.0f, 0.0f
};

int main( int argc, char* args[] )
{
	Window win(640, 480, "Triangles");
	win.init();

	std::shared_ptr<Shader> vertshader, fragshader;

	try
	{
		vertshader = Shader::fromFile("vert.glsl", GL_VERTEX_SHADER);
		fragshader = Shader::fromFile("frag.glsl", GL_FRAGMENT_SHADER);
	}
	catch(Fragment::Graphics::FileNotFoundException e)
	{
		std::cerr << "File not found: " << e.filename << std::endl;
		return 1;
	}

	ShaderProgram program;
	program.attachShader(vertshader.get());
	program.attachShader(fragshader.get());
	program.linkProgram();

	//
	// Setting up VAO and vertex buffer and stuff
	//
	VAO vertexarrayobject;

	VBO vertexbuffer;
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_screen_vertex_buffer_data), g_screen_vertex_buffer_data, GL_STATIC_DRAW);

	GLint uTime   = program.getUniformLocation("time");

	GLint uNTriangles		   = program.getUniformLocation("nTriangles");

	GLint uTrianglesCenter0   = program.getUniformLocation("triangles[0].center");
	GLint uTrianglesSize0     = program.getUniformLocation("triangles[0].size");
	GLint uTrianglesOffsett0  = program.getUniformLocation("triangles[0].offsett");

	GLint uTrianglesCenter1   = program.getUniformLocation("triangles[1].center");
	GLint uTrianglesSize1     = program.getUniformLocation("triangles[1].size");
	GLint uTrianglesOffsett1  = program.getUniformLocation("triangles[1].offsett");

	GLint uTrianglesCenter2   = program.getUniformLocation("triangles[2].center");
	GLint uTrianglesSize2     = program.getUniformLocation("triangles[2].size");
	GLint uTrianglesOffsett2  = program.getUniformLocation("triangles[2].offsett");

	SDL_Event e;
	bool running = true;
	while(running)
	{
		//Handle events on queue
	    while( SDL_PollEvent( &e ) != 0 )
	    {
	        if( e.type == SDL_QUIT )
	            running = false;

	        if (e.type == SDL_KEYDOWN)
	        {
				switch (e.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						running = false;
				}
	        }
	    }

    	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    	// Render triangles

    	program.useProgram();

		glUniform1f(uTime, (float)SDL_GetTicks());

		glUniform1f(uNTriangles, 3);

		glUniform2f(uTrianglesCenter0, 200, 200);
		glUniform1f(uTrianglesSize0, 100);
		glUniform1f(uTrianglesOffsett0, (float)SDL_GetTicks() * 0.001);

		glUniform2f(uTrianglesCenter1, 400, 400);
		glUniform1f(uTrianglesSize1, 50);
		glUniform1f(uTrianglesOffsett1, (float)SDL_GetTicks() * -0.0005);

		glUniform2f(uTrianglesCenter2, 200, 400);
		glUniform1f(uTrianglesSize2, 75);
		glUniform1f(uTrianglesOffsett2, 0);

    	glEnableVertexAttribArray(0);
		vertexbuffer.bind();
		glVertexAttribPointer(
			0,                  // attribute. No particular reason for 0, but must match the layout in the shader.
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*)0            // array buffer offset
		);

		glDrawArrays(GL_TRIANGLES, 0, array_size(g_screen_vertex_buffer_data));

		glDisableVertexAttribArray(0);

		// Swap windows
		SDL_GL_SwapWindow( win.getWindow() );
	}

	return 0;
}