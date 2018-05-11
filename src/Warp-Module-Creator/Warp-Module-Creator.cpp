#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <string>

#define WARP_PATH "..\\Warp-Framework\\"
#define EMPTY_VAL ""
#define PLHDR_VAL ""
#define STR_NEWLN 10
#define STR_CPRGT "//© 2018 NIREX ALL RIGHTS RESERVED"

namespace File
{
	int AppendAllText(std::string file, std::string str)
	{
		std::ofstream f;
		f.open(file);
		f << str;
		f.close();
		return 0;
	}
}

namespace String
{
	char* ToUpper(char* temp)
	{
		char* retc = temp;
		
		int i = 0;
		while (retc[i])
		{
			retc[i] = toupper(retc[i]);
			i++;
		}
		return retc;
	}

	char* ToLower(char* temp)
	{
		char* retc = temp;

		int i = 0;
		while (retc[i])
		{
			retc[i] = tolower(retc[i]);
			i++;
		}
		return retc;
	}
}

auto Empty(int argc, char** argv) -> int
{
	std::string name = argv[1];
	std::string upperName = String::ToUpper(argv[1]);
	std::string lowerName = String::ToLower(argv[1]);

	std::string hfileName = name + ".h";
	std::string cfileName = name + ".cpp";

	std::string hfileCont = EMPTY_VAL;
	std::string cfileCont = EMPTY_VAL;

	// .H
	// Copyright
	hfileCont += STR_CPRGT;
	hfileCont += STR_NEWLN;
	hfileCont += STR_NEWLN;

	// #ifndef
	hfileCont += "#ifndef _";
	hfileCont += upperName;
	hfileCont += "_H_";
	hfileCont += STR_NEWLN;

	// #define
	hfileCont += "#define _";
	hfileCont += upperName;
	hfileCont += "_H_";
	hfileCont += STR_NEWLN;
	hfileCont += STR_NEWLN;

	// #endif
	hfileCont += "#endif // !_";
	hfileCont += upperName;
	hfileCont += "_H_";
	hfileCont += STR_NEWLN;

	// .CPP
	// CopyRight
	cfileCont += STR_CPRGT;
	cfileCont += STR_NEWLN;
	cfileCont += STR_NEWLN;

	// #Include
	cfileCont += "#include \"";
	cfileCont += hfileName;
	cfileCont += "\"";
	cfileCont += STR_NEWLN;

	File::AppendAllText(WARP_PATH + hfileName, hfileCont);
	File::AppendAllText(WARP_PATH + cfileName, cfileCont);

	return 0;
}

auto ObjectOriented(int argc, char** argv, bool Entity) -> int
{
	std::string name = argv[1];
	std::string upperName = String::ToUpper(argv[1]);
	std::string lowerName = String::ToLower(argv[1]);

	std::string hfileName = "W" + name + ".h";
	std::string cfileName = "W" + name + ".cpp";

	std::string hfileCont = EMPTY_VAL;
	std::string cfileCont = EMPTY_VAL;

	// .H
	// Copyright
	hfileCont += STR_CPRGT;
	hfileCont += STR_NEWLN;
	hfileCont += STR_NEWLN;

	// #ifndef
	hfileCont += "#ifndef ";
	hfileCont += "_W_";
	hfileCont += upperName;
	hfileCont += "_H_";
	hfileCont += STR_NEWLN;

	// #define
	hfileCont += "#define ";
	hfileCont += "_W_";
	hfileCont += upperName;
	hfileCont += "_H_";
	hfileCont += STR_NEWLN;
	hfileCont += STR_NEWLN;

	if (Entity)
	{
		// #include "WEntity.h"
		hfileCont += "#include \"WEntity.h\"";
		hfileCont += STR_NEWLN;
		hfileCont += STR_NEWLN;
	}

	// Class

	hfileCont += "class ";
	hfileCont += "W";
	hfileCont += name;
	if (Entity)
	{
		hfileCont += " : public WEntity";
	}
	hfileCont += STR_NEWLN;
	hfileCont += "{";
	hfileCont += STR_NEWLN;
	hfileCont += "public:";
	hfileCont += STR_NEWLN;

	// CTOR
	hfileCont += "\t";
	hfileCont += "W";
	hfileCont += name;
	hfileCont += "();";

	// DTOR
	hfileCont += STR_NEWLN;
	hfileCont += "\t~";
	hfileCont += "W";
	hfileCont += name;
	hfileCont += "();";
	hfileCont += STR_NEWLN;
	hfileCont += STR_NEWLN;

	// End Notation
	hfileCont += "};";
	hfileCont += STR_NEWLN;
	hfileCont += STR_NEWLN;

	// #endif
	hfileCont += "#endif // !_W_";
	hfileCont += upperName;
	hfileCont += "_H_";
	hfileCont += STR_NEWLN;

	// .CPP
	// CopyRight
	cfileCont += STR_CPRGT;
	cfileCont += STR_NEWLN;
	cfileCont += STR_NEWLN;

	// #Include
	cfileCont += "#include \"";
	cfileCont += hfileName;
	cfileCont += "\"";
	cfileCont += STR_NEWLN;
	cfileCont += STR_NEWLN;

	// CTOR
	cfileCont += "W";
	cfileCont += name;
	cfileCont += "::";
	cfileCont += "W";
	cfileCont += name;
	cfileCont += "()";
	cfileCont += STR_NEWLN;
	cfileCont += "{";
	cfileCont += STR_NEWLN;
	cfileCont += STR_NEWLN;
	cfileCont += "}";
	cfileCont += STR_NEWLN;
	cfileCont += STR_NEWLN;

	// DTOR
	cfileCont += "W";
	cfileCont += name;
	cfileCont += "::~";
	cfileCont += "W";
	cfileCont += name;
	cfileCont += "()";
	cfileCont += STR_NEWLN;
	cfileCont += "{";
	cfileCont += STR_NEWLN;
	cfileCont += STR_NEWLN;
	cfileCont += "}";
	cfileCont += STR_NEWLN;

	File::AppendAllText(WARP_PATH + hfileName, hfileCont);
	File::AppendAllText(WARP_PATH + cfileName, cfileCont);

	return 0;
}

auto HeaderOnly(int argc, char** argv, bool Entity) -> int
{
	std::string name = argv[1];
	std::string upperName = String::ToUpper(argv[1]);
	std::string lowerName = String::ToLower(argv[1]);

	std::string hfileName = "W" + name + ".h";
	std::string hfileCont = EMPTY_VAL;

	// .H
	// Copyright
	hfileCont += STR_CPRGT;
	hfileCont += STR_NEWLN;
	hfileCont += STR_NEWLN;

	// #ifndef
	hfileCont += "#ifndef ";
	hfileCont += "_W_";
	hfileCont += upperName;
	hfileCont += "_H_";
	hfileCont += STR_NEWLN;

	// #define
	hfileCont += "#define ";
	hfileCont += "_W_";
	hfileCont += upperName;
	hfileCont += "_H_";
	hfileCont += STR_NEWLN;
	hfileCont += STR_NEWLN;

	if (Entity)
	{
		// #include "WEntity.h"
		hfileCont += "#include \"WEntity.h\"";
		hfileCont += STR_NEWLN;
		hfileCont += STR_NEWLN;
	}

	// Class

	hfileCont += "class ";
	hfileCont += "W";
	hfileCont += name;
	if (Entity)
	{
		hfileCont += " : public WEntity";
	}
	hfileCont += STR_NEWLN;
	hfileCont += "{";
	hfileCont += STR_NEWLN;
	hfileCont += "public:";
	hfileCont += STR_NEWLN;

	// CTOR
	hfileCont += "\t";
	hfileCont += "W";
	hfileCont += name;
	hfileCont += "();";

	// DTOR
	hfileCont += STR_NEWLN;
	hfileCont += "\t~";
	hfileCont += "W";
	hfileCont += name;
	hfileCont += "();";
	hfileCont += STR_NEWLN;
	hfileCont += STR_NEWLN;

	// End Notation
	hfileCont += "};";
	hfileCont += STR_NEWLN;
	hfileCont += STR_NEWLN;

	// #endif
	hfileCont += "#endif // !_W_";
	hfileCont += upperName;
	hfileCont += "_H_";
	hfileCont += STR_NEWLN;

	File::AppendAllText(WARP_PATH + hfileName, hfileCont);

	return 0;
}

auto main(int argc, char** argv) -> int
{

	std::string arg1 = argv[1];
	std::string cmd = EMPTY_VAL;
	if (argc < 2 || arg1 == "-h" || arg1 == "--help")
	{
		std::cout << std::endl;
		std::cout << "wmc <name> <option>";
		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "Options: " << std::endl;
		std::cout << "   header: Creates a single header file (.h)" << std::endl;
		std::cout << "   wheader: Creates a single warp header file (.h)" << std::endl;
		std::cout << "   class: Creates class files (.h .cpp)" << std::endl;
		std::cout << "   wclass: Creates warp class files (.h .cpp)" << std::endl;
		std::cout << "   'nothing': Creates empty files (.h .cpp)" << std::endl;

		return 1;
	}
	else if (argc == 2)
	{
		std::cout << "Creating Empty files." << std::endl;
		return (Empty(argc, argv));
	}
	else if (argc == 3)
	{
		std::string arg2 = argv[2];

		if (arg2 == "header")
		{
			std::cout << "header" << std::endl;
			std::cout << "Creating header file." << std::endl;
			return (HeaderOnly(argc, argv, false));
		}
		else if (arg2 == "wheader")
		{
			std::cout << "header" << std::endl;
			std::cout << "Creating Warp header file." << std::endl;
			return (HeaderOnly(argc, argv, true));
		}
		else if (arg2 == "class")
		{
			std::cout << "Creating class files." << std::endl;
			return (ObjectOriented(argc, argv, false));
		}
		else if (arg2 == "wclass")
		{
			std::cout << "Creating Warp class files." << std::endl;
			return (ObjectOriented(argc, argv, true));
		}
		else
		{
			std::cout << "Creating Empty files." << std::endl;
			return (Empty(argc, argv));
		}
	}
	
    return 0;
}
