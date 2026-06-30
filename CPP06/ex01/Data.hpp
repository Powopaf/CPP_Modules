#ifndef DATA_HPP
#define DATA_HPP

class Data {
    private:
        int i;
        char c;
    public:
        Data();
        Data(int i, char c);
        Data(const Data& copy);
        Data& operator=(const Data& other);
        ~Data() {}
        int getI() const;
        char getC() const;
};

#endif