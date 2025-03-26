#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include "user.h"
#include "message.h"


using namespace std;

int main()
{
    
    vector<User> Users; // �Ӭ֬ܬ��� ���ݬ�٬�ӬѬ�֬ݬ֬�
    vector<Message> Message; // �Ӭ֬ܬ��� ����Ҭ�֬߬ڬ�

    /* �ݬ�Ԭڬ�/�ڬެ� ���ݬ�٬�ӬѬ�֬ݬ�, ��Ѭ��ݬ�/���լ�Ӭ֬�جլ֬߬ڬ�, ��֬ܬ�� ����Ҭ�֬߬ڬ�,
           �Ѭլ�֬�Ѭ�, �����ѬӬݬ֬߬ڬ� ����Ҭ�֬߬ڬ�*/
    string user_login, user_name, user_pssw, pssw_confirm,
        curr_messg, adressee, send_to;

    int num, i, s, n; // ��֬�֬ެ֬߬߬�� ��ڬܬݬ�� 

    /* boolean �լݬ� �ѬӬ���ڬ٬Ѭ�ڬ�, ���ڬ�ܬ� ��� �ެѬ��ڬӬ� ���ݬ�٬�ӬѬ�֬ݬ֬�/����Ҭ�֬߬ڬ�,
     �٬ѬӬ֬��֬߬ڬ� ����Ԭ�Ѭެެ�*/
    bool access, name_avlble, no_valid_send, prog_end = 1;
    while (prog_end) //program_end = true 
    {
        cout << "Choose an option :" << endl;// �ެ֬߬� �Ӭ��լ�
        cout << "1. Registration" << endl;
        cout << "2. Sign in" << endl;
        cout << "Press a button to exit" << endl << endl;
        cin >> num;
        cin.ignore();
        switch (num) // �Ӭ�Ҭ�� �լ֬۬��Ӭڬ� 
        {
        case 1:
            cout << "Enter Login" << endl;
            getline(cin, user_login);
            if (Users.size() == 0) // ��֬�Ӭ�� ���ݬ�٬�ӬѬ�֬ݬ�
            {
                cout << "Enter your name" << endl;
                getline(cin, user_name);
                cout << "Enter password" << endl;
                getline(cin, user_pssw);
                cout << "Repeat password" << endl;
                getline(cin, pssw_confirm);

                if (user_pssw == pssw_confirm) // ���ѬӬ߬֬߬ڬ� ��Ѭ��ݬ�
                {
                    registr_new_user(Users, user_login, user_name, user_pssw); //��֬Ԭڬ���Ѭ�ڬ� ���ݬ�٬�ӬѬ�֬ݬ�
                }
                else
                {
                    cout << "No password match" << endl << endl; 
                }
            }
            else //  �ڬ�֬� ���Ӭ�Ѭլ֬߬ڬ� �ڬެ֬߬�
            {
                name_avlble = true;
                for (i = 0; i < Users.size(); ++i) // ����Ӭ֬��֬� �ެѬ��ڬ�
                {
                    if (user_login == Users[i].getUserLogin()) // 
                    {
                        name_avlble = false; // �լ�����߬���� �ڬެ֬߬� name_free = false
                        break;
                    }
                }

                if (name_avlble) // �լ�����߬���� �ڬެ֬߬�
                {
                    cout << "Enter your name" << endl;
                    getline(cin, user_name);
                    cout << "Enter password" << endl;
                    getline(cin, user_pssw);
                    cout << "Repeat password" << endl;
                    getline(cin, pssw_confirm);
                    if (user_pssw == pssw_confirm) // ���ѬӬ߬֬߬ڬ� ��Ѭ��ݬ�
                    {
                        registr_new_user(Users, user_login, user_name, user_pssw); //��֬Ԭڬ���Ѭ�ڬ� ���ݬ�٬�ӬѬ�֬ݬ�
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
            if (Users.size() < 2) // �ܬ�ݬڬ�֬��Ӭ� ���Ѭ��߬ڬܬ�� �լݬ� ��Ѭ�� >2
            {
                cout << "NEED TWO PARTICIPANTS TO BE REGISTERED" << endl << endl;
                break;
            }
            /*  �ѬӬ���ڬ٬Ѭ�ڬ�*/
            cout << "Enter Login:" << endl;
            getline(cin, user_login);
            cout << "Enter password:" << endl;
            getline(cin, user_pssw);

            access = false;
            for (i = 0; i < Users.size(); ++i) // ���ڬ�� �� �Ӭ֬ܬ����
            {
                if (user_login == Users[i].getUserLogin() && user_pssw == Users[i].getUserPassword()) // ���ѬӬ߬֬߬ڬ� �լѬ߬߬��
                {
                    cout << "WELCOME   " << Users[i].getUserName() << endl << endl;
                    access = true; //�֬�ݬ� �լѬ߬߬�� �߬� ���Ӭ�ѬլѬ��: access = true
                    break;
                }
            }
            if (!access)
            {
                cout << "Invalid login or password" << endl << endl;
            }
            while (access) // �� ��ݬ��Ѭ� ����֬�� �ެ֬߬� ����Ҭ�֬߬ڬ�
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
                case 1: // ����Ҭ�֬߬ڬ� �լݬ� �Ӭ�֬�
                    cout << "Write a message" << endl;
                    getline(cin, curr_messg);
                    curr_messg = "To All users from  " + user_login + ": " + curr_messg;
                    for (i = 0; i < Users.size(); ++i) // �ڬլ֬� ��� �Ӭ֬ܬ����
                    {
                        if (user_login != Users[i].getUserLogin())
                            // �����ѬӬܬ� ����Ҭ�֬߬ڬ� 
                            sent_message(Message, user_login, Users[i].getUserLogin(), curr_messg); // ����Ҭ�֬߬ڬ�, ��֬ܬ��, �ڬެ� ���ݬ�٬�ӬѬ�֬ݬ�, �Ѭլ�֬�Ѭ�
                    }

                    cout << "Message sent to All users" << endl << endl;
                    break;

                case 2:
                    /* �����ѬӬܬ� ����Ҭ�֬߬ڬ� �ܬ�߬ܬ�֬�߬�ެ� ���ݬ�٬�ӬѬ�֬ݬ�*/
                    no_valid_send = true; //�ڬެ� �Ѭլ�֬�Ѭ��
                    cout << "Users registered:" << endl; // 
                    for (i = 0; i < Users.size(); ++i) // ���ڬ��� ���ݬ�٬�ӬѬ�֬ݬ֬�
                    {
                        cout << Users[i].getUserLogin() << "; ";
                    }
                    while (no_valid_send) // ����Ӭ֬�ܬ� �ڬެ֬߬� �Ѭլ�֬�Ѭ��
                    {
                        cout << endl << "send to ?" << endl;
                        getline(cin, adressee);

                        for (i = 0; i < Users.size(); ++i) // �ڬ�֬� �ڬެ� ���֬լ� (�Ӭ��֬լ�ڬ�) ���ݬ�٬�ӬѬ�֬ݬ֬�
                        {
                            if (adressee == Users[i].getUserLogin()) 
                            {
                                cout << "Write a message" << endl;// ��ڬ�֬� ����Ҭ�֬߬ڬ�
                                getline(cin, curr_messg);
                                curr_messg = "Message from " + user_login + ": " + curr_messg;
                                sent_message(Message, user_login, adressee, curr_messg); // �����ѬӬܬ� ����Ҭ�֬߬ڬ�
                                cout << "Message sent" << endl << endl;
                                no_valid_send = 0; // �����ѬӬݬ֬߬�
                            }
                        }
                        if (no_valid_send) // �Ѭլ�֬�Ѭ�� �߬֬� �� ���ڬ�ܬ�
                        {
                            cout << "NOT REGISTERED " << adressee << " USERNAME" << endl << endl;
                        }
                    }
                    break;

                case 3: // ���֬߬ڬ� ����Ҭ�֬߬ڬ�
                    s = Message.size();
                    
                        for (i = 0; i < s; ++i)
                        {
                            if (user_login == Message[i].getRecipient()) // �߬Ѭ��լڬ� �ڬެ� �� Message  
                            {
                                cout << Message[i].getMessage() << endl; // �Ӭ�Ӭ�լڬ� ����Ҭ�֬߬ڬ�
                                cout << "For confidential Answer to'" << Message[i].getSender() << "' press 'c', for public - press 'p', others - any button" << endl; // �Ӭڬ� ����Ҭ�֬߬ڬ�
                                cin >> send_to; // 
                                if (send_to == "c") // "��" - �ݬڬ�߬�� ����Ҭ�֬߬ڬ�
                                {
                                    cin.ignore();
                                    cout << "Write a message:" << endl;
                                    getline(cin, curr_messg);
                                    curr_messg = "Message from " + user_login + ": " + curr_messg;
                                    sent_message(Message, user_login, Message[i].getSender(), curr_messg); // �����ѬӬܬ� ���Ҭ�֬߬ڬ�
                                    cout << "Message sent" << endl << endl;
                                }
                                if (send_to == "p") // �֬�ݬ� "p" - ��� ���Ӭ֬�Ѭ֬� �Ӭ�֬�
                                {
                                    cin.ignore();
                                    cout << "Write a message:" << endl;
                                    getline(cin, curr_messg);
                                    curr_messg = "Public message from " + user_login + ": " + curr_messg;

                                    for (n = 0; n < Users.size(); ++n) //����Ҭ�֬߬ڬ� �Ӭ�֬� ���Ѭ��߬ڬܬѬ�
                                    {
                                        if (user_login != Users[n].getUserLogin())
                                        {
                                            sent_message(Message, user_login, Users[n].getUserLogin(), curr_messg); //
                                        }
                                    }
                                    cout << "Message sent to All users" << endl << endl;
                                }
                                Message.erase(Message.begin() + i); // ��լѬݬ�֬� �����ڬ�Ѭ߬߬��
                                --s; // ��ެ֬߬��Ѭ֬� �ܬ��-�Ӭ� ������լ��
                                --i; // 
                            }
                        }
                    
                    cout << "No Entered message " << endl << endl;
                    break;

                default:
                    if ((num > 3) || (num < 1)) // �ެ֬߬� �ӬӬ֬��
                    {
                        access = false;
                    }
                    break;
                }

            }
            break;
         default:
             if ((num > 2) || (num < 1)) // ���ݬ�Ӭڬ� �Ӭ���լ� �ڬ� ����Ԭ�Ѭެެ�
             {
                 prog_end = 0;
             }
             break;

        }



    }
    return 0;
}