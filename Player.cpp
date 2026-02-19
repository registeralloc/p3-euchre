#include "Player.hpp"

// TODO: Implement Player classes + Player_factory declared in Player.hpp.
class SimplePlayer : public Player
{
public:
    //EFFECTS returns player's name
    const std::string & get_name() const override
    {
        return name;
    }

    //REQUIRES player has less than MAX_HAND_SIZE cards
    //EFFECTS  adds Card c to Player's hand
    void add_card(const Card &c) override
    {
        hand.push_back(c);
    }

    //REQUIRES round is 1 or 2
    //MODIFIES order_up_suit
    //EFFECTS If Player wishes to order up a trump suit then return true and
    //  change order_up_suit to desired suit.  If Player wishes to pass, then do
    //  not modify order_up_suit and return false.
    bool make_trump(const Card &upcard, bool is_dealer,
                            int round, Suit &order_up_suit) const override
    {
        if (round == 1)
        {
            Suit x {upcard.get_suit()};
            int count {};
            
            for (int i {}; i < hand.size(); ++i)
            {
                if (hand[i].is_face_or_ace() && hand[i].is_trump(x))
                {
                    count++;
                }
            }
            
            if (count >= 2)
            {
                order_up_suit = x;
                return true;
            }
            
            return false;
            
        }
        
        if (round == 2)
        {
            Suit x {Suit_next(upcard.get_suit())};
            int count {};
            
            for (int i {}; i < hand.size(); ++i)
            {
                if (hand[i].is_face_or_ace() && hand[i].is_trump(x))
                {
                    count++;
                }
            }
            
            if (count >= 1)
            {
                order_up_suit = x;
                return true;
            }
            
            if (is_dealer)
            {
                order_up_suit = x;
                return true;
            }
            
            return false;
            
        }
    }

    //REQUIRES Player has at least one card
    //EFFECTS  Player adds one card to hand and removes one card from hand.
    void add_and_discard(const Card &upcard) override
    {
        
    }

    //REQUIRES Player has at least one card
    //EFFECTS  Leads one Card from Player's hand according to their strategy
    //  "Lead" means to play the first Card in a trick.  The card
    //  is removed the player's hand.
    Card lead_card(Suit trump) override
    {
        
    }

    //REQUIRES Player has at least one card
    //EFFECTS  Plays one Card from Player's hand according to their strategy.
    //  The card is removed from the player's hand.
    Card play_card(const Card &led_card, Suit trump) override
    {
        
    }
};

class HumanPlayer : public Player
{
 public:
   
    
    
 private:
    std::string name;
    std::vector<Card> hand;
};

//EFFECTS: Returns a pointer to a player with the given name and strategy
//To create an object that won't go out of scope when the function returns,
//use "return new Simple(name)" or "return new Human(name)"
//Don't forget to call "delete" on each Player* after the game is over
Player * Player_factory(const std::string &name, const std::string &strategy);

//EFFECTS: Prints player's name to os
std::ostream & operator<<(std::ostream &os, const Player &p);
