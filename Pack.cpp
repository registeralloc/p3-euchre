#include "Pack.hpp"

// TODO: Implement Pack member functions declared in Pack.hpp.

// Initializes the Pack to be in the following standard order:
//          the cards of the lowest suit arranged from lowest rank to
//          highest rank, followed by the cards of the next lowest suit
//          in order from lowest to highest rank, and so on.
Pack::Pack() : next(0)
{
    int count {0};
    
    for (int i {SPADES}; i <= DIAMONDS; ++i)
    {
        for (int j {NINE}; j <= ACE; ++j)
        {
            cards[count] = Card(static_cast<Rank>(j), static_cast<Suit>(i));
            ++count;
        }
    }
}


Pack::Pack(std::istream& pack_input);



