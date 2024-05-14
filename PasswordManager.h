// file name: PasswordManager.h
// Kendal Anderson
// 17.8 PA#4 Password Manager
// 2/15/24
// CS2308 Spring 2024
// Class declaration


#include <string>
using namespace std;

class PasswordManager {
   
private:
   string userName;
   string password;
   string encrypt(const string&) const;
   bool meetsCriteria(const string&);
   
public:
   void setUsername(const string&);
   string getUsername() const;
   void setEncryptedPassword(const string&);
   string getEncryptedPassword() const;
   bool setNewPassword(const string&);
   bool authenticate(const string&) const;
};
