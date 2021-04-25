#include "Deck.hpp"
#include "URL.hpp"
#include "json.hpp"
#include <string>
#include <stdlib.h>
#include <time.h>


using json = nlohmann::json;

Deck::Deck()
{
    this->theCards = new LinkedList();

    URL* u1 = new URL("https://api.hearthstonejson.com/v1/25770/enUS/cards.json");
    string jsonString = u1->getContents();
    json parsedJson = json::parse(jsonString);

    if(parsedJson.is_array())
    {
        for(int i = 0; i < parsedJson.size(); i++)
        {
            json currValue = parsedJson[i];
            if(currValue.is_object())
            {
                string type =  currValue.value("type", "N/A");
                if(type == "MINION")
                {
                    string name = currValue.value("name", "N/A");
                    int attack = currValue.value("attack", -1);
                    int defense = currValue.value("health", -1);
                    int manaCost = currValue.value("cost", -1);
                    theCards->addEnd(new Card(name, manaCost, attack, defense));
                }
            }
        }
    }


}

void Deck::display()
{
    this->theCards->display();
}

void Deck::shuffle()
{
    srand(time(NULL)); //this seeds us a random number 

    for(int i = 0; i < 1000; i++)
    {
        int pos1 = rand() % this->theCards->getCount(); //gives us a number between 0 - getCount -1
        int pos2 = rand() % this->theCards->getCount();

        while(pos1 == pos2) //defense to make sure we have different random numbers
        {
            int pos2 = rand() % this->theCards->getCount();
        }
        this->theCards->swapPayload(pos1, pos2);
    }
}

Card* Deck::dealCard()
{
    return this->theCards->removeFront();
}