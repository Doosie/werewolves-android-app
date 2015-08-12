#include "characters.h"

#include <QDebug>

Characters::Characters()
{

}

void Characters::constructUserChars(std::set<QString> checked)
{
    // set UserChars as the buttons checked in characterScreen and add the werewolves (which aren't selectable in charScreen)
    UserCharacters::userChars = std::vector<QString>(checked.begin(), checked.end());
    UserCharacters::userChars.push_back("Werewolves");

    // Go through the list of possible characters
    for (auto charInfoIter = Characters::charOrderInfo.begin();
         charInfoIter != Characters::charOrderInfo.end(); ++charInfoIter) {
        // if their buttons have been checked


        if (checked.find(charInfoIter->first) != checked.end() || charInfoIter->first == "Werewolves") {

            // add them to the list of user selected characters; add them to EveryNight if their role can have an action each night
            if (!(charInfoIter->second))
                UserCharacters::userCharsEveryNight.push_back(charInfoIter->first);
            UserCharacters::userCharsFirstNight.push_back(charInfoIter->first);
            if (charInfoIter->first == "Cupido")
                UserCharacters::userCharsFirstNight.push_back((++charInfoIter)->first);
        }
    }
}


std::map<QString, QString> Characters::nightCharInfo = {
    {"Thief", "<i>The Thief wakes up.</i><br><br>Show The Thief the two face down cards in the centre, \
if both are Werewolves the thief must trade his card.<br><br><i>The Thief falls asleep.</i>"},

    {"Cupido", "<i>Cupido wakes up, and chooses two players to fall in love.</i><br><br>\
<i>Cupido falls asleep.</i>"},

    {"Lovers", "<i>The Lovers wake up, recognise one another and fall back into blissful sleep.</i>"},

    {"Two Sisters", "<i>The Two Sisters wake up, recognise one another and fall back to sleep.</i>"},

    {"Three Brothers", "<i>The Three Brothers wake up, recognise one another and fall back to sleep.</i>"},

    {"Stuttering Judge", "<i>The Stuttering Judge wakes up, shows their \
sign and falls asleep.</i><br><br>Watch for this sign during the villagers' vote."},

    {"Wild Child", "<i>The Wild Child wakes up, chooses their role model and falls asleep.</i>"},

    {"Fortune Teller", "<i>The Fortune Teller wakes up, and chooses a player whose true personality \
they want to know</i><br><br>Show the Fortune Teller the character card of the chosen player.\
<br><br><i>The Fortune Teller falls asleep</i>"},

    {"Wolf Hound", "<i>If the Wolf Hound wishes to become a werewolf, wake up with them, otherwise \
keep your eyes close.</i>"},

    {"Werewolves", "<i>The Werewolves wake up, recognise one another and choose a new victim.</i>\
<br><br>In the morning reveal the results.<br><br><i>The Werewolves fall asleep again, after \
fulfilling their lycanthropic needs.</i>"},

    {"Cursed Wolf-Father", "<i>The Cursed Wolf-Father, raise your hand if you wish to curse the \
victim.</i><br><br>If the Cursed Wolf-Father curses the victim, touch the player and he/she \
immediately becomes a Werewolf."},

    {"Big Bad Wolf", "<i>The Big Bad Wolf wakes up, and chooses a second victim.</i><br><br>The Big \
Bad Wolf only wakes up if no Werewolf, Wild Child or Wolf Hound has been killed.<br><br>\
<i>The Big Bad Wolf falls asleep.</i>"},

    {"White Werewolf", "<i>The White Werewolf wakes up, and may choose a werewolf to devour.</i>\
<br><br>The White Werewolf only wakes up every other night."},

    {"Fox", "<i>The Fox wakes up, and chooses a group of three neighbouring players, indicating the \
centre player.</i><br><br>If there is a Werewolf in the group of three players, give a \
positive gesture to The Fox.<br><br><i>The Fox falls asleep.</i>"},

    {"Witch", "<i>The Witch wakes up, and I'll show you the victim of the Werewolves. Would you like \
to use your potion of healing or poison?</i><br><br>If the Witch uses a potion, he/she \
indicates by showing a thumb-up for healing, thumbs-down for poisoning. If poisoning is used, \
the Witch indicates which player is to be poisoned.<br><br><i>The Witch falls asleep.</i>"},

    {"Actor", "<i>The Actor wakes up, and may choose a card.</i><br><br>The Actor chooses one of three \
character cards. He/she can use the corresponding power until the next night. If they choose \
to use a card, remove the card from the game.<br><br><i>The Actor falls asleep.</i>"},

    {"Bear Tamer", "Grunt if the Bear Tamer is the direct neighbour of a werewolf."}
};

std::map<QString, QString> Characters::helpVanillaCharInfo = {
    {"Thief", "If the Thief is used, two additional ordinary Townsfolk cards are added to the deck at \
the beginning of the game. After the cards are shuffled and dealt, the two extra cards are placed \
face down in the centre of the table. During the preliminary turn of the first night, the Thief \
looks at these two cards. However if both cards are Werewolves, the Thief must trade his card \
with one of them. If the Thief takes one of the extra cards, he/she assumes the role of this \
character for the rest of the game."},

    {"Cupido", "During the first night of the game, Cupido designates two players who will be \"in \
love\" with one another for the rest of the game. Cupido can choose him/herself as one of the \
lovers. If one of the lovers dies, the other immediately kills his/herself in a fit of grief. \
A Lover cannot, even as a bluff, vote to lynch their lover. \nSpecial case: If one of the \
lovers is a Werewolf and the other one is a Townsperson, the object of the game changes for \
these two players. The pair's only wish is to love in love and peace, and therefore must \
eliminate all other players from the game."},

    {"Fortune Teller", "Each night, the Fortune Teller can see the true personality of one player. \
The Fortune Teller chooses which player this will be. The fortune teller must help the other Townsfolk \
to correctly identify the Werewolves, without being discovered out by the Werewolves, thus making \
him/herself a target."},

    {"Werewolves", "Each night, the Werewolves bite, kill and devour one Townsperson. During the \
day they try to conceal their identity and vile deeds from the Townsfolk. Depending upon the number \
of players and variants used in the game, there are 1, 2, 3 or 4 Werewolves in play."},

    {"Witch", "This Townsperon knows how to make two very powerful potions:\nThe first is a healing \
potion, which can be used to resurrect a player that is killed by a Werewolf. The second is a poison, \
used during the night to eliminate one player.\nEach potion can only be used once per game. The Witch \
can use either potion on him/herself if he/she wishes."},

    {"Hunter", "If the hunter is killed by the Werewolves, or lynched by the Townsfolk, he/she can \
retaliate. With his/her dying breath, the hunter will shoot, thus eliminating, any one other player."},

    {"Little Girl", "The Little Girl is very curious. She can open her eyes dyring the night to spy \
on the Werewolves.\nHowever, if she is caught in the act by the Werewolves, she immediately dies of \
fright, silently, instead of the designated victim.\nThe Little Girl can spy during the night only \
during the \"Werewolves awaking\" phase. When the Little Girl is in play, it is necessary for all \
players to avoid hiding their faces when sleeping."},

    {"Ordinary Townsfolk", "These folks have no abilities other than their own intuition.\n\
Each Ordinary Townsperson must analyse the players' behaviour to guess who is a Werewolf, \
and try not to be mistaken for a Werewolf and unduly lynched, hanged and burned."},

    {"Sheriff", "Instead of being dealt like the rest of the characters, this card is entrusted to \
one of the players.\nJust like a real Sheriff, this player is elected by a vote of the Townsfolk. \
The player recieving the most votes gets to be the Sheriff.\nOnce elected, the Sheriff cannot refuse \
the honor. Henceforth, this player's votes count as 2 votes (always applied to a single player, not \
split). If the Sheriff is eliminated, upon his/her deathbed, the Sheriff names a successor, who then \
becomes the new Sheriff."}
};


std::map<QString, QString> Characters::helpExpansCharInfo = {
    {"Two Sisters", "The first night, upon the narrator's call, they wake together and \
recognise one another."},

    {"Three Brothers", "The first night, upon the narrator's call, they wake together and \
recognise one another."},

    {"Stuttering Judge", "Once per game, the Stuttering Judge can decide that there will be 2 \
consecutive votes and two suspect eliminations. The Stuttering Judge lets the narrator know \
their decisions using a specific distinctive sign used to designate an inhabitant during the \
villager’s vote. The second vote starts immediately after the first one without debate. The \
\"St-st-stuttering Ju-ju-judge\" will have shown their distinctive sign during the first night, \
upon the narrator’s call."},

    {"Wild Child", "The Wild Child is a Villager. The first night, upon the Narrator’s call, the \
Child chooses a role model. If during the game, that model is eliminated, the Wild Child becomes \
a werewolf and will wake up the following night with his brethren, to devour with them each night \
until the end of the game.\nHowever, as long as his model is alive, the Wild Child remains a \
Villager. Whether or not his role model is a Werewolf makes no difference!\nNothing keeps the Wild \
Child from taking part in the elimination of his role model if he so desires.\nIf his role model \
is alive when all the Werewolves are eliminated he wins with the Villagers. If his model is \
eliminated and the Werewolves win then it’s also a victory for our Wild Child."},

    {"Wolf Hound", "On the first night, he decides if he wants to be a Simple Villager or a \
Werewolf. If he wants to be a Werewolf he’ll wake up with them each night from then on and will \
take part in the choosing of the devoured victim. Otherwise, he keeps his eyes closed and will win \
with the Villagers.\n(This choice is final)"},

    {"Cursed Wolf-Father", "Each night, he wakes up and devours with the other Werewolves. But if \
he so wishes, after the Werewolves have gone to sleep, he raises his hand. That means that the victim \
isn’t devoured, but is instead cursed.\nThe cursed Wolf Father can only use his special power once \
per game. The narrator touches the cursed inhabitant who then immediately (and secretly) becomes a \
werewolf – that character will now partake each night in the Werewolves’ feast. If the Character had \
a nocturnal power, he will be woken up by the narrator the following turns to use that power, in \
addition to being called with the Werewolves."},

    {"Big Bad Wolf", "Each night, he wakes up and devours with the other Werewolves. But as long \
as no Werewolf, Wild Child, or Wolf hound has been eliminated, he wakes up alone a second time and \
devours another victim. He cannot devour a Werewolf."},

    {"White Werewolf", "Each night, he wakes up and devours with the other Werewolves. But every \
other night, upon the Narrator’s call, he wakes up alone and can eliminate a Werewolf. The goal \
of this character is to be the sole survivor in the village. In that case, and only that case, \
he wins the game."},

    {"Fox", "At night, upon the Narrator’s call, the Fox can designate a group of three neighboring \
players, of which he points to the center player. If in that group is at least one Werewolf, then \
the narrator makes a positive gesture to the Fox. In that case, the Fox will be able to use his \
power again the next night. If no Werewolf is among the chosen group, the Fox loses his power for \
good; however, he has important information for clearing three players at once."},


    {"Actor", "Before the game, the narrator chooses 3 character cards with special powers. After \
the distribution of the roles, these cards are placed face-down in the middle of the table.\n\
Each night, upon the Narrator’s call, the Actor can choose one of these cards and use the \
corresponding power until the next night. If the Actor uses a character card, the narrator \
removes that card from the table. It can no longer be used."},

    {"Bear Tamer", "Each morning, right after the revelation of any nocturnal victims, if at \
least one Werewolf is or becomes the direct neighbor of the Bear Tamer, then the Narrator \
grunts to tell the players that the Tamer’s bear has smelled the danger.\n\
(Only the neighbors still in play are taken into account.)"},

    {"Prejudiced Manipulator", "Before the beginning of the game, the Narrator divides the village \
into 2 groups, according to an obvious criterion (gender, glasses, size, age, etc.) and announces \
it out loud to the village. The Prejudiced Manipulator will obviously be part of one of these two \
groups. The goal of that character is the elimination of all the players from the group he doesn’t \
belong to. In that case, and only in that case, he wins the game. He has no special powers: his \
skill at manipulating the inhabitants of the village is his only weapon!"},

    {"Angel", "If the Angel manages to attract the discriminatory vote of the villagers, or the \
devouring vindictiveness of the lycanthropes to be eliminated during the first turn, he’ll \
be able to successfully leave his nightmare and win the game. The game ends: the players can \
immediately begin a new game.\nIf he fails he becomes a simple villager for the rest of the game."},

    {"Knight with the Rusty Sword", "If the Knight is devoured, he is eliminated, but one of \
the Werewolves becomes diseased from the rusted sword’s wound. From among the Werewolves guilty \
of the elimination, the first Werewolf to the left of the Knight with the Rusty Sword will be \
eliminated the following night. This elimination caused by disease will be revealed in the morning \
by the narrator after the disappearance of the Werewolf, who will thus have survived for a full day."},

    {"Devoted Servant", "Before revealing the card of the player killed by the village’s vote, she \
can reveal herself by showing her card. In that case, the Devoted Servant loses her card and gains \
the card of the eliminated played until the end of the game.\nNote: If she is one the lovers, the \
Devoted Servant cannot use her power, as her love is stronger than her desire to change characters."},

    {"Villager-Villager", "On both of its sides, this card has the illustration of a simple \
villager. Upon distribution, the village will thus have the absolute certainty that its owner \
is truly an innocent Simple Villager."}

};



// Name, Action(No Action = 0, First Night = 1, Every Night = 2), Expansion (Vanilla = false, Characters = true);
std::vector<std::pair<QString, bool>> Characters::charOrderInfo = {
    {"Bear Tamer", true},
    {"Thief", true},
    {"Cupido", true},
    {"Lovers", true},
    {"Two Sisters", true},
    {"Three Brothers", true},
    {"Stuttering Judge", true},
    {"Wild Child", true},
    {"Fortune Teller", false},
    {"Wolf Hound", true},
    {"Werewolves", false},
    {"Cursed Wolf-Father", false},
    {"Big Bad Wolf", false},
    {"White Werewolf", false},
    {"Fox", false},
    {"Witch", false},
    {"Actor", false}
};




std::vector<QString>UserCharacters::userChars;
std::vector<QString> UserCharacters::userCharsFirstNight;
std::vector<QString> UserCharacters::userCharsEveryNight;

