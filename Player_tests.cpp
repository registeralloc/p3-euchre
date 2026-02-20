#include "Player.hpp"
#include "unit_test_framework.hpp"

#include <iostream>

using namespace std;

TEST(test_player_get_name) {
    Player * alice = Player_factory("Alice", "Simple");
    ASSERT_EQUAL("Alice", alice->get_name());

    delete alice;
}

// Add more tests here

TEST(make_trump_one_ou)
{
    Player *p {Player_factory("Player", "Simple")};
    
    p -> add_card(Card(ACE, SPADES));
    p -> add_card(Card(KING, SPADES));
    p -> add_card(Card(NINE, SPADES));
    p -> add_card(Card(TEN, HEARTS));
    p -> add_card(Card(NINE, DIAMONDS));
    
    // Upcard and trump
    Card upcard(KING, SPADES);
    Suit trump;
    
    ASSERT_TRUE(p -> make_trump(upcard, false, 1, trump));
    ASSERT_EQUAL(trump, SPADES);
    
    // delete
    delete p;
}

TEST(make_trump_one_p)
{
    Player *p {Player_factory("Player", "Simple")};
    
    p -> add_card(Card(ACE, SPADES));
    p -> add_card(Card(TEN, SPADES));
    p -> add_card(Card(NINE, SPADES));
    p -> add_card(Card(TEN, HEARTS));
    p -> add_card(Card(NINE, DIAMONDS));
    
    // Upcard and trump
    Card upcard(KING, SPADES);
    Suit trump;
    
    ASSERT_FALSE(p -> make_trump(upcard, false, 1, trump));
    
    // delete
    delete p;
    
}

TEST(make_trump_two_ou)
{
    Player *p {Player_factory("Player", "Simple")};
    
    p -> add_card(Card(ACE, CLUBS));
    p -> add_card(Card(NINE, SPADES));
    p -> add_card(Card(TEN, SPADES));
    p -> add_card(Card(TEN, HEARTS));
    p -> add_card(Card(TEN, DIAMONDS));
    
    // Upcard and trump
    Card upcard(KING, SPADES);
    Suit trump;
    
    ASSERT_TRUE(p -> make_trump(upcard, false, 2, trump));
    ASSERT_EQUAL(trump, CLUBS);
    
    // delete
    delete p;
}

TEST(make_trump_dealer)
{
    Player *p {Player_factory("Player", "Simple")};
    
    p -> add_card(Card(ACE, SPADES));
    p -> add_card(Card(NINE, SPADES));
    p -> add_card(Card(TEN, SPADES));
    p -> add_card(Card(NINE, HEARTS));
    p -> add_card(Card(NINE, DIAMONDS));
    
    // Upcard and trump
    Card upcard(KING, SPADES);
    Suit trump;
    
    ASSERT_TRUE(p -> make_trump(upcard, true, 2, trump));
    ASSERT_EQUAL(trump, CLUBS);
    
    // delete
    delete p;
}

TEST(make_trump_two_p)
{
    Player *p {Player_factory("Player", "Simple")};
    
    p -> add_card(Card(ACE, SPADES));
    p -> add_card(Card(NINE, SPADES));
    p -> add_card(Card(TEN, SPADES));
    p -> add_card(Card(NINE, HEARTS));
    p -> add_card(Card(TEN, DIAMONDS));
    
    // Upcard and trump
    Card upcard(KING, SPADES);
    Suit trump;
    
    ASSERT_FALSE(p -> make_trump(upcard, false, 2, trump));
    
    // delete
    delete p;
}

TEST(make_trump_bower)
{
    Player *p {Player_factory("Player", "Simple")};
    
    p -> add_card(Card(JACK, CLUBS));
    p -> add_card(Card(ACE, SPADES));
    p -> add_card(Card(NINE, HEARTS));
    p -> add_card(Card(TEN, HEARTS));
    p -> add_card(Card(TEN, DIAMONDS));
    
    // Upcard and trump
    Card upcard(KING, SPADES);
    Suit trump;
    
    ASSERT_TRUE(p -> make_trump(upcard, false, 1, trump));
    ASSERT_EQUAL(trump, SPADES);
    
    // delete
    delete p;
}

TEST(add_and_discard)
{
    Player *p {Player_factory("Player", "Simple")};
    
    p -> add_card(Card(ACE, SPADES));
    p -> add_card(Card(TEN, SPADES));
    p -> add_card(Card(NINE, SPADES));
    p -> add_card(Card(TEN, HEARTS));
    p -> add_card(Card(NINE, DIAMONDS));
    
    // use lead card
    p -> add_and_discard(Card(KING, SPADES));
    
    Card a {p -> lead_card(SPADES)};
    ASSERT_EQUAL(a, Card(TEN, HEARTS));
                         
    delete p;
}

// NO add and discard
TEST(lead_card_both_types)
{
    Player *p {Player_factory("Player", "Simple")};
    
    p -> add_card(Card(ACE, SPADES));
    p -> add_card(Card(TEN, SPADES));
    p -> add_card(Card(NINE, SPADES));
    p -> add_card(Card(NINE, HEARTS));
    p -> add_card(Card(NINE, DIAMONDS));
    
    Card a {p -> lead_card(SPADES)};
    ASSERT_EQUAL(a, Card(NINE, HEARTS));
                         
    delete p;
}

//Same as above change suit
TEST(lead_card_trump)
{
    Player *p {Player_factory("Player", "Simple")};
    
    p -> add_card(Card(ACE, SPADES));
    p -> add_card(Card(KING, SPADES));
    p -> add_card(Card(QUEEN, SPADES));
    p -> add_card(Card(TEN, SPADES));
    p -> add_card(Card(NINE, SPADES));
    
    Card a {p -> lead_card(SPADES)};
    ASSERT_EQUAL(a, Card(ACE, SPADES));
                         
    delete p;
}

TEST(play_card_suit_follow)
{
    Player *p {Player_factory("Player", "Simple")};
    
    p -> add_card(Card(ACE, SPADES));
    p -> add_card(Card(NINE, SPADES));
    p -> add_card(Card(TEN, SPADES));
    p -> add_card(Card(TEN, HEARTS));
    p -> add_card(Card(TEN, DIAMONDS));
    
    // add led card
    Card led {KING, SPADES};
    Card a {p -> play_card(led, HEARTS)};
    ASSERT_EQUAL(a, Card(ACE, SPADES));
                         
    delete p;
}

TEST(play_card)
{
    Player *p {Player_factory("Player", "Simple")};
    
    p -> add_card(Card(ACE, SPADES));
    p -> add_card(Card(NINE, SPADES));
    p -> add_card(Card(TEN, SPADES));
    p -> add_card(Card(TEN, HEARTS));
    p -> add_card(Card(TEN, DIAMONDS));
    
    // add led card and throw away weakest
    Card led {NINE, CLUBS};
    Card a {p -> play_card(led, HEARTS)};
    ASSERT_EQUAL(a, Card(NINE, SPADES));
                         
    delete p;
    
}

TEST(play_card_bower)
{
    Player *p {Player_factory("Player", "Simple")};
    
    p -> add_card(Card(ACE, SPADES));
    p -> add_card(Card(JACK, CLUBS));
    p -> add_card(Card(TEN, SPADES));
    p -> add_card(Card(TEN, HEARTS));
    p -> add_card(Card(TEN, DIAMONDS));
    
    // left bower follows trump
    Card led {NINE, SPADES};
    Card a {p -> play_card(led, SPADES)};
    ASSERT_EQUAL(a, Card(JACK, CLUBS));
                         
    delete p;
    
}

TEST_MAIN()
