/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <gl/glew.h>
#include <iostream>

int main( int argc, char* args[] )
{
   
	int i = glewInit();

	std::cout << i;

    return 0;
}