#include <vector>


class BigDataStorage {
    public:
        void addData(char** data, int count);
        std::vector<char*> m_data; 

    private:

};

class StringHandler {
    public:
        StringHandler(BigDataStorage data);
        void operation1();
        char* operation2();
        void print();

private:
        BigDataStorage m_data;
};
