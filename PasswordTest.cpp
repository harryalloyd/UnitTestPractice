/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, two_leading_letters)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aab");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, one_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ab");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, upper_and_lower_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aAa");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, two_uppercase_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("AAab");
	ASSERT_EQ(2, actual);
}