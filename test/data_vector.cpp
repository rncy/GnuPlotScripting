#include "GnuPlotScripting/data_vector.hpp"

#include <gtest/gtest.h>

using namespace GnuPlotScripting;

TEST(Data_Std_Vector, uuid)
{
  std::vector<double> v1(2, 5);
  Data_Vector test_1(v1);
  Data_Vector test_2(v1);

  ASSERT_FALSE(test_1.uuid() == test_2.uuid());

  ASSERT_EQ(test_1.data(), "5 \n5 \n");
}

TEST(Data_Std_Vector, vector)
{
  std::vector<double> v1(2, 3);
  std::vector<int> v2(2, 4);

  Data_Vector test_1(v1, v2);
  ASSERT_EQ(test_1.data(), "3 4 \n3 4 \n");
}

TEST(Data_Std_Vector, copy)
{
  std::vector<double> v1(2, 3);
  std::vector<int> v2(2, 4);

  Data_Vector test_1(v1, v2);
  Data_Vector test_2(v2, v1);
  ASSERT_EQ(test_1.data(), "3 4 \n3 4 \n");

  test_2 = test_1;
  ASSERT_EQ(test_1.data(), "3 4 \n3 4 \n");
  ASSERT_EQ(test_2.data(), "3 4 \n3 4 \n");
}
