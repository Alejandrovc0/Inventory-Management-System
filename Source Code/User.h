#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

using namespace std;

class User
{
    private:
        string name;
        string username;
        string password;
        string encryptedPasword;
        int verificationCode;

    public:
        User();
        User(const string &name, const string &username, const string &password, int verificationCode);

        string getName() const;
        string getUsername() const;
        string getPassword() const;
        int getVerification() const;

        void setName(const string &name);
        void setUsername(const string &username);
        void setPassword(const string &password);
        void setVerification(int verificationCode);
};


#endif