#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Checklist/Checklist.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		Checklist clhobbies = Checklist(6, 15, { "Hike", "Books", "Movies", "Games" });
		TEST_METHOD(getNumbet)
		{
			// TODO: Your test code here
		}

	};
}