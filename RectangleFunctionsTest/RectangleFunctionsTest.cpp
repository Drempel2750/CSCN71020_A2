#include "pch.h"
#include "CppUnitTest.h"
extern "C" int getPerimeter(int* length, int* width);
extern "C" int getArea(int* length, int* width);
extern "C" void setLength(int input, int* length);
extern "C" void setWidth(int input, int* width);
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RectangleFunctionsTest
{
	TEST_CLASS(RectangleFunctionsTest)
	{
	public:

		TEST_METHOD(GetPerimeterFunctionality)
		{
			int result = 0;
			int length = 2, width = 2;
			int* lenPtr = &length, * widPtr = &width;

			result = getPerimeter(lenPtr, widPtr);
			Assert::AreEqual(8, result);
		}
		TEST_METHOD(GetAreaFunctionality)
		{
			int result = 0;
			int length = 4, width = 2;
			int* lenPtr = &length, * widPtr = &width;

			result = getArea(lenPtr, widPtr);
			Assert::AreEqual(8, result);
		}
	};
}
