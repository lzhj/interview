#include <stdio.h>
#include <stdlib.h>
#include "qh_string.h"
#include "gtest/gtest.h"

extern bool string_equal_test(qh::string &, const char *);
int main(int argc, char* argv[])
{
    //TODO ��������ӵ�Ԫ���ԣ�Խ��Խ�ã�����·��������ԽȫԽ��

#ifdef WIN32
    system("pause");
#endif

    testing::InitGoogleTest(&argc, argv);
    qh::string s;
    //ASSERT_TRUE(string_equal_test(s, ""));
	return RUN_ALL_TESTS();
}

