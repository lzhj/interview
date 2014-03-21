#include "gtest/gtest.h"
#include "qh_string.h"
#include <iostream>

bool string_equal_test(qh::string &, const char *);

TEST(Qh_StringTest, member)
{
	// constructor test
	qh::string s1;
	qh::string s2("hello world");
	qh::string s3("hello world", 0);
	qh::string s4("hello world", 9);
	qh::string s5("hello world", 11);
	qh::string s6("hello world", 15);
	qh::string s7(s1);
	qh::string s8(s6);

	std::cout << string_equal_test(s1, "") << std::endl;
	ASSERT_TRUE(string_equal_test(s1, ""));
	ASSERT_TRUE(string_equal_test(s2, "hello world"));
	ASSERT_TRUE(string_equal_test(s3, ""));
	ASSERT_TRUE(string_equal_test(s4, "hello wor"));
	ASSERT_TRUE(string_equal_test(s5, "hello world"));
	ASSERT_FALSE(string_equal_test(s6, "hello world\0\0\0\0"));
	ASSERT_TRUE(string_equal_test(s7, ""));
	ASSERT_TRUE(string_equal_test(s8, "hello world\0\0\0\0"));

	// operator test
	s4 = s2;
	ASSERT_TRUE(string_equal_test(s4, "hello world"));

	EXPECT_EQ(s4[0], 'h');
	EXPECT_EQ(s4[11], '\0');

	s4[0] = 'H';
	s4[6] = 'W';
	ASSERT_TRUE(string_equal_test(s4, "Hello World"));
	//member functions test
	EXPECT_EQ(s1.size(), 0);

}

bool string_equal_test(qh::string &s, const char *str)
{
	if(!str)
		return false;
	else{
		size_t size_of_s = s.size();
		size_t len_str = strlen(str);
		if(size_of_s == 0 && len_str == 0)
			return true;
		else if(size_of_s != len_str)
			return false;
		else{
			size_t i;
			for(i = 0; i < len_str; ++i)
				if(s[i] != str[i])
					return false;
			return true;
		}

	}
}