#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include "user.h"
#include "message.h"


using namespace std;

int main()
{
    
    vector<User> Users; // ¬Ó¬Ö¬Ü¬ä¬à¬â ¬á¬à¬Ý¬î¬Ù¬à¬Ó¬Ñ¬ä¬Ö¬Ý¬Ö¬Û
    vector<Message> Message; // ¬Ó¬Ö¬Ü¬ä¬à¬â ¬ã¬à¬à¬Ò¬ë¬Ö¬ß¬Ú¬Û

    /* ¬Ý¬à¬Ô¬Ú¬ß/¬Ú¬Þ¬ñ ¬á¬à¬Ý¬î¬Ù¬à¬Ó¬Ñ¬ä¬Ö¬Ý¬ñ, ¬á¬Ñ¬â¬à¬Ý¬î/¬á¬à¬Õ¬ä¬Ó¬Ö¬â¬Ø¬Õ¬Ö¬ß¬Ú¬Ö, ¬ä¬Ö¬Ü¬ã¬ä ¬ã¬à¬à¬Ò¬ë¬Ö¬ß¬Ú¬ñ,
           ¬Ñ¬Õ¬â¬Ö¬ã¬Ñ¬ä, ¬à¬ä¬á¬â¬Ñ¬Ó¬Ý¬Ö¬ß¬Ú¬Ö ¬ã¬à¬à¬Ò¬ë¬Ö¬ß¬Ú¬Û*/
    string user_login, user_name, user_pssw, pssw_confirm,
        curr_messg, adressee, send_to;

    int num, i, s, n; // ¬á¬Ö¬â¬Ö¬Þ¬Ö¬ß¬ß¬í¬Ö ¬è¬Ú¬Ü¬Ý¬à¬Ó 

    /* boolean ¬Õ¬Ý¬ñ ¬Ñ¬Ó¬ä¬à¬â¬Ú¬Ù¬Ñ¬è¬Ú¬Ú, ¬á¬à¬Ú¬ã¬Ü¬Ñ ¬á¬à ¬Þ¬Ñ¬ã¬ã¬Ú¬Ó¬å ¬á¬à¬Ý¬î¬Ù¬à¬Ó¬Ñ¬ä¬Ö¬Ý¬Ö¬Û/¬ã¬à¬à¬Ò¬ë¬Ö¬ß¬Ú¬Û,
     ¬Ù¬Ñ¬Ó¬Ö¬â¬ê¬Ö¬ß¬Ú¬ñ ¬á¬â¬à¬Ô¬â¬Ñ¬Þ¬Þ¬í*/
    bool access, name_avlble, no_valid_send, prog_end = 1;
    while (prog_end) //program_end = true 
    {
        cout << "Choose an option :" << endl;// ¬Þ¬Ö¬ß¬ð ¬Ó¬ç¬à¬Õ¬Ñ
        cout << "1. Registration" << endl;
        cout << "2. Sign in" << endl;
        cout << "Press a button to exit" << endl << endl;
        cin >> num;
        cin.ignore();
        switch (num) // ¬Ó¬í¬Ò¬à¬â ¬Õ¬Ö¬Û¬ã¬ä¬Ó¬Ú¬Û 
        {
        case 1:
            cout << "Enter Login" << endl;
            getline(cin, user_login);
            if (Users.size() == 0) // ¬á¬Ö¬â¬Ó¬í¬Û ¬á¬à¬Ý¬î¬Ù¬à¬Ó¬Ñ¬ä¬Ö¬Ý¬î
            {
                cout << "Enter your name" << endl;
                getline(cin, user_name);
                cout << "Enter password" << endl;
                getline(cin, user_pssw);
                cout << "Repeat password" << endl;
                getline(cin, pssw_confirm);

                if (user_pssw == pssw_confirm) // ¬ã¬â¬Ñ¬Ó¬ß¬Ö¬ß¬Ú¬Ö ¬á¬Ñ¬â¬à¬Ý¬ñ
                {
                    registr_new_user(Users, user_login, user_name, user_pssw); //¬â¬Ö¬Ô¬Ú¬ã¬ä¬â¬Ñ¬è¬Ú¬ñ ¬á¬à¬Ý¬î¬Ù¬à¬Ó¬Ñ¬ä¬Ö¬Ý¬ñ
                }
                else
                {
                    cout << "No password match" << endl << endl; 
                }
            }
            else //  ¬Ú¬ë¬Ö¬Þ ¬ã¬à¬Ó¬á¬Ñ¬Õ¬Ö¬ß¬Ú¬Ö ¬Ú¬Þ¬Ö¬ß¬Ú
            {
                name_avlble = true;
                for (i = 0; i < Users.size(); ++i) // ¬á¬â¬à¬Ó¬Ö¬â¬ñ¬Ö¬Þ ¬Þ¬Ñ¬ã¬ã¬Ú¬Ó
                {
                    if (user_login == Users[i].getUserLogin()) // 
                    {
                        name_avlble = false; // ¬Õ¬à¬ã¬ä¬å¬á¬ß¬à¬ã¬ä¬î ¬Ú¬Þ¬Ö¬ß¬Ú name_free = false
                        break;
                    }
                }

                if (name_avlble) // ¬Õ¬à¬ã¬ä¬å¬á¬ß¬à¬ã¬ä¬î ¬Ú¬Þ¬Ö¬ß¬Ú
                {
                    cout << "Enter your name" << endl;
                    getline(cin, user_name);
                    cout << "Enter password" << endl;
                    getline(cin, user_pssw);
                    cout << "Repeat password" << endl;
                    getline(cin, pssw_confirm);
                    if (user_pssw == pssw_confirm) // ¬ã¬â¬Ñ¬Ó¬ß¬Ö¬ß¬Ú¬Ö ¬á¬Ñ¬â¬à¬Ý¬ñ
                    {
                        registr_new_user(Users, user_login, user_name, user_pssw); //¬â¬Ö¬Ô¬Ú¬ã¬ä¬â¬Ñ¬è¬Ú¬ñ ¬á¬à¬Ý¬î¬Ù¬à¬Ó¬Ñ¬ä¬Ö¬Ý¬ñ
                        break;
                    }
                    else
                    {
                        cout << "No password match" << endl << endl;
                    }
                }
                else
                {
                    cout << "Username is already exist. Make another one" << endl << endl;
                }
            }
            break;
        case 2:
            if (Users.size() < 2) // ¬Ü¬à¬Ý¬Ú¬é¬Ö¬ã¬ä¬Ó¬à ¬å¬é¬Ñ¬ã¬ä¬ß¬Ú¬Ü¬à¬Ó ¬Õ¬Ý¬ñ ¬é¬Ñ¬ä¬Ñ >2
            {
                cout << "NEED TWO PARTICIPANTS TO BE REGISTERED" << endl << endl;
                break;
            }
            /*  ¬Ñ¬Ó¬ä¬à¬â¬Ú¬Ù¬Ñ¬è¬Ú¬ñ*/
            cout << "Enter Login:" << endl;
            getline(cin, user_login);
            cout << "Enter password:" << endl;
            getline(cin, user_pssw);

            access = false;
            for (i = 0; i < Users.size(); ++i) // ¬á¬à¬Ú¬ã¬Ü ¬Ó ¬Ó¬Ö¬Ü¬ä¬à¬â¬Ö
            {
                if (user_login == Users[i].getUserLogin() && user_pssw == Users[i].getUserPassword()) // ¬ã¬â¬Ñ¬Ó¬ß¬Ö¬ß¬Ú¬Ö ¬Õ¬Ñ¬ß¬ß¬í¬ç
                {
                    cout << "WELCOME   " << Users[i].getUserName() << endl << endl;
                    access = true; //¬Ö¬ã¬Ý¬Ú ¬Õ¬Ñ¬ß¬ß¬í¬Ö ¬ß¬Ö ¬ã¬à¬Ó¬á¬Ñ¬Õ¬Ñ¬ð¬ä: access = true
                    break;
                }
            }
            if (!access)
            {
                cout << "Invalid login or password" << endl << endl;
            }
            while (access) // ¬Ó ¬ã¬Ý¬å¬é¬Ñ¬Ö ¬å¬ã¬á¬Ö¬ç¬Ñ ¬Þ¬Ö¬ß¬ð ¬ã¬à¬à¬Ò¬ë¬Ö¬ß¬Ú¬Û
            {
                cout << "Choose an option:" << endl;
                cout << "1. Send to All users" << endl;
                cout << "2. Send a private message" << endl;
                cout << "3. Read a message" << endl;
                cout << "For Menu Up press a number/ To Exit the program press a letter" << endl << endl;
                cin >> num;
                cin.ignore();
                switch (num)
                {
                case 1: // ¬ã¬à¬à¬Ò¬ë¬Ö¬ß¬Ú¬Ö ¬Õ¬Ý¬ñ ¬Ó¬ã¬Ö¬ç
                    cout << "Write a message" << endl;
                    getline(cin, curr_messg);
                    curr_messg = "To All users from  " + user_login + ": " + curr_messg;
                    for (i = 0; i < Users.size(); ++i) // ¬Ú¬Õ¬Ö¬Þ ¬á¬à ¬Ó¬Ö¬Ü¬ä¬à¬â¬å
                    {
                        if (user_login != Users[i].getUserLogin())
                            // ¬à¬ä¬á¬â¬Ñ¬Ó¬Ü¬Ñ ¬ã¬à¬à¬Ò¬ë¬Ö¬ß¬Ú¬ñ 
                            sent_message(Message, user_login, Users[i].getUserLogin(), curr_messg); // ¬ã¬à¬à¬Ò¬ë¬Ö¬ß¬Ú¬Ö, ¬ä¬Ö¬Ü¬ã¬ä, ¬Ú¬Þ¬ñ ¬á¬à¬Ý¬î¬Ù¬à¬Ó¬Ñ¬ä¬Ö¬Ý¬ñ, ¬Ñ¬Õ¬â¬Ö¬ã¬Ñ¬ä
                    }

                    cout << "Message sent to All users" << endl << endl;
                    break;

                case 2:
                    /* ¬à¬ä¬á¬â¬Ñ¬Ó¬Ü¬Ñ ¬ã¬à¬à¬Ò¬ë¬Ö¬ß¬Ú¬ñ ¬Ü¬à¬ß¬Ü¬â¬Ö¬ä¬ß¬à¬Þ¬å ¬á¬à¬Ý¬î¬Ù¬à¬Ó¬Ñ¬ä¬Ö¬Ý¬ð*/
                    no_valid_send = true; //¬Ú¬Þ¬ñ ¬Ñ¬Õ¬â¬Ö¬ã¬Ñ¬ä¬Ñ
                    cout << "Users registered:" << endl; // 
                    for (i = 0; i < Users.size(); ++i) // ¬ã¬á¬Ú¬ã¬à¬Ü ¬á¬à¬Ý¬î¬Ù¬à¬Ó¬Ñ¬ä¬Ö¬Ý¬Ö¬Û
                    {
                        cout << Users[i].getUserLogin() << "; ";
                    }
                    while (no_valid_send) // ¬á¬â¬à¬Ó¬Ö¬â¬Ü¬Ñ ¬Ú¬Þ¬Ö¬ß¬Ú ¬Ñ¬Õ¬â¬Ö¬ã¬Ñ¬ä¬Ñ
                    {
                        cout << endl << "send to ?" << endl;
                        getline(cin, adressee);

                        for (i = 0; i < Users.size(); ++i) // ¬Ú¬ë¬Ö¬Þ ¬Ú¬Þ¬ñ ¬ã¬â¬Ö¬Õ¬Ú (¬Ó¬à¬ê¬Ö¬Õ¬ê¬Ú¬ç) ¬á¬à¬Ý¬î¬Ù¬à¬Ó¬Ñ¬ä¬Ö¬Ý¬Ö¬Û
                        {
                            if (adressee == Users[i].getUserLogin()) 
                            {
                                cout << "Write a message" << endl;// ¬á¬Ú¬ê¬Ö¬Þ ¬ã¬à¬à¬Ò¬ë¬Ö¬ß¬Ú¬Ö
                                getline(cin, curr_messg);
                                curr_messg = "Message from " + user_login + ": " + curr_messg;
                                sent_message(Message, user_login, adressee, curr_messg); // ¬à¬ä¬á¬â¬Ñ¬Ó¬Ü¬Ñ ¬ã¬à¬à¬Ò¬ë¬Ö¬ß¬Ú¬Û
                                cout << "Message sent" << endl << endl;
                                no_valid_send = 0; // ¬à¬ä¬á¬â¬Ñ¬Ó¬Ý¬Ö¬ß¬à
                            }
                        }
                        if (no_valid_send) // ¬Ñ¬Õ¬â¬Ö¬ã¬Ñ¬ä¬Ñ ¬ß¬Ö¬ä ¬Ó ¬ã¬á¬Ú¬ã¬Ü¬Ö
                        {
                            cout << "NOT REGISTERED " << adressee << " USERNAME" << endl << endl;
                        }
                    }
                    break;

                case 3: // ¬é¬ä¬Ö¬ß¬Ú¬Ö ¬ã¬à¬à¬Ò¬ë¬Ö¬ß¬Ú¬ñ
                    s = Message.size();
                    
                        for (i = 0; i < s; ++i)
                        {
                            if (user_login == Message[i].getRecipient()) // ¬ß¬Ñ¬ç¬à¬Õ¬Ú¬Þ ¬Ú¬Þ¬ñ ¬Ó Message  
                            {
                                cout << Message[i].getMessage() << endl; // ¬Ó¬í¬Ó¬à¬Õ¬Ú¬Þ ¬ã¬à¬à¬Ò¬ë¬Ö¬ß¬Ú¬Ö
                                cout << "For confidential Answer to'" << Message[i].getSender() << "' press 'c', for public - press 'p', others - any button" << endl; // ¬Ó¬Ú¬Õ ¬ã¬à¬à¬Ò¬ë¬Ö¬ß¬Ú¬ñ
                                cin >> send_to; // 
                                if (send_to == "c") // "¬ã" - ¬Ý¬Ú¬é¬ß¬à¬Ö ¬ã¬à¬à¬Ò¬ë¬Ö¬ß¬Ú¬Ö
                                {
                                    cin.ignore();
                                    cout << "Write a message:" << endl;
                                    getline(cin, curr_messg);
                                    curr_messg = "Message from " + user_login + ": " + curr_messg;
                                    sent_message(Message, user_login, Message[i].getSender(), curr_messg); // ¬à¬ä¬á¬â¬Ñ¬Ó¬Ü¬Ñ ¬ã¬à¬Ò¬ë¬Ö¬ß¬Ú¬Û
                                    cout << "Message sent" << endl << endl;
                                }
                                if (send_to == "p") // ¬Ö¬ã¬Ý¬Ú "p" - ¬ä¬à ¬à¬ä¬Ó¬Ö¬é¬Ñ¬Ö¬Þ ¬Ó¬ã¬Ö¬Þ
                                {
                                    cin.ignore();
                                    cout << "Write a message:" << endl;
                                    getline(cin, curr_messg);
                                    curr_messg = "Public message from " + user_login + ": " + curr_messg;

                                    for (n = 0; n < Users.size(); ++n) //¬ã¬à¬à¬Ò¬ë¬Ö¬ß¬Ú¬Ö ¬Ó¬ã¬Ö¬Þ ¬å¬é¬Ñ¬ã¬ä¬ß¬Ú¬Ü¬Ñ¬Þ
                                    {
                                        if (user_login != Users[n].getUserLogin())
                                        {
                                            sent_message(Message, user_login, Users[n].getUserLogin(), curr_messg); //
                                        }
                                    }
                                    cout << "Message sent to All users" << endl << endl;
                                }
                                Message.erase(Message.begin() + i); // ¬å¬Õ¬Ñ¬Ý¬ñ¬Ö¬Þ ¬á¬â¬à¬é¬Ú¬ä¬Ñ¬ß¬ß¬à¬Ö
                                --s; // ¬å¬Þ¬Ö¬ß¬î¬ê¬Ñ¬Ö¬Þ ¬Ü¬à¬Ý-¬Ó¬à ¬á¬â¬à¬ç¬à¬Õ¬à¬Ó
                                --i; // 
                            }
                        }
                    
                    cout << "No Entered message " << endl << endl;
                    break;

                default:
                    if ((num > 3) || (num < 1)) // ¬Þ¬Ö¬ß¬ð ¬Ó¬Ó¬Ö¬â¬ç
                    {
                        access = false;
                    }
                    break;
                }

            }
            break;
         default:
             if ((num > 2) || (num < 1)) // ¬å¬ã¬Ý¬à¬Ó¬Ú¬Ö ¬Ó¬í¬ç¬à¬Õ¬Ñ ¬Ú¬Ù ¬á¬â¬à¬Ô¬â¬Ñ¬Þ¬Þ¬í
             {
                 prog_end = 0;
             }
             break;

        }



    }
    return 0;
}