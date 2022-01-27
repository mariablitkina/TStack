#include "pch.h"
#include "..\Project3\TCalculator.h"

using namespace std;

TEST(TCalculator, can_create_calculator) {

	ASSERT_NO_THROW(TCalc c);
};

TEST(TCalculator, can_set_and_get_expression) {

	TCalc c;
	string expr = "2+2";
	string res;

	ASSERT_NO_THROW(c.set_expr(expr));
	ASSERT_NO_THROW(res = c.get_expr());

	EXPECT_EQ(res, expr);

};

TEST(TCalculator, can_check_brackets) {

	TCalc c;
	c.set_expr("2+2");
	ASSERT_NO_THROW(c.check_expr());
};

TEST(TCalculator, can_determine_correct_brackets) {

	TCalc c;
	c.set_expr("(2+2)");
	ASSERT_TRUE(c.check_expr());
};

TEST(TCalculator, can_determine_incorrect_brackets) {

	TCalc c;
	c.set_expr("(2+(2)");
	ASSERT_FALSE(c.check_expr());
};

TEST(TCalculator, can_convert_to_postfix_1) {

	TCalc c;
	c.set_expr("2");
	ASSERT_NO_THROW(c.convert_to_postfix());
	EXPECT_EQ("2", c.get_pstfix());
};

TEST(TCalculator, can_convert_to_postfix_2) {

	TCalc c;
	c.set_expr("2+2");
	ASSERT_NO_THROW(c.convert_to_postfix());
	EXPECT_EQ("2 2 +", c.get_pstfix());
};

TEST(TCalculator, can_convert_to_postfix_3) {

	TCalc c;
	c.set_expr("2+2*2");
	ASSERT_NO_THROW(c.convert_to_postfix());
	EXPECT_EQ("2+2 2 *", c.get_pstfix());
};

TEST(TCalculator, can_convert_to_postfix_4) {

	TCalc c;
	c.set_expr("2^2+2-2/2");
	ASSERT_NO_THROW(c.convert_to_postfix());
	EXPECT_EQ("2^2 2 + 2/2 -", c.get_pstfix());
};

TEST(TCalculator, can_add) {

	TCalc c;
	c.set_expr("2+2");
	c.get_pstfix();
	EXPECT_EQ(2+2, c.calc());
};

TEST(TCalculator, can_minus) {

	TCalc c;
	c.set_expr("2-2");
	c.get_pstfix();
	EXPECT_EQ(2 - 2, c.calc());
};

TEST(TCalculator, can_multiply) {

	TCalc c;
	c.set_expr("2*2");
	c.get_pstfix();
	EXPECT_EQ(2 * 2, c.calc());
};
TEST(TCalculator, can_divide) {

	TCalc c;
	c.set_expr("2/2");
	c.get_pstfix();
	EXPECT_EQ(2 / 2, c.calc());
};

TEST(TCalculator, can_stepen) {

	TCalc c;
	c.set_expr("2^2");
	c.get_pstfix();
	EXPECT_EQ(pow(2,2), c.calc());
};

TEST(TCalculator, can_calculate_difficult_expr) {

	TCalc c;
	c.set_expr("2+4/2-6*2+20-2^3");
	c.get_pstfix();
	EXPECT_EQ(2 + 4/2-6*2+20-pow(2,3), c.calc());
};

