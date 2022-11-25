#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_7.2.rec/lab_7.2.rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72rec
{
	TEST_CLASS(UnitTest72rec)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            int result;
            int imax_1 = 0;
            int jmax_1 = 0;

            int a[3][3] = {
              {1, 5, 8},
              {2, 15, 7},
              {3, 7, 9},
            };
            int max = a[0][0];
            int* pa[3] = { a[0], a[1], a[2] };
            result = Max(pa, 3, 3, max, imax_1, jmax_1, 0 ,0); ;
            Assert::AreEqual(result, 15);
		}
	};
}
