#ifndef CHARACTERS_H
#define CHARACTERS_H

#include <vector>
#include <QString>
#include <map>
#include <set>

class UserCharacters;
class Characters
{
public:
    Characters();

    static std::vector<std::pair<QString, bool>> firstNightCharsInfo;

    static std::map<QString, QString> nightCharInfo;
    static std::map<QString, QString> helpVanillaCharInfo;
    static std::map<QString, QString> helpExpansCharInfo;

    static std::vector<std::pair<QString, bool>> charOrderInfo;


    static void constructUserChars(std::set<QString>);
private:




    // static std::vector<std::pair<QString, QString>> userCharVector;
};

#endif // CHARACTERS_H


class UserCharacters
{
public:
    static std::vector<QString> userChars;
    static std::vector<QString> userCharsFirstNight;
    static std::vector<QString> userCharsEveryNight;
};
