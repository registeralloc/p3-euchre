#include "Card.hpp"
#include "unit_test_framework.hpp"
#include <iostream>
using namespace std;

TEST(suit_next)
{
    ASSERT_EQUAL(Suit_next(SPADES), CLUBS);
    ASSERT_EQUAL(Suit_next(HEARTS), DIAMONDS);
    ASSERT_EQUAL(Suit_next(CLUBS), SPADES);
    ASSERT_EQUAL(Suit_next(DIAMONDS), HEARTS);
}

TEST(test_constructor_base_case)
{
    Card card;
    ASSERT_EQUAL(card.get_rank(), TWO);
    ASSERT_EQUAL(card.get_suit(), SPADES);
}

TEST(test_constructor_with_inputs)
{
    Card card(JACK, SPADES);
    ASSERT_EQUAL(card.get_rank(), JACK);
    ASSERT_EQUAL(card.get_suit(), SPADES);
}

TEST(get_suit)
{
    Card card(JACK, CLUBS);
    ASSERT_EQUAL(card.get_suit(SPADES), SPADES);
    
    
}

//Test for true and false cases
TEST(test_is_face_or_ace)
{
    Card a(ACE, SPADES);
    ASSERT_TRUE(a.is_face_or_ace());
    
    Card b(FIVE, SPADES);
    ASSERT_FALSE(b.is_face_or_ace());
    
    Card c(KING, CLUBS);
    ASSERT_TRUE(c.is_face_or_ace());
    
    Card d(TWO, CLUBS);
    ASSERT_FALSE(d.is_face_or_ace());
    
    Card e(QUEEN, HEARTS);
    ASSERT_TRUE(e.is_face_or_ace());
    
    Card f(TWO, HEARTS);
    ASSERT_FALSE(f.is_face_or_ace());
    
    Card g(JACK, DIAMONDS);
    ASSERT_TRUE(g.is_face_or_ace());
    
    Card h(SEVEN, DIAMONDS);
    ASSERT_FALSE(h.is_face_or_ace());
}

TEST(is_right_bower)
{
    Card a(JACK, DIAMONDS);
    ASSERT_TRUE(a.is_right_bower(DIAMONDS));
    ASSERT_FALSE(a.is_right_bower(SPADES));
    ASSERT_FALSE(a.is_right_bower(CLUBS));
    
    Card b(ACE, DIAMONDS);
    ASSERT_FALSE(b.is_right_bower(HEARTS));
}

TEST(is_left_bower)
{
    Card a(JACK, DIAMONDS);
    ASSERT_TRUE(a.is_left_bower(HEARTS));
    ASSERT_FALSE(a.is_left_bower(DIAMONDS));
    ASSERT_FALSE(a.is_left_bower(SPADES));
    
    Card b(ACE, DIAMONDS);
    ASSERT_FALSE(b.is_left_bower(HEARTS));
}

TEST(is_trump)
{
    Card a(ACE, SPADES);
    ASSERT_TRUE(a.is_trump(SPADES));
    ASSERT_FALSE(a.is_trump(DIAMONDS));
    
    Card b(JACK, DIAMONDS);
    ASSERT_TRUE(b.is_trump(HEARTS));
    ASSERT_FALSE(b.is_trump(SPADES));
}
// Repeat structure for operators
TEST(less_than_operator)
{
    Card a(ACE, SPADES);
    Card b(KING, SPADES);
    ASSERT_TRUE(b < a);
    ASSERT_FALSE(a < b);
    
    //equals
    Card c(ACE, SPADES);
    Card d(ACE, SPADES);
    ASSERT_FALSE(d < c);
    ASSERT_FALSE(c < d);
}

TEST(less_than_equal_operator)
{
    Card a(ACE, SPADES);
    Card b(KING, SPADES);
    ASSERT_TRUE(b <= a);
    ASSERT_FALSE(a <= b);
    
    //equals
    Card c(ACE, SPADES);
    Card d(ACE, SPADES);
    ASSERT_TRUE(d <= c);
    ASSERT_TRUE(c <= d);
}

TEST(greater_than_operator)
{
    Card a(ACE, SPADES);
    Card b(KING, SPADES);
    ASSERT_TRUE(a > b);
    ASSERT_FALSE(b > a);
    
    //equals
    Card c(ACE, SPADES);
    Card d(ACE, SPADES);
    ASSERT_FALSE(c > d);
    ASSERT_FALSE(d > c);
}

TEST(greater_than_equal_operator)
{
    Card a(ACE, SPADES);
    Card b(KING, SPADES);
    ASSERT_TRUE(a >= b);
    ASSERT_FALSE(b >= a);
    
    //equals
    Card c(ACE, SPADES);
    Card d(ACE, SPADES);
    ASSERT_TRUE(c >= d);
    ASSERT_TRUE(d >= c);
}

TEST(equal_operator)
{
    Card a(ACE, SPADES);
    Card b(KING, SPADES);
    ASSERT_FALSE(b == a);
    ASSERT_FALSE(a == b);
    
    //equals
    Card c(ACE, SPADES);
    Card d(ACE, SPADES);
    ASSERT_TRUE(d == c);
    ASSERT_TRUE(c == d);
}

TEST(not_equal_operator)
{
    Card a(ACE, SPADES);
    Card b(KING, SPADES);
    ASSERT_TRUE(b != a);
    ASSERT_TRUE(a != b);
    
    //equals
    Card c(ACE, SPADES);
    Card d(ACE, SPADES);
    ASSERT_FALSE(d != c);
    ASSERT_FALSE(c != d);
}

// 3 P
TEST(card_less_trump)
{
    Card a(ACE, SPADES);
    Card b(JACK, SPADES);
    ASSERT_FALSE(Card_less(a, b, DIAMONDS));
    
    Card c(ACE, SPADES);
    Card d(ACE, SPADES);
    ASSERT_FALSE(Card_less(c, d, SPADES));
    
    Card e(TWO, SPADES);
    Card f(ACE, HEARTS);
    ASSERT_FALSE(Card_less(e, f, SPADES));
    
    Card g(ACE, SPADES);
    Card h(KING, SPADES);
    ASSERT_FALSE(Card_less(g, h, SPADES));
    
    //Bowers
    Card i(JACK, SPADES);
    Card j(JACK, CLUBS);
    ASSERT_FALSE(Card_less(i, j, SPADES));
    ASSERT_TRUE(Card_less(j, i, SPADES));
}

// 4 P
TEST(card_less_trump_led)
{
    Card led(TEN, DIAMONDS);
    Card a(ACE, SPADES);
    Card b(ACE, HEARTS);
    ASSERT_FALSE(Card_less(a, b, led, SPADES));
    
    Card c(TEN, DIAMONDS);
    Card d(ACE, HEARTS);
    ASSERT_FALSE(Card_less(c, d, led, SPADES));
    
    Card e(ACE, DIAMONDS);
    Card f(KING, DIAMONDS);
    ASSERT_FALSE(Card_less(e, f, led, SPADES));
    
    // Neither led or trump
    Card g(ACE, HEARTS);
    Card h(KING, HEARTS);
    ASSERT_TRUE(Card_less(h, g, led, SPADES));
    
    // Trump vs LED
    Card i(ACE, SPADES);
    Card j(ACE, DIAMONDS);
    ASSERT_TRUE(Card_less(j, i, led, SPADES));
}

TEST_MAIN()
