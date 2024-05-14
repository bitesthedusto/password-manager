// The PasswordManager class
// file name: PasswordManager.cpp
// Kendal Anderson   igt22@txstate.edu
// 17.8 PA#4 Password Manager
// 2/15/24
// CS2308 Spring 2024
// Member function definitions

#include "PasswordManager.h"

// setUsername: takes string user and stores in username member variable
// user: input string for user name
void PasswordManager::setUsername(const string& user) {
   userName = user; //userName is a member var
}

// getUsername: returns value of username member variable
// returns string username
string PasswordManager::getUsername() const {
   return userName;
}

// setEncryptedPassword: takes string from input and stores in proper member
// variable
// pw: string from input for password
void PasswordManager::setEncryptedPassword(const string& pw) {
   password = pw;
}

// getEncryptedPassword: returns value of encrypted password stored in
// member variable
// returns string stored in member variable
string PasswordManager::getEncryptedPassword() const {
   return password;
}

// setNewPassword: takes string, if it meets criteria, it encrypts the string
// and stores it in the password member variable and returns true. Otherwise
// false.
// pw: string for password
// returns true or false based on if string meets criteria
bool PasswordManager::setNewPassword(const string& pw) {
   if (meetsCriteria(pw)) {
      string encryptedPass = encrypt(pw);
      password = encryptedPass;
      return true;
   }
   
   return false;
}

// authenticate: takes string and return true if, once encrypted, it matches
// encrypted string stored in member var.
// pw: string input for password
// returns true or false
bool PasswordManager::authenticate(const string& pw) const {
   string encryptedPw = encrypt(pw);
   if (encryptedPw == password) {
      return true;
   }
   return false;
}

// encrypt: takes string and encrypts it
// pw: string input for password
// returns encrypted form of string
string PasswordManager::encrypt(const string& pw) const {
   string encryptedPass;
   
   for (char ch : pw) {
      char encryptedCh = ((ch - 33) + 43) % 94 + 33;
      encryptedPass.push_back(encryptedCh);
   }
   
   return encryptedPass;
}

// meetCriteria: takes string and checks if it meets criteria
// pw: string for password
// returns true or false
bool PasswordManager::meetsCriteria(const string& pw) {
   if (pw.length() < 10) {
      return false;
   }
   
   int repeatedChars = 0;
   //bool minTwoRepeats = false;
   bool chars[128] = {false};
   
   for (int i = 0; i < pw.length(); ++i) {
      char ch = pw[i];
      
      if (!chars[ch]) {
         chars[ch] = true;
         repeatedChars++;
         continue;
      }
   }
   if (repeatedChars < 2) {
      return false;
   }
   
   string commonPasswords[] = {
            "qwertyuiop", "1234567890", "mypassword",
            "q1w2e3r4t5", "mississippi", "texasstate",
            "texasstate", "abcde12345", "sanantonio",
            "september21"
   };
   for (int i = 0; i < 10; ++i) {
      if (pw == commonPasswords[i]) {
         return false;
      }
   }
   
   return true;
}
