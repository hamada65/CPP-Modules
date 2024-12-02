class PhoneBook {
    private:
        Contact Contacts[8];
        int ADD();
        int SEARCH();
        int EXIT();
    public:
        int contactNB;
        int contactIndex;
        PhoneBook();
        int ExecuteCommand(std::string command);
};
