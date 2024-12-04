class Contact {
    private:
        std::string fName;
        std::string lName;
        std::string nName;
        std::string pNumber;
        std::string darkestSecret;
    public:
        std::string getFName() const;
        void setFName(const std::string fName);

        std::string getLName() const;
        void setLName(const std::string lName);

        std::string getNName() const;
        void setNName(const std::string nName);

        std::string getPNumber() const;
        void setPNumber(const std::string pNumber);

        std::string getDarkestSecret() const;
        void setDarkestSecret(const std::string darkestSecret);
};