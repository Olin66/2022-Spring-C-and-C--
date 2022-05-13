#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string *> v;
    string path = "world_cities.csv";
    ifstream ifs;
    ifs.open(path);
    string line;
    while (getline(ifs, line)) {
        auto *items = new string[5];
        int pos = 0;
        int temp = 0;
        int i = 0;
        while (true) {
            if (line[pos++] == ',') {
                items[i++] = line.substr(temp, pos - temp - 1);
                temp = pos;
            }
            if (pos == line.length()) {
                items[i] = line.substr(temp, pos - temp);
                break;
            }
        }
        v.push_back(items);
    }
    ifs.close();
    FILE *wfile;
    wfile = fopen("china_cities.csv", "w");
    if (wfile) {
        for (string *s: v) { 
            if(s[2] == "China")
            fprintf(wfile, "%s,%s,%s,%s,%s\n", s[0].c_str(), s[1].c_str(), s[2].c_str(), s[3].c_str(),
                    s[4].c_str());
        }
    }
    fclose(wfile);
    for(string* s: v) delete[] s;
}