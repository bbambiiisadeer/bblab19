#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string filename, vector<string> &names, vector<int> &scores, vector<char> &grades){
    ifstream source(filename.c_str());
    string text;
    while(getline(source, text)){
        int i = 0;

            char format[] = "%[^:]: %d %d %d";
            char a[100];
            int b, c, d;
            sscanf(text.c_str(),format, a, &b, &c, &d);
            names.push_back(a);
            scores.push_back(b + c + d);
            int score = b + c + d;
            char e = score2grade(score);
            grades.push_back(e);
            i++;    
        
    }

}

void getCommand(string &command, string &key){
    cout << "Please input your command: ";
    string x;
    int start = 0;
    getline(cin,x);
    int j = x.find_first_of(" ");
    command = x.substr(start,j);
    key = x.substr(j+1,x.size());
}

void searchName(vector<string> names, vector<int> scores, vector<char> grades, string key){
    bool flag = 0;
    cout << "---------------------------------\n";
    for(unsigned int i = 0; i < names.size(); i++){
        if(key == toUpperStr(names[i])){
            cout << names[i] << "'s score = " << scores[i] << "\n" << names[i] << "'s grade = " << grades[i] << endl;
            flag = 1;
        }
    }
    if(flag == 0){
            cout << "Cannot found." << endl;
    }
    cout << "---------------------------------\n";
}

void searchGrade(vector<string> names, vector<int> scores, vector<char> grades, string key){
    bool flag = 0;
    cout << "---------------------------------\n";
    for(unsigned int i = 0; i < names.size(); i++){
        grades[i] = toupper(grades[i]);
        if(key[0] == grades[i]){
            cout << names[i] << " " << "(" << scores[i] << ")" << "\n";
            flag = 1;
        }
    }
    if(flag == 0){
            cout << "Cannot found.";
               
    }
    cout << "---------------------------------\n"; 
}



int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}
