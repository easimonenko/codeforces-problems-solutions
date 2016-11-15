#include <iostream>
#include <string>
#include <list>
#include <set>
#include <map>

using namespace std;

int main(int argc, char* argv[]) {
#ifdef __DEBUG__
    //freopen("A_1.in", "r", stdin);
#endif
    int n;
    cin >> n;
    list<pair<string,int> > records;
    for (int i = 0; i < n; i++) {
        static string name;
        static int score;
        cin >> name >> score;
        records.push_back(pair<string,int>(name,score));
    }
    map<string,int> scores;
    for (list<pair<string,int> >::iterator it = records.begin(); it != records.end(); it++) {
        scores[it->first] += it->second;
    }
    int m = scores.begin()->second;
    set<string> names;
    names.insert(scores.begin()->first);
    for (map<string,int>::iterator it = scores.begin(); it != scores.end(); it++) {
        if (it->second == m) {
            names.insert(it->first);
            continue;
        }
        if (it->second > m) {
            m = it->second;
            names.clear();
            names.insert(it->first);
        }
    }
    
    if (names.size() == 1) {
        cout << *(names.begin()) << endl;
    } else {
        // вновь моделируем игру
        map<string,int> scores;
        for (list<pair<string,int> >::iterator it = records.begin(); it != records.end(); it++) {
            static string name;
            name = it->first;
            scores[name] += it->second;
            if (scores[name] >= m && names.find(name) != names.end()) {
                cout << name << endl;
                break;
            }
        }
    }

    return 0;
}
