#include <iostream>

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>

#include "match_client/Match.h"
#include "match_client/match_types.h"

using namespace std;
using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::match_service;

int main()
{
    std::shared_ptr<TTransport> socket(new TSocket("localhost", 9090));
    std::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
    std::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
    MatchClient client(protocol);
    cout << "add_user---" << endl;
    try
    {
        transport->open();

        User user;
        user.id = 13;
        user.name = "I am seu client";
        client.add_user(user, "None");
        cout << "add_user---" << endl;

        transport->close();
    }
    catch (TException &tx)
    {
        cout << "ERROR: " << tx.what() << endl;
    }
}