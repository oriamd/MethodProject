#include "stdafx.h"
#include "CppUnitTest.h"
#include "../ComboBox/ComboBox.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(SelectIndex)
		{
			ComboBox comboBox = ComboBox(18, { "Israel", "italy", "Germany" });
			comboBox.SetSelectedIndex(0);
			Assert::AreEqual(0, (int)comboBox.GetSelectedIndex(), L"Assert");
			comboBox.SetSelectedIndex(2);
			Assert::AreEqual(2, (int)comboBox.GetSelectedIndex(), L"Assert");
			comboBox.SetSelectedIndex(2);
			Assert::AreEqual(2, (int)comboBox.GetSelectedIndex(), L"Assert");
			comboBox.SetSelectedIndex(1);
			Assert::AreEqual(1, (int)comboBox.GetSelectedIndex(), L"Assert");
		}

	};
}