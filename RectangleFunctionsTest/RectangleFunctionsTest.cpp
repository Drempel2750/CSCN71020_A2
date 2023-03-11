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
			int result = 0;//result initialized to 0
			int length = 2, width = 2;
			int* lenPtr = &length, * widPtr = &width;//length and width pointers initialized

			result = getPerimeter(lenPtr, widPtr);
			Assert::AreEqual(8, result);//expected result is 8 for perimeter.
		}
		TEST_METHOD(GetAreaFunctionality)
		{
			int result = 0;//result initialized to 0.
			int length = 4, width = 2;
			int* lenPtr = &length, * widPtr = &width;//length and width pointers initialized

			result = getArea(lenPtr, widPtr);
			Assert::AreEqual(8, result);//expected result is 8 for area.
		}
		TEST_METHOD(SetLengthLowerLimitFunctionality)
		{
			int input = 0;
			int resultLen = 2;
			//input and resultLen both initialized. resultLen is initialized to 2 because it is a value which will not be
			//used as input. For some tests if input and resultLen are the same, the test will report a false negative. for ex.
			//if the values are both initialized to 0, for some cases the test would fail, since zero is outside of the accepted 
			//values meaning that the pointer variable would not be updated, but the assert would show false, since the values are the same.
			//this is done for all tests below.
			int* lenPtr = &resultLen;
			setLength(input, lenPtr);
			Assert::AreNotEqual(input, *lenPtr);
		}//Will test the lower limit of included values. Using a value one lower then 1(lower limit)
		//Since 0 is outside of accepted values, and AreNotEqual is used, test should pass
		TEST_METHOD(SetLengthUpperLimitFunctionality)
		{
			int input = 100;
			int resultLen = 2;
			int* lenPtr = &resultLen;

			setLength(input, lenPtr);
			Assert::AreNotEqual(input, *lenPtr);
		}//will test the upper limit of included values. Using a value one greater then 99(upper limit)
		//Since 100 is outside of accepted values, and AreNotEqual is used, test should pass
		TEST_METHOD(SetLengthEqualityFunctionality)
		{
			int input = 26;
			int resultLen = 2;
			int* lenPtr = &resultLen;

			setLength(input, lenPtr);
			Assert::AreEqual(input, *lenPtr);
		}//Will test that the pointer is updated to the proper value using input value between 1 and 99(inclusive)
		//Test Should pass with both *lenPtr and input being 26
		TEST_METHOD(SetWidthUpperLimitFunctionality)
		{
			int input = 100;
			int resultWid = 2;
			int* WidPtr = &resultWid;

			setWidth(input, WidPtr);
			Assert::AreNotEqual(input, *WidPtr);
		}//will test the upper limit of included values. Using a value one greater then 99(upper limit)
		//Since 100 is outside of accepted values, and AreNotEqual is used, test should pass
		TEST_METHOD(SetWidthLowerLimitFunctionality)
		{
			int input = 0;
			int resultWid = 2;
			int* WidPtr = &resultWid;

			setWidth(input, WidPtr);
			Assert::AreNotEqual(input, *WidPtr);
		}//will test the lower limit of included values. Using a value one less then 1(lower limit)
		//Since 0 is outside of accepted values, and AreNotEqual is used, test should pass
		TEST_METHOD(SetWidthEqualityFunctionality)
		{
			int input = 25;
			int resultWid = 2;
			int* WidPtr = &resultWid;

			setWidth(input, WidPtr);
			Assert::AreEqual(input, *WidPtr);
		}//Will test that the pointer is updated to the proper value using input value between 1 and 99(inclusive)
		//Test Should pass with both *widPtr and input being 25 after the function is called.
	};
}
