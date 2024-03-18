#include "pch.h"
#include "CppUnitTest.h"
#include "CppUnitTest.h"
#include "..//2s.lab.2.4.2/receipt.h"
#include "..//2s.lab.2.4.2/goods.h"
#include "..//2s.lab.2.4.2/goods.cpp"
#include "..//2s.lab.2.4.2/receipt.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestCalculateTotalAmount)
        {
            Receipt receipt;
            Goods item1(1, "Item 1", 50.0, 2);
            Goods item2(2, "Item 2", 20.0, 1);
            receipt.addItem(item1);
            receipt.addItem(item2);

            Assert::AreEqual(120.0, receipt.calculateTotalAmount());
        }
    };
}