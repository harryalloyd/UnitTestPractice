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





TEST(PasswordTest, mixed_upper_and_lower)
{
	Password my_password;
	int actual = my_password.has_mixed_case("Ab");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, mixed_lower_then_upper)
{
	Password my_password;
	int actual = my_password.has_mixed_case("aB");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, mixed_upper)
{
	Password my_password;
	int actual = my_password.has_mixed_case("A");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, mixed_lower)
{
	Password my_password;
	int actual = my_password.has_mixed_case("b");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, mixed_two_upper)
{
	Password my_password;
	int actual = my_password.has_mixed_case("AA");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, mixed_two_lower)
{
	Password my_password;
	int actual = my_password.has_mixed_case("bb");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, mixed_two_lower_and_two_upper)
{
	Password my_password;
	int actual = my_password.has_mixed_case("AbAb");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, mixed_empty)
{
	Password my_password;
	int actual = my_password.has_mixed_case("");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, mixed_random_characters)
{
	Password my_password;
	int actual = my_password.has_mixed_case("aB?Ab!");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, mixed_numbers_with_letters)
{
	Password my_password;
	ASSERT_EQ(false, my_password.has_mixed_case("a4"));
}

TEST(PasswordTest, mixed_numbers_with_letters_two)
{
	Password my_password;
	ASSERT_EQ(false, my_password.has_mixed_case("B4"));
}

TEST(PasswordTest, mixed_numbers_with_letters_three)
{
	Password my_password;
	int actual = my_password.has_mixed_case("a4B");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, mixed_just_characters)
{
	Password my_password;
	int actual = my_password.has_mixed_case("?4!");
	ASSERT_EQ(false, actual);
}



TEST(PasswordTest, unique_count_characters)
{
	Password my_password;
	int actual = my_password.unique_characters("?4!");
	ASSERT_EQ(3, actual);
}

TEST(PasswordTest, unique_count_characters_diff)
{
	Password my_password;
	int actual = my_password.unique_characters("?");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, unique_count_characters_empty)
{
	Password my_password;
	int actual = my_password.unique_characters("");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, unique_count_characters_same_char_special)
{
	Password my_password;
	int actual = my_password.unique_characters("??");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, unique_count_characters_same_char_num)
{
	Password my_password;
	int actual = my_password.unique_characters("11");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, unique_count_characters_same_char_letter)
{
	Password my_password;
	int actual = my_password.unique_characters("hh");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, unique_count_characters_upper_and_lower_let)
{
	Password my_password;
	int actual = my_password.unique_characters("aA");
	ASSERT_EQ(2, actual);
}