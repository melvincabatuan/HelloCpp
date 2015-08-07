#Makefile

all: chapter1

chapter1: hello functions size autoconversion initialization implicit accept arraycopy reference vector_struct vector_class invariantdemo assertdemo

hello:

	g++ -Wall -o HelloWorld HelloWorld.cpp
	
functions:

	g++ -Wall -o Functions Functions.cpp
	
size:

	g++ -Wall -o Size Size.cpp
	
autoconversion:

	g++ -Wall -o AutomaticConversion AutomaticConversion.cpp
	
initialization:

	g++ -std=c++11 -Wall -o Initialization Initialization.cpp
	
implicit:

	g++ -std=c++11 -Wall -o ImplicitType ImplicitType.cpp
	
accept:

	g++ -std=c++11 -Wall -o Accept Accept.cpp
	
arraycopy:

	g++ -std=c++11 -Wall -o ArrayCopy ArrayCopy.cpp
	
reference:

	g++ -std=c++11 -Wall -o ReferenceDemo ReferenceDemo.cpp
	
vector_struct:

	g++ -std=c++11 -Wall -o VectorStructDemo VectorStructDemo.cpp
	
vector_class:

	g++ -std=c++11 -Wall -o VectorClassDemo VectorClassDemo.cpp
	
invariantdemo:

	g++ -std=c++11 -Wall -o InvariantDemo InvariantDemo.cpp
	
assertdemo:

	g++ -std=c++11 -Wall -o AssertDemo AssertDemo.cpp
	
	
clean:

	rm *.o *~
