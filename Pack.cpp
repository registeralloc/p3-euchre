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

// Initializes Pack by reading from pack_input.
Pack::Pack(std::istream& pack_input) : next(0)
{
    for (int i {0}; i < 24; ++i)
    {
        pack_input >> cards[i];
    }
};

// Returns the next card in the pack and increments the next index
Card Pack::deal_one()
{
    Card i {cards[next]};
    ++next;
    return i;
}

// Resets next index to first card in the Pack
void Pack::reset()
{
    next = 0;
}

// Shuffles the Pack and resets the next index. This performs an in shuffle seven times.
void Pack::shuffle()
{
    for (int i{0}; i < 7; ++i)
    {
        std::array<Card, PACK_SIZE> x;
        
        for (int j {0}; j < 12; ++j)
        {
            x[2 * j] = cards[j + 12];
            x[2 * j + 1] = cards[j];
        }
        // Cards copies x
        cards = x;
    }
    // reset index
    next = 0;
    
}

bool Pack::empty() const
{
    if (next >= PACK_SIZE)
    {
        return true;
    }
    
    return false;
    
}
