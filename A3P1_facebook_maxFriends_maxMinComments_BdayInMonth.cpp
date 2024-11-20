// #include <iostream>
// #include <vector>
// #include <string>
// #include <ctime>
// #include <climits>
// using namespace std;

// struct User{
//     string name;
//     string date_of_birth;
//     int num_comments;
// };

// string split(const string& strr) {
//     size_t pos = strr.find("-");
//     if (pos != string::npos && pos + 1 < strr.length()) {
//         size_t next_pos = strr.find("-", pos + 1);
//         if (next_pos != string::npos) {
//             return strr.substr(pos + 1, next_pos - pos - 1);
//         }
//     }
//     return "";
// }

// void print_vec(vector<string> ret_vec){
//     cout << "{";
//     string sCol = "'";
//     for(int i=0; i<ret_vec.size(); i++){
//         cout << sCol;
//         cout << ret_vec[i];
//         cout << sCol;
//         if(i < ret_vec.size()-1){
//             cout << ", ";
//         }
//     }
//     cout << "}";
//     cout << endl;
// }

// class FBGraph {
// public:
//     vector<User> users;
//     vector<vector<int>> fList;
    
//     void addUser(string name, string dob, int comments){
//         User newUser = {name, dob, comments};
//         users.push_back(newUser);
//         fList.push_back(vector<int>());
//     }
    
//     void addFriend(int u1_idx, int u2_idx){
//         fList[u1_idx].push_back(u2_idx);
//         fList[u2_idx].push_back(u1_idx);
//     }
    
//     string maxFriend() {
//         int max_ctr = 0;
//         int max_friend_idx = -1;
        
//         for(int i=0; i<fList.size(); i++){
//             if(fList[i].size() > max_ctr){
//                 max_ctr = fList[i].size();
//                 max_friend_idx = i;
//             }
//         }
        
//         if(max_friend_idx != -1){
//             return users[max_friend_idx].name;
//         }
//         else{
//             return "None";
//         }
//     }
    
//     void MaxMinComments(string &max_user, string &min_user){
//         int max_comment = -1;
//         int min_comment = INT_MAX;
//         int max_user_idx = -1;
//         int min_user_idx = -1;
        
//         for(int i=0; i<users.size(); i++){
//             if(users[i].num_comments > max_comment) {
//                 max_comment = users[i].num_comments;
//                 max_user_idx = i;
//             }
            
//             if(users[i].num_comments < min_comment) {
//                 min_comment = users[i].num_comments;
//                 min_user_idx = i;
//             }
//         }
        
//         if (max_user_idx != -1){
//             max_user = users[max_user_idx].name;
//         }
        
//         if (min_user_idx != -1){
//             min_user = users[min_user_idx].name;
//         }
//     }
    
//     void findDOB(){
//         // Get current time
//         time_t t = time(0);
//         // Convert to local time
//         tm *now = localtime(&t);
//         // Get the current month (tm_mon is 0-based, so we add 1)
//         int month_number = now->tm_mon + 1;
//         // Convert the month number to a string
//         string curr_month = to_string(month_number);
        
//         vector<string> ret_vec;
//         for(int i=0; i<users.size(); i++){
//             if(split(users[i].date_of_birth) == curr_month){
//                 ret_vec.push_back(users[i].name);
//             }
//         }
//         print_vec(ret_vec);
//     }
// };


// int main(){
//     FBGraph facebook_graph;
        
//     facebook_graph.addUser("A", "1990-10-15", 35); //0
//     facebook_graph.addUser("B", "1988-10-25", 20); //1
//     facebook_graph.addUser("C", "1995-11-01", 11); //2
//     facebook_graph.addUser("D", "1992-09-10", 50); //3
//     facebook_graph.addUser("E", "1990-10-15", 45); //4
//     facebook_graph.addUser("F", "1988-10-25", 10); //5
//     facebook_graph.addUser("G", "1995-11-01", 35); //6
//     facebook_graph.addUser("H", "1992-09-10", 55); //7
    
    
//     facebook_graph.addFriend(0, 1); //0 -> 1
//     facebook_graph.addFriend(1, 2); //1 -> 2
//     facebook_graph.addFriend(1, 3); //1 -> 3
//     facebook_graph.addFriend(2, 3); //2 -> 3
//     facebook_graph.addFriend(4, 3); //4 -> 3
//     facebook_graph.addFriend(5, 6); //5 -> 6
//     facebook_graph.addFriend(0, 7); //0 -> 7
//     facebook_graph.addFriend(7, 1); //7 -> 1
//     facebook_graph.addFriend(7, 3); //7 -> 3

//     cout << "User with maximum fList: " << facebook_graph.maxFriend() << endl;
    
    
//     string max_user;
//     string min_user;
//     facebook_graph.MaxMinComments(max_user, min_user);
//     cout << "User with maximum comments: " << max_user << endl;
//     cout << "User with minimum comments: " << min_user << endl;
    
    
//     cout << "Users with Current Birth Month: ";
//     facebook_graph.findDOB();

//     return 0;
// }

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <climits>
using namespace std;

struct User {
    string name;
    string date_of_birth;
    int num_comments;
};

string split(const string& strr) {
    size_t pos = strr.find("-");
    if (pos != string::npos && pos + 1 < strr.length()) {
        size_t next_pos = strr.find("-", pos + 1);
        if (next_pos != string::npos) {
            return strr.substr(pos + 1, next_pos - pos - 1);
        }
    }
    return "";
}

void print_vec(vector<string> ret_vec) {
    cout << "{";
    string sCol = "'";
    for (int i = 0; i < ret_vec.size(); i++) {
        cout << sCol;
        cout << ret_vec[i];
        cout << sCol;
        if (i < ret_vec.size() - 1) {
            cout << ", ";
        }
    }
    cout << "}";
    cout << endl;
}

class FBGraph {
public:
    vector<User> users;
    vector<vector<int>> fList;
    
    void addUser(string name, string dob, int comments) {
        User newUser = {name, dob, comments};
        users.push_back(newUser);
        fList.push_back(vector<int>());
    }
    
    void addFriend(int u1_idx, int u2_idx) {
        if (u1_idx >= 0 && u1_idx < users.size() && u2_idx >= 0 && u2_idx < users.size()) {
            fList[u1_idx].push_back(u2_idx);
            fList[u2_idx].push_back(u1_idx);
        } else {
            cout << "Invalid user indices for friendship.\n";
        }
    }
    
    string maxFriend() {
        int max_ctr = 0;
        int max_friend_idx = -1;
        
        for (int i = 0; i < fList.size(); i++) {
            if (fList[i].size() > max_ctr) {
                max_ctr = fList[i].size();
                max_friend_idx = i;
            }
        }
        
        if (max_friend_idx != -1) {
            return users[max_friend_idx].name;
        } else {
            return "None";
        }
    }
    
    void MaxMinComments(string &max_user, string &min_user) {
        int max_comment = -1;
        int min_comment = INT_MAX;
        int max_user_idx = -1;
        int min_user_idx = -1;
        
        for (int i = 0; i < users.size(); i++) {
            if (users[i].num_comments > max_comment) {
                max_comment = users[i].num_comments;
                max_user_idx = i;
            }
            
            if (users[i].num_comments < min_comment) {
                min_comment = users[i].num_comments;
                min_user_idx = i;
            }
        }
        
        if (max_user_idx != -1) {
            max_user = users[max_user_idx].name;
        }
        
        if (min_user_idx != -1) {
            min_user = users[min_user_idx].name;
        }
    }
    
    void findDOB() {
        time_t t = time(0);
        tm *now = localtime(&t);
        int month_number = now->tm_mon + 1;
        string curr_month = to_string(month_number);
        
        vector<string> ret_vec;
        for (int i = 0; i < users.size(); i++) {
            if (split(users[i].date_of_birth) == curr_month) {
                ret_vec.push_back(users[i].name);
            }
        }
        print_vec(ret_vec);
    }
};

int main() {
    FBGraph facebook_graph;
    int numUsers, numFriendships;

    // Get user data
    cout << "Enter number of users: ";
    cin >> numUsers;

    for (int i = 0; i < numUsers; i++) {
        string name, dob;
        int comments;
        
        cout << "Enter details for User " << i + 1 << endl;
        cout << "Name: ";
        cin >> name;
        cout << "Date of Birth (YYYY-MM-DD): ";
        cin >> dob;
        cout << "Number of comments: ";
        cin >> comments;

        facebook_graph.addUser(name, dob, comments);
    }

    // Get friendships
    cout << "Enter number of friendships: ";
    cin >> numFriendships;

    for (int i = 0; i < numFriendships; i++) {
        int user1, user2;
        cout << "Enter friendship (two user indices starting from 0): ";
        cin >> user1 >> user2;

        facebook_graph.addFriend(user1, user2);
    }

    cout << "User with maximum friends: " << facebook_graph.maxFriend() << endl;

    string max_user, min_user;
    facebook_graph.MaxMinComments(max_user, min_user);
    cout << "User with maximum comments: " << max_user << endl;
    cout << "User with minimum comments: " << min_user << endl;

    cout << "Users with birthdays in the current month: ";
    facebook_graph.findDOB();

    return 0;
}
