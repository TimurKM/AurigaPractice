#include <iostream>
#include <array>
#include <ctime> // для time()
#include <random>

namespace
{
	const auto numberOfCards = 52;

	enum class CardSuit
	{
		CLUBS,
		DIAMONDS,
		HEARTS,
		SPADES,
		MAX_SUITS
	};

	enum class CardValue
	{
		TWO,
		THREE,
		FOUR,
		FIVE,
		SIX,
		SEVEN,
		EIGHT,
		NINE,
		TEN,
		JACK,
		QUEEN,
		KING,
		ACE,
		MAX_VALUES
	};

	struct Card
	{
		CardSuit suit = CardSuit::MAX_SUITS;
		CardValue value = CardValue::MAX_VALUES;
	};

	void printCard(const Card& card)
	{
		const std::array<std::string, static_cast<int>(CardSuit::MAX_SUITS)> arraySuits = { "C", "D", "H", "S" };
		const std::array<std::string, static_cast<int>(CardValue::MAX_VALUES)> arrayValues = { "2", "3", "4", "5", "6", "7", "8", "9", "10","J", "Q", "K","A" };

		std::cout << arraySuits[static_cast<int>(card.suit)] << arrayValues[static_cast<int>(card.value)] << std::endl;

		/*switch (card.suit)
		{
		case CardSuit::CLUBS:
			std::cout << "C";
			break;
		case CardSuit::DIAMONDS:
			std::cout << "D";
			break;
		case CardSuit::HEARTS:
			std::cout << "H";
			break;
		case CardSuit::SPADES:
			std::cout << "S";
			break;
		default:
			break;
		}

		switch (card.value)
		{
		case CardValue::TWO:
			std::cout << "2";
			break;
		case CardValue::THREE:
			std::cout << "3";
			break;
		case CardValue::FOUR:
			std::cout << "4";
			break;
		case CardValue::FIVE:
			std::cout << "5";
			break;
		case CardValue::SIX:
			std::cout << "6";
			break;
		case CardValue::SEVEN:
			std::cout << "7";
			break;
		case CardValue::EIGHT:
			std::cout << "8";
			break;
		case CardValue::NINE:
			std::cout << "9";
			break;
		case CardValue::TEN:
			std::cout << "10";
			break;
		case CardValue::JACK:
			std::cout << "J";
			break;
		case CardValue::QUEEN:
			std::cout << "Q";
			break;
		case CardValue::KING:
			std::cout << "K";
			break;
		case CardValue::ACE:
			std::cout << "A";
			break;
		default:
			break;
		}*/
	}

	void printDeck(const std::array<Card, numberOfCards>& deck)
	{
		for (const auto& card : deck)
		{
			printCard(card);
		}
	}

	void swapCards(Card& card1, Card& card2)
	{
		std::swap(card1, card2);
	}

	void shuffleDeck(std::array<Card, numberOfCards>& deck)
	{
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> dist(0, 51);

		for (size_t i = 0; i < numberOfCards; ++i)
		{
			auto swapIndex = dist(rng);
			swapCards(deck[i], deck[swapIndex]);
		}
	}

	int getCardValue(const Card& card)
	{
		auto value = 0;

		if (static_cast<int>(card.value) + 2 < 10)
		{
			value = static_cast<int>(card.value) + 2;
		}
		else if (static_cast<int>(card.value) < static_cast<int>(CardValue::ACE))
		{
			value = 10;
		}
		else
		{
			value = 11;
		}

		/*switch (card.value)
		{
		case CardValue::TWO:
			value = 2;
			break;
		case CardValue::THREE:
			value = 3;
			break;
		case CardValue::FOUR:
			value = 4;
			break;
		case CardValue::FIVE:
			value = 5;
			break;
		case CardValue::SIX:
			value = 6;
			break;
		case CardValue::SEVEN:
			value = 7;
			break;
		case CardValue::EIGHT:
			value = 8;
			break;
		case CardValue::NINE:
			value = 9;
			break;
		case CardValue::TEN:
		case CardValue::JACK:
		case CardValue::QUEEN:
		case CardValue::KING:
			value = 10;
			break;
		case CardValue::ACE:
			value = 11;
			break;
		default:
			break;
		}*/

		return value;
	}
}

int main()
{
	std::array<Card, numberOfCards> deck;

	for (size_t suit = 0, cardCounter = 0; suit < static_cast<int>(CardSuit::MAX_SUITS); ++suit)
	{
		for (size_t value = 0; value < static_cast<int>(CardValue::MAX_VALUES); ++value)
		{
			if (cardCounter < numberOfCards)
			{
				deck[cardCounter].suit = static_cast<CardSuit>(suit);
				deck[cardCounter].value = static_cast<CardValue>(value);
				++cardCounter;
			}
			else
			{
				break;
			}
		}
	}

	printDeck(deck);

	shuffleDeck(deck);

	std::cout << "This is shuffled deck" << std::endl;

	printDeck(deck);

	return 0;
}

