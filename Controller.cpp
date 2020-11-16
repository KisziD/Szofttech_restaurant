#include "Controller.h"
#include <algorithm>

Controller::Controller(){
}

void Controller::readMap()
{
    ifstream fr("timetable.txt");
    string row;
    vector<string> splitRow;
    while (getline(fr, row)) {
        splitRow = split(row, "!");        
        timetable[splitRow[0].c_str()] = splitRow[1];
    }

}

vector<string> Controller::split(const string& str, const string& delim)
{
    vector<string> tokens;
    unsigned int prev = 0, pos = 0;
    do {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos - prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    } while (pos < str.length() && prev < str.length());
    return tokens;
}
