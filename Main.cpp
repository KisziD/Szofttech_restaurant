#include "Main.h"
#include <algorithm>

Main::Main()
{
    cout << "asd";
}

void Main::readMap()
{
    ifstream fr("timetable.txt");
    string row;
    vector<string> splitRow;
    while (getline(fr, row)) {
        splitRow = split(row, ";");
        vector<bool> tables;
        for (int i = 1; i < 7; i++) {
            if (splitRow[i] == "true") {
                tables.push_back(true);
            }
            else {
                tables.push_back(false);
            }

        }
        timetable[splitRow[0].c_str()] = tables;
    }

}

vector<string> Main::split(const string& str, const string& delim)
{
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos - prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    } while (pos < str.length() && prev < str.length());
    return tokens;
}
