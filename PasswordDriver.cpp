//  PasswordDriver.cpp
//  Kendal Anderson   igt22@txstate.edu
//  17.8 PA#4 Password Manager
//  2/15/24
//  CS2308 Spring 2024
//  Driver file

#include <iostream>
#include <fstream>
using namespace std;
#include "PasswordManager.h"

int main() {
   
   PasswordManager passwords[4];
   
  
   string file;
   cout << "Please enter the name of the input file:" << endl;
   cin >> file;
   
   ifstream in;
   in.open(file);
   
   if (!in.is_open()) {
      return -1;
   }
   
   const int USERS = 4;
   for (int i = 0; i < USERS; ++i) {
      string netID;
      string encryptedPw;
      
      in >> netID;
      in >> encryptedPw;
      
      passwords[i].setUsername(netID);
      passwords[i].setEncryptedPassword(encryptedPw);
      
   }
   
   
   in.close();
   
   string netID;
   string oldPw;
   string newPw;
   
   cout << "Please enter your netID:";
   cin >> netID;
   cout << endl;
   
   cout << "Please enter your old password:";
   cin >> oldPw;
   cout << endl;
   
   cout << "Please enter your new password:";
   cin >> newPw;
   cout << endl << endl;
   
   
   
   bool netIdExists = false;
   bool matchingPw = false;
   bool validPw = false;
   
   for (int i = 0; i < USERS; ++i) {
      if (passwords[i].getUsername() == netID) {
         netIdExists = true;
         if (passwords[i].authenticate(oldPw)) {
            matchingPw = true;
            if (passwords[i].setNewPassword(newPw)) {
               validPw = true;
               break;
            }
         }
      }
   }
   
   
   if (!netIdExists) {
      cout << "NetID is invalid, password not changed." << endl;
      cout << endl;
      for (int i = 0; i < USERS; ++i) {
         
         cout << passwords[i].getUsername() << "  "
         << passwords[i].getEncryptedPassword() << endl;
      }
      return 0;
   }
   else if (!matchingPw) {
      cout << "Old password is incorrect." << endl;
      cout << endl;
      for (int i = 0; i < USERS; ++i) {
         
         cout << passwords[i].getUsername() << "  "
         << passwords[i].getEncryptedPassword() << endl;
      }
      return 0;
   }
   else if (!validPw) {
      cout << "New Password does not meet criteria." << endl;
      cout << endl;
      for (int i = 0; i < USERS; ++i) {
         
         cout << passwords[i].getUsername() << "  "
         << passwords[i].getEncryptedPassword() << endl;
      }
      return 0;

   }
   
   cout << "Password has been changed for netID: " << netID << endl;
   cout << endl;
   for (int i = 0; i < USERS; ++i) {
      if (netID == passwords[i].getUsername()) {
         passwords[i].setNewPassword(newPw);
      }
      cout << passwords[i].getUsername() << "  "
      << passwords[i].getEncryptedPassword() << endl;
   }
   
   return 0;
}
