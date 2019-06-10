#include <iostream>
#include <unistd.h>
#include "Client.h"

using namespace std;
using namespace imsdk;

Client *clientApi = NULL;

string appid = "gtom7mskaton8p3x";

// 15618516930
string openid = "774477b4f9c5217ff7997e4149aede2f";
string access_token = "6ad9666e5201f61297e980625b36bcddc3df413e43c54ce7e4df9fbd6ce6775b";

// 17317534316
//string openid = "774477b4f9c5217ff7997e4149aede2f";
//string access_token = "93ea1e18d2e9670bb06fa7ff6dadb1ed2d65cc00973b16f265942ad9517ce7a8";



class ClientDeletgate : public ClientDelegate
{
public:
    void onGetServer(std::string address, int port)
    {
        cout << "-------------connect-------------" << endl;
        clientApi->connect("10.1.11.34", 3003);
    }

    void onConnect(bool bSuccess)
    {
        if(bSuccess)
        {
            cout << "onConnect: " << bSuccess << endl;
            clientApi->authenticate(openid, access_token, appid);
        }
    }

    void onStatus(Status status)
    {
        cout << "status: " << status << endl;
    }

    void onAuthenticate(bool authorized, User user, std::string message, int code)
    {
        cout << "user id: " << user.uid << endl;
        cout << "onAuthenticate: " << authorized << endl << endl;

        if(authorized)
        {
            cout << "-------------updateContacts-------------" << endl;
            clientApi->updateContacts(0);
        }
    }

    void onContacts(std::vector<User> users, std::vector<std::string> deletedUserIds, long timestamp)
    {
        cout << "contacts count: " << users.size() << endl;

        //打开消息通道
        cout << "-------------openReceivedMessage-------------" << endl;
        clientApi->openReceivedMessage(true);



        //查找好友
//        clientApi->searchFriend("15618516930");

        if(users.size() > 0)
        {
            cout << "chatid: " << users[0].chatId << endl;

            cout << "-------------sendTextMessage-------------" << endl;

            imsdk::Message msg;
            msg.message = "hello";
            msg.chatId = users[0].chatId;
            clientApi->sendTextMessage(msg);

//            clientApi->deleteFriend(users[0].uid);
        }

    }

    void onMessage(Message message, bool bSuccess)
    {
        cout << "-------------onMessage-------------" << endl;
        cout << "message_id: " << message.messageId << endl;
    }

    void onUnrecievedMessage(std::vector<Message> unreceivedMessages, int32_t total)
    {
        cout << "-------------onMessage-------------" << endl;
        cout << "total: " << total << endl;
    }


    void onSearchFriend(std::vector<User> users)
    {
        cout << "-------------onSearchUser-------------" << endl;
        cout << "users: " << users.size() << endl;

        if(users.size() > 0)
        {
            clientApi->applyFriend(users[0].uid, "hello apply friend");
        }
    }

    void onApplyFriend(std::string userId, bool bSuccess)
    {
        cout << "-------------onApplyFriend-------------" << endl;
        cout << "userId: " << userId << endl;
        cout << "bSuccess: " << bSuccess << endl;
    }

    void onApplyFriendNotification(User user, std::string message)
    {
        cout << "-------------onApplyFriendNotification-------------" << endl;
        cout << "uid: " << user.uid << endl;
        cout << "name: " << user.name << endl;
        cout << "msg: " << message << endl;

        clientApi->agreeFriend(user.uid);
    }

    void onAgreeFriend(std::string chatId, std::string message)
    {
        cout << "-------------onAgreeFriend-------------" << endl;
        cout << "chatId: " << chatId << endl;
        cout << "message: " << message << endl;
    }

    void onDeleteFriend(std::string uid, bool bSuccess, std::string message)
    {
        cout << "-------------onDeleteFriend-------------" << endl;
        cout << "uid: " << uid << endl;
        cout << "bSuccess: " << bSuccess << endl;
        cout << "message: " << message << endl;
    }

    void onMessageFailed(Message message)
    {

    }
};

int main()
{
    ClientDeletgate deletgate;
    clientApi = ClientCreate(&deletgate);

    std::string address;
    int port = 0;
    clientApi->getServer("");


    while (1)
    {
        usleep(1000);
    }

    PCClientApi_Destroy(clientApi);
    cout << "bye !!!" << endl;

    return 0;
}