#include "Controller.h"
#include <algorithm>

Controller::Controller(){
    ifstream fr("ulist.txt");
    string fname;
    while (getline(fr, fname)) {
        ifstream ur("users\\"+fname);
        string udata;
        int linenum=0;
        while (getline(ur, udata)) {
            if (linenum == 0) {
                vector<string> data = split(udata, ";");
                if (data[5] == "true") {
                    data.erase(data.end());
                    users.push_back(User(split(udata, ";"),true));
                }
                else {
                    data.erase(data.end()-1);
                    users.push_back(User(split(udata, ";"), false));
                }
                
            }
            else {
                users.end()->newReservation(split(udata, ";"));
            }
        }
    }
    readMap();
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
    fr.close();

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

void Controller::list()
{
    for_each(timetable.cbegin(), timetable.cend(), [](const pair<string, string> iter) {
        cout << iter.first << " : " << iter.second<<endl;
        });

}

void Controller::newUser()
{
    string n, e, p, u, pass;
    cout << "Enter your name: ";
    cin >> n;
    cout << "Enter your email address: ";
    cin >> e;
    cout << "Enter your phonenumber: ";
    cin >> p;
    cout << "Enter your username: ";
    cin >> u;
    bool usercheck = false;
    for_each(users.cbegin(), users.cend(), [u, &usercheck](const User us) {

        if (us.getUname() == u) {
            usercheck = true;
        }});    
    cout << "Enter your password: ";
    cin >> pass;
    if (usercheck) {
        cout << "Username already exists please choose a different one."<<endl;
        newUser();
    }
    else {
        users.push_back(User(n, e, p, u, encryptDecrypt(pass), false));

        ofstream fw("users\\" + u + ".txt");
        fw << n << ";" << e << ";" << p << ";" << u << ";" << encryptDecrypt(pass) << ";" << "false" << endl;
        fw.close();
        fw.open("ulist.txt", std::ios_base::app);
        fw << u << ".txt" << endl;
        fw.close();
    }
}

void Controller::login()
{
    string uname, password;

    cout << "Enter your username: ";
    cin >> uname;
    cout << "Enter your password: ";
    cin >> password;
    for_each(users.cbegin(), users.cend(), [this,uname, password](User us) {
            
        if (us.getUname() == uname && us.getPassword() == encryptDecrypt(password)) {
            currentUser= &us;
        }});
    cout << "Wrong username or password!";
    login();
}

void Controller::listUsers()
{
    for_each(users.cbegin(), users.cend(), [](const User us) {
        cout <<us.getName()<<endl;
        });
}

string Controller::encryptDecrypt(string toEncrypt) {
    char key[3] = { 'D', 'N', 'T' };
    string output = toEncrypt;

    for (unsigned int i = 0; i < toEncrypt.size(); i++)
        output[i] = toEncrypt[i] ^ key[i % (sizeof(key) / sizeof(char))];

    return output;
}
