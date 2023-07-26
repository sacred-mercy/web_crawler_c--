#ifndef SESSION_H
#define SESSION_H

class Session
{
public:
    Session(int sessionID);
    ~Session();

    void createSession();
    void continueOrRestartSession(bool answer);
    bool checkSessionExists();
    void forceRestartSession();
    void continueSession();

private:
    int sessionID;
};

#endif // SESSION_H
