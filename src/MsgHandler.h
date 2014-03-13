#ifndef MSGHANDLER_H
#define MSGHANDLER_H

#include <map>

class I_Command;
class IpmiMessage;

class MsgHandler {
    
private:
    typedef std::map<unsigned char, I_Command*> CommandMap;
    static CommandMap AppCommands_;
    static CommandMap ChassisCommands_;
    static CommandMap SECommands_;
    static CommandMap StorageCommands_;
    static CommandMap FirmCommands_;
    static CommandMap TransportCommands_;
    static CommandMap BridgeCommands_;
    
public:
    static void initCMD();
    static void clearCMD();
    
    static bool isPing(const IpmiMessage& message);
    static void pong(const IpmiMessage& message, IpmiMessage& response);
    static void processRequest(const IpmiMessage& message, IpmiMessage& response);
 };

#endif
